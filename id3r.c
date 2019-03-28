/* id3r is a small program to read only id3v1 tags. */
/* neither the extended tag nor the id3v2 formats are supported */

#include <stdlib.h>

#include "id3v1.h"

void usage(void);

void
usage(void)
{
    fputs("usage: id3r filename\n", stderr);

    exit(EXIT_FAILURE);
}

int
main(int argc, char *argv[])
{
    FILE *f;

    if (argc != 2) {
        usage();
    }

    f = fopen(argv[1], "rb");

    if (!f) {
        fprintf(stderr, "error, unable to open file: %s\n", argv[1]);
    }

    if(checkid3v1(f)) {
        puts("ID3v1 tag found!");
        printid3v1(f);
    }

    return EXIT_SUCCESS;
}
