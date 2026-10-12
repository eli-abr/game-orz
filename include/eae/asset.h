#ifndef EAE_ASSET_H
#define EAE_ASSET_H
#include <eae/macro.h>

EAE_API void eaeSetAssetPath(const char *path);
EAE_API const char *eaeGetAssetPath();
EAE_API size_t eaeAssetUrl(char *src, size_t size, const char *path);

#endif/*EAE_ASSET_H*/