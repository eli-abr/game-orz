#include <orz/character.h>
#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>

static void prvReady(OrzCharater *self)
{
    self->crt_impl.direct = (Vector2){};
}
static void prvHandle(OrzCharater *self)
{
    if (IsKeyDown(KEY_A)) self->crt_impl.direct.x -= 1.f;
    if (IsKeyDown(KEY_D)) self->crt_impl.direct.x += 1.f;
    if (IsKeyDown(KEY_W)) self->crt_impl.direct.y -= 1.f;
    if (IsKeyDown(KEY_S)) self->crt_impl.direct.y += 1.f;
    self->crt_impl.direct = Vector2Normalize(self->crt_impl.direct);
}
static void prvUpdate(OrzCharater *self)
{
    float delta = GetFrameTime();
    self->trans_impl.offset.x += self->crt_impl.direct.x * self->crt_impl.speed * delta;
    self->trans_impl.offset.y += self->crt_impl.direct.y * self->crt_impl.speed * delta;
}
static void prvRender(OrzCharater *self)
{
    DrawCircleV(self->trans_impl.offset, 50.f, GREEN);
}

OrzCharater *orzCharaterCreate()
{
    OrzCharater *self = (OrzCharater *)malloc(sizeof(OrzCharater));
    self->node_impl = (EaeNodeImpl){
        .impl       = self,
        .ready      = (EaeProcess_func)prvReady,
        .handle     = (EaeProcess_func)prvHandle,
        .update     = (EaeProcess_func)prvUpdate,
        .render     = (EaeProcess_func)prvRender
    };
    self->crt_impl = (EaeCharacterImpl) {
        .direct = (Vector2){},
        .speed = 200.f,
    };
    return self;
}
