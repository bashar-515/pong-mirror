#include <stdio.h>
#include <stdlib.h>

#define XDG_RUNTIME_DIR_ENV "XDG_RUNTIME_DIR"

static int foo(void) {
    const char *xdg_runtime_dir = getenv(XDG_RUNTIME_DIR_ENV);
    if (xdg_runtime_dir == NULL) {
        fprintf(stderr, XDG_RUNTIME_DIR_ENV " is not set\n");

        return -1;
    }

    return 0;
}

int main(void) {
    printf("hello, world\n");

    return 0;
}
