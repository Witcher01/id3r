#include <stdlib.h>

#include "id3v1.h"

int
main(int argc, char *argv[])
{
    FILE *f;

    if (argc != 2) {
        fputs("usage: id3r filename\n", stderr);

        exit(EXIT_FAILURE);
    }

    f = fopen(argv[1], "rb");
    printid3v1(f);

    return EXIT_SUCCESS;
}
