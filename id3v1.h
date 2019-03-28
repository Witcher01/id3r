#ifndef ID3V1_H
#define ID3V1_H

#include <inttypes.h>
#include <stdio.h>

uint8_t checkid3v1(FILE *);
void printid3v1(FILE *);

#endif /* ID3V1_H */
