#ifndef ORZ_MACRO_H
#define ORZ_MACRO_H
#include <stdio.h>

#define ORZ_API __attribute__((visibility("default")))
#define ORZ_LOG(fp, ...) \
do { fprintf(fp, "[orz] " __VA_ARGS__); fputc('\n', fp); } while(0)

#endif/*ORZ_MACRO_H*/