#ifndef ORZ_GAME_H
#define ORZ_GAME_H
#include <orz/macro.h>

typedef struct {
    void *data;
    void (*preload)();
    void (*handle)();
    void (*update)();
    void (*render)();
} OrzScene;



#endif/*ORZ_GAME_H*/