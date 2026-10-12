#include <raylib.h>
#include <stdlib.h>
#include <raymath.h>
#include <orz/asset.h>
#include <limits.h>

Texture2D *prv_tex = nullptr;

Vector2 pos = {};
Vector2 dir = {};
float speed = 10.f;
static void prv_raylib_init()
{
    InitWindow(640, 360, "dev");
    SetTargetFPS(60);
    Orz_SetAssetPath(nullptr);
    char path[PATH_MAX];
    (void)Orz_AssetUrl(path, PATH_MAX, "../asset/img/精灵-0001.png");
    prv_tex = malloc(sizeof(Texture2D));
    *prv_tex = LoadTexture(path);
    ORZ_LOG(stdout, "ball path: %s", path);
}
static void prv_event()
{
    dir = (Vector2){};
    if (IsKeyDown(KEY_A)) dir.x -= 1.f;
    if (IsKeyDown(KEY_D)) dir.x += 1.f;
    if (IsKeyDown(KEY_W)) dir.y -= 1.f;
    if (IsKeyDown(KEY_S)) dir.y += 1.f;
    dir = Vector2Normalize(dir);
}
static void prv_update()
{
    pos.x += dir.x * speed;
    pos.y += dir.y * speed;
}
int main(int argc, char **argv)
{
    (void)argc, (void)argv;
    prv_raylib_init();
    while (!WindowShouldClose()) {
        prv_event();
        prv_update();
        BeginDrawing();
        ClearBackground(BLUE);
        DrawTexture(*prv_tex, (int)pos.x, (int)pos.y, WHITE);
        EndDrawing();
    }
    CloseWindow();
    free(prv_tex);
    exit(0);
}