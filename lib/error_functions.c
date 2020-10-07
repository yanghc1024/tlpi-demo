//
// Created by yanghuichen on 2020-08-09.
//

/**
 * 对于错误处理函数一般需要处理：
 * 1. 刷新标准输出
 * 2. 错误信息的输出
 * 3. 刷新标准输出
 * 4. 退出（是否刷新缓冲区、是否调用用户注册函数、是否要core dump）
 */

#include <stdarg.h>
#include "error_functions.h"
#include "tlpi_hdr.h"
#include "ename.h"

#ifdef __GNUC__
__attribute__ ((__noreturn__))
#endif
static void terminate(Boolean useExit3) {
    char *s = getenv("EF_DUMPCORE");

    if (s != NULL && *s != '\0') {
        abort();
    } else if (useExit3) {
        exit(EXIT_FAILURE);
    } else {
        _exit(EXIT_FAILURE);
    }
}

static void outputError(Boolean useErr, int err, Boolean flushStdout, const char *format, va_list ap) {
#define BUF_SIZE 513
    char buf[BUF_SIZE], userMsg[BUF_SIZE], errText[BUF_SIZE];
    vsnprintf(userMsg, BUF_SIZE, format, ap);

    if (useErr) {
        snprintf(errText, BUF_SIZE, " [%s %s]", (err > 0 && err <= MAX_ENAME) ? ename[err] : "?UNKNOWN?", strerror(err));
    } else {
        snprintf(errText, BUF_SIZE, ":");
    }

    snprintf(buf, BUF_SIZE, "ERROR%s %s\n", errText, userMsg);
    if (flushStdout) { /* NOTE: 当标准输出和标准输入为同一位置的时候，会导致输出的混乱，刷新一下标准输出再输出错误信息 */
        fflush(stdout);
    }
    fputs(buf, stderr);
    fflush(stderr);
}

void errMsg(const char *format, ...) {
    va_list argList;
    int savedErrno;

    /* 使用其他系统调用同样可能导致错误，致使errno产生变化，所以保存起来原来的值，使得内部过程对外透明 */
    savedErrno = errno;

    va_start(argList, format);
    outputError(TRUE, errno, TRUE, format, argList);
    va_end(argList);
    errno = savedErrno;
}

void errExit(const char *format, ...) {
    va_list argList;

    va_start(argList, format);
    outputError(TRUE, errno, TRUE, format, argList);
    va_end(argList);

    terminate(TRUE);
}

void err_exit(const char *format, ...) {
    va_list argList;
    va_start(argList, format);
    outputError(TRUE, errno, FALSE, format, argList);
    va_end(argList);

    terminate(FALSE);
}

void errExitEN(int errnum, const char *format, ...) {
    va_list argList;
    va_start(argList, format);
    outputError(TRUE, errnum, TRUE, format, argList);
    va_end(argList);

    terminate(TRUE);
}

void fatal(const char *format, ...) {
    va_list ap;

    va_start(ap, format);
    outputError(FALSE, 0, TRUE, format, ap);
    va_end(ap);

    terminate(TRUE);
}

void usageErr(const char *format, ...) {
    va_list argList;
    fflush(stdout); /* Flush any pending stdout */

    fprintf(stderr, "Usage: ");
    va_start(argList, format);
    vfprintf(stderr, format, argList);
    va_end(argList);

    fflush(stderr); /* In case stderr is not line-buffered */
    exit(EXIT_FAILURE);
}

void cmdLineError(const char *format, ...) {
    va_list argList;

    fflush(stdout);

    va_start(argList, format);
    vfprintf(stderr, format, argList);
    va_end(argList);

    fflush(stderr);
    exit(EXIT_FAILURE);
}
