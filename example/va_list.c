//
// Created by yanghuichen on 2020-10-04.
//

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Pair;

void foo(const char *fmt, ...) {
    if (!fmt) {
        exit(-1);
    }
    va_list ap;
    va_start(ap, fmt);
    while (*fmt) {
        switch (*fmt) {
            case 's':
                printf("str = %s\n", va_arg(ap, char *));
                break;
            case 'd':
                printf("int = %d\n", va_arg(ap, int));
                break;
            case 'p':
                printf("p.a = %d\n", va_arg(ap, Pair).a);
                break;
            default:
                printf("unknown\n");
        }
        fmt++;
    }
    va_end(ap);
}
