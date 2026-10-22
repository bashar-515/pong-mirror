#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "platform/platform.h"

#define DEFAULT_PROG_NAME "pong"

static const char *get_prog_name(int argc, char *argv[]) {
    if (argc > 0 && argv[0][0] != '\0') {
        const char *slash = strrchr(argv[0], '/');

        if (slash == NULL) {
            return argv[0];
        } else if (slash[1] != '\0') {
            return slash + 1;
        }
    }

    return DEFAULT_PROG_NAME;
}

int main(int argc, char *argv[]) {
    const char *prog_name = get_prog_name(argc, argv);

    const char *err_msg = platform_run();
    if (err_msg != NULL) {
        fprintf(stderr, "%s: %s\n", prog_name, err_msg);

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
