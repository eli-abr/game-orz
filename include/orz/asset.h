#ifndef ORZ_ASSET_H
#define ORZ_ASSET_H
#include <orz/macro.h>

ORZ_API void Orz_SetAssetPath(const char *path);
ORZ_API const char *Orz_GetAssetPath();
ORZ_API size_t Orz_AssetUrl(char *src, size_t size, const char *path);

#endif/*ORZ_ASSET_H*/