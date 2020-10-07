//
// Created by yanghuichen on 2020-08-09.
//

#ifndef LINUX_PROGRAMMING_TLPI_HDR_H
#define LINUX_PROGRAMMING_TLPI_HDR_H

#include <sys/types.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "error_functions.h"
#include "get_num.h"

typedef enum { FALSE, TRUE } Boolean;

#define min(m, n) (((m) < (n)) ? (m) : (n))
#define max(m, n) (((m) < (n)) ? (n) : (m))

#endif //LINUX_PROGRAMMING_TLPI_HDR_H
