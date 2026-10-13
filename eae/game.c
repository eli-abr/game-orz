#include <eae/game.h>
#include <stdlib.h>

EaeNodeList *eaeNodeListCreate()
{
    EaeNodeList *self = (EaeNodeList *)malloc(sizeof(EaeNodeList));
    self->size = 8U;
    self->arr = (EaeNodeImpl **)malloc(self->size * sizeof(EaeNodeImpl *));
    self->count = 0U;
    return self;
}
void eaeNodeListDestroy(EaeNodeList *self)
{
    free(self->arr);
    free(self);
}
void eaeNodeListInsert(EaeNodeList *self, EaeNodeImpl *node_impl)
{
    if (self->count >= self->size) {
        self->size += 8U;
        self->arr = (EaeNodeImpl **)realloc(self->arr, self->size * sizeof(EaeNodeImpl *));
    }
    self->arr[self->count] = node_impl;
    ++self->count;
}
void eaeNodeListRemove(EaeNodeList *self, EaeNodeImpl *node_impl)
{
    size_t i;
    for (i = 0U; i < self->count; ++i) {
        if (self->arr[i] == node_impl) break;
    }
    if (i == self->count) return;
    for (; i < self->count - 1; ++i) {
        self->arr[i] = self->arr[i + 1];
    }
    --self->count;
}
