#include <eae/asset.h>
#include <raylib.h>
#include <limits.h>
#include <string.h>
#include <cwalk.h>

static char prv_asset_path[PATH_MAX];
void eaeSetAssetPath(const char *path)
{
    if (path == nullptr) {
        strlcpy(prv_asset_path, GetApplicationDirectory(), PATH_MAX);
    } else if (*path == '/') {
        strlcpy(prv_asset_path, path, PATH_MAX);
    } else {
        cwk_path_get_absolute(GetApplicationDirectory(), path, prv_asset_path, PATH_MAX);
    }
    EAE_LOG(stdout, "asset path: %s", prv_asset_path);
}
const char *eaeGetAssetPath()
{
    return prv_asset_path;
}
size_t eaeAssetUrl(char *str, size_t maxlen, const char *path)
{
    return cwk_path_get_absolute(prv_asset_path, path, str, maxlen);
}