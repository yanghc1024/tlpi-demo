//
// Created by yanghuichen on 2020-10-04.
//

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include "../lib/tlpi_hdr.h"

/**
 * Unix系统维护了三个结构
 * 1. 每个进程独有的file descriptors table
 *      a) a set of flags (close-on-exec)
 *      b) a reference to the open file description
 * 2. system-wide table of open file descriptions (open file handlers)
 *      a) current file offset
 *      b) status flags
 *      c) the file access mode
 *      d) settings
 *      e) a reference to the related i-node object for the file
 * 3. file system i-node table
 *      a) file type (regular file, FIFO, socket)
 *      b) permission
 *      c) a pointer to a list of locks held on the file
 *      d) various properties
 */

void myCopy(const char *srcFile, const char *dstFile) {
    if (srcFile == NULL || dstFile == NULL)
        usageErr("copy src-file dstFile");
    char buf[BUFSIZ];

    // fd is the lowest-numbered unused file descriptor for the process
    // file descriptors, file description(file handler)与文件是一个多对一的关系
    // open函数会创建一个新的file description
    int srcFd = open(srcFile, O_RDONLY);
    if (srcFd == -1)
        errExit("open file %s", srcFile);

    // O_RDONLY | O_WRONLY: this combination is a logical error
    int openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    int dstFd = open(dstFile, openFlags, filePerms);
    if (dstFd == -1)
        errExit("open file %s", dstFile);

    int numRead = 0;
    // read返回的是读取到的字节数，为0时表示EOF，发生错误时为-1
    // BUFSIZ限制了最多可以读到的字节数
    // buf必须是预先分配好的内存
    while ((numRead = read(srcFd, buf, BUFSIZ)) > 0)
        if (write(dstFd, buf, numRead) != numRead)
            fatal("cannot write the whole buffer");
    if (numRead == -1)
        errExit("read");

    if (close(srcFd) == -1)
        errExit("close input");
    if (close(dstFd) == -1)
        errExit("close output");
}

int bitwiseOr(int n, ...) {
    va_list ap;
    va_start(ap, n);
    unsigned int result = 0;
    for (int i = 0; i < n; ++i) {
        result |= (unsigned)va_arg(ap, int);
    }
    return (int)result;
}

int myOpen(const char *pathname, int flag, ...) {
    va_list ap;
    va_start(ap, flag);
    int mode = va_arg(ap, int);
    int fd = open(pathname, flag, mode);
    va_end(ap);

    if (fd == -1) {
        errExit("open file %s", pathname);
    }

    return fd;
}

int myRead(int fd, void *buffer, int size) {
    if (size <= 0) {
        errExit("buffer size must greater than zero, found %d", size);
    }
    int numRead = read(fd, buffer, size);
    if (numRead == -1) {
        errExit("error when reading from file descriptor %d", fd);
    }
    return numRead;
}

int myPRead(int fd, void *buffer, size_t size, off_t offset) {
    if (size <= 0) {
        errExit("buffer size must greater than zero, found %d", size);
    }

    int numRead = pread(fd, buffer, size, offset);
    if (numRead == -1) {
        errExit("error when reading from file descriptor %d", fd);
    }
    return numRead;
}

int myWrite(int fd, const void *buffer, int size) {
    if (size <= 0) {
        errExit("the write size must greater than zero, found %d", size);
    }
    int numWrite = write(fd, buffer, size);
    if (numWrite != size) {
        errExit("want %d but write %d", size, numWrite);
    }
    return numWrite;
}

void myClose(int fd) {
    if (close(fd) == -1) {
        errExit("error when closing file descriptor %d", fd);
    }
}

/**
 * 从terminal读数据的时候，只会读到换行符，所以调用printf等需要null字符的函数需要手动设置
 */
void readFromTerminal(char *buffer, int size) {
    if (size <= 1) {
        errExit("buffer size must greater than 1, found %d", size);
    }

    int numRead = read(STDIN_FILENO, buffer, size - 1);
    if (numRead == -1) {
        errExit("error when reading from terminal");
    }
    buffer[numRead] = '\0';
}

void seekExample(int fd, const char *buffer, int size) {
    for (int i = size-1; 0 <= i; --i) {
        myWrite(fd, buffer+i, 1);
        lseek(fd, 0, SEEK_END);
    }
}

int getFlags(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1)
        errExit("fcntl");
    return flags;
}

/*
 * dup, dup2, dup3和fcntl都能够达到复制文件描述符的目的，但是灵活性不同
 */
void dupExample() {
    close(STDIN_FILENO);
    dup(STDOUT_FILENO); // Now 0 is referring to the same file description of 1

    // Before duplicate the STDOUT_FILENO descriptor, dup2 would close 3 first
    dup2(STDOUT_FILENO, 3);

    // fcntl uses the lowest number started from 4 as the new file descriptor
    close(4);
    fcntl(STDOUT_FILENO, F_DUPFD, 4);
}

typedef struct {
    double x, y;
} MyStruct;

void writevExample(const char *pathname) {
    int fd = myOpen(pathname, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    struct iovec iov[3];
    MyStruct s = { 2.0, 2.0 };
    int x = 23;
#define MAXN 128
    char string[MAXN];
    memset(string, 'c', MAXN);

    int total = 0;

    iov[0].iov_base = &s;
    iov[0].iov_len = sizeof(s);
    total += iov[0].iov_len;

    iov[1].iov_base = &x;
    iov[1].iov_len = sizeof(x);
    total += iov[1].iov_len;

    iov[2].iov_base = string;
    iov[2].iov_len = MAXN;
    total += iov[2].iov_len;

    int totalWritten = writev(fd, iov, 3);
    if (totalWritten == -1) {
        errExit("writev");
    }
    if (totalWritten < total) {
        errMsg("partially write: %s", pathname);
    }

    printf("total = %d, totalWritten = %d", total, totalWritten);

    myClose(fd);
}

void readvExample(const char *pathname) {
    int fd = myOpen(pathname, O_RDONLY);
    struct iovec iov[3];
    MyStruct s;
    int x;
#define MAXN 128
    char string[MAXN];

    int total = 0;

    iov[0].iov_base = &s;
    iov[0].iov_len = sizeof(s);
    total += iov[0].iov_len;

    iov[1].iov_base = &x;
    iov[1].iov_len = sizeof(x);
    total += iov[1].iov_len;

    iov[2].iov_base = string;
    iov[2].iov_len = MAXN;
    total += iov[2].iov_len;

    int totalRead = readv(fd, iov, 3);

    if (totalRead == -1) {
        errExit("readv");
    }
    if (totalRead < total) {
        errMsg("partially read: %s", pathname);
    }

    printf("%lf %lf %d\n%s", s.x, s.y, x, string);

    myClose(fd);
}
