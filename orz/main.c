#include <raylib.h>
#include <stdlib.h>
#include <raymath.h>
#include <eae/asset.h>
#include <limits.h>
#include <orz/character.h>

EaeNodeList *prv_scene;

static void prv_raylib_init()
{
    InitWindow(1920, 1080, "dev");
    SetTargetFPS(60);
    
    prv_scene = eaeNodeListCreate();
    
    OrzCharater *crt = orzCharaterCreate();
    eaeNodeListInsert(prv_scene, &crt->node_impl);
}

static void prv_ready()
{
    for (size_t i = 0U; i < prv_scene->count; ++i) {
        EaeNodeImpl *node_impl = prv_scene->arr[i];
        if (!node_impl->ready) continue;
        node_impl->ready(node_impl->impl);
    }
}
static void prv_handle()
{
    for (size_t i = 0U; i < prv_scene->count; ++i) {
        EaeNodeImpl *node_impl = prv_scene->arr[i];
        if (!node_impl->handle) continue;
        node_impl->handle(node_impl->impl);
    }
}
static void prv_update()
{
    for (size_t i = 0U; i < prv_scene->count; ++i) {
        EaeNodeImpl *node_impl = prv_scene->arr[i];
        if (!node_impl->update) continue;
        node_impl->update(node_impl->impl);
    }
}
static void prv_render()
{
    for (size_t i = 0U; i < prv_scene->count; ++i) {
        EaeNodeImpl *node_impl = prv_scene->arr[i];
        if (!node_impl->render) continue;
        node_impl->render(node_impl->impl);
    }
}

int main(int argc, char **argv)
{
    (void)argc, (void)argv;
    prv_raylib_init();

    
    while (!WindowShouldClose()) {
        prv_ready();
        prv_handle();
        prv_update();
        BeginDrawing();
        ClearBackground(BLUE);
        prv_render();
        EndDrawing();
    }
    CloseWindow();
    exit(0);
}