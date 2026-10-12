#ifndef EAE_MACRO_H
#define EAE_MACRO_H
#include <stdio.h>

#define EAE_API __attribute__((visibility("default")))
#define EAE_LOG(fp, ...) \
do { fprintf(fp, "[eae] " __VA_ARGS__); fputc('\n', fp); } while(0)

#endif/*EAE_MACRO_H*/