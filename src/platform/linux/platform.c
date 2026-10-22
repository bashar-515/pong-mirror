#include "platform/platform.h"

#include <stddef.h>

#include "wayland/wayland.h"

const char *platform_run(void) {
    const char *err_msg = NULL;

    wayland_connect(&err_msg);
    if (err_msg != NULL) {
        return err_msg;
    }

    return NULL;
}
