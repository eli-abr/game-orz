#ifndef ORZ_GAME_H
#define ORZ_GAME_H
#include <eae/macro.h>
#include <raylib.h>

typedef void (*EaeProcess_func)(void *data);

typedef struct {
    void *impl;
    void (*ready)(void *impl);
    void (*update)(void *impl);
    void (*handle)(void *impl);
    void (*render)(void *impl);
} EaeNodeImpl;

typedef struct {
    Vector2 offset;
} EaeTransform2DImpl;

typedef struct {
    Vector2 direct;
    float speed;
} EaeCharacterImpl;

typedef struct {
    EaeNodeImpl **arr;
    size_t count;
    size_t size;
} EaeNodeList;

EaeNodeList *eaeNodeListCreate();
void eaeNodeListDestroy(EaeNodeList *self);
void eaeNodeListInsert(EaeNodeList *self, EaeNodeImpl *node_impl);
void eaeNodeListRemove(EaeNodeList *self, EaeNodeImpl *node_impl);

#endif/*Eae_GAME_H*/
