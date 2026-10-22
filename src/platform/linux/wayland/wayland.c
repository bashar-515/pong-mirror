#include "wayland.h"

#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/un.h>

#define XDG_RUNTIME_DIR_ENV "XDG_RUNTIME_DIR"

void wayland_connect(const char **err_msg) {
    const char *xdg_runtime_dir = getenv(XDG_RUNTIME_DIR_ENV);
    if (xdg_runtime_dir == NULL) {
        *err_msg = XDG_RUNTIME_DIR_ENV " is not set";

        return;
    }

    // size_t xdg_runtime_dir_len = strlen(xdg_runtime_dir);
    //
    // struct sockaddr_un addr = {.sun_family = AF_UNIX};
}
