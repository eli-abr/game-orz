#ifndef ORZ_CHARATER_H
#define ORZ_CHARATER_H
#include <eae/game.h>

typedef struct {
    EaeNodeImpl         node_impl;
    EaeCharacterImpl    crt_impl;
    EaeTransform2DImpl  trans_impl;
} OrzCharater;

OrzCharater *orzCharaterCreate();

#endif/*ORZ_CHARATER_H*/