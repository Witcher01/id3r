#include <inttypes.h>
#include <string.h>

#include "id3v1.h"

int
checkid3v1(FILE *f)
{
    /* a buffer for the first 4 bytes of the id3v1 tag + terminating NULL */
    char buffer[5];
    uint8_t i;

    /* set the current file pointer to the beginning of where the id3v1 tag should be */
    /* this is 128 bytes from the back of the file */
    fseek(f, -128, SEEK_END);

    /* copy the first 3 bytes of the supposed id3v1 tag to the buffer */
    for (i = 0; i < 4; ++i) {
        buffer[i] = fgetc(f);
    }
    /* add terminating NULL character to the end of the buffer, marking it as a string */
    buffer[4] = '\0';

    /* if first 3 bytes are "TAG" and the fourth isn't '+' */
    /* "TAG+" indicates id3v1.1 tag which is different from the id3v1 tag */
    if(!strcmp(buffer, "TAG") && !buffer[3] == '+') {
        /* 1 = true; 0 = false */
        return 1;
    }

    return 0;
}

void
printid3v1(FILE *f)
{
    /* the size of a field is a maximum of 30 bytes */
    char buffer[31];

    buffer[30] = '\0';
    /* start after the TAG field */
    fseek(f, -125, SEEK_END);

    /* read 30 bytes for the title */
    fread(buffer, 30, 1, f);
    printf("Title: %s\n", buffer);

    /* read 30 bytes for the artist name */
    fread(buffer, 30, 1, f);
    printf("Artist: %s\n", buffer);

    /* read 30 bytes for the album name */
    fread(buffer, 30, 1, f);
    printf("Album: %s\n", buffer);

    /* read 4 bytes for the year */
    fread(buffer, 4, 1, f);
    printf("Year: %s\n", buffer);

    /* read 30 bytes for the comment */
    fread(buffer, 30, 1, f);
    printf("Comment: %s\n", buffer);

    /* read 1 byte for the genre */
    fread(buffer, 1, 1, f);
    printf("Genre: %d\n", buffer[0]);
}
