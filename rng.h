#ifndef rng_h
#define rng_h

#include <stdio.h>
#include <stdint.h>
#include "poly.h"
uint8_t randombytes();
void randomarray(uint8_t* buf, int8_t k);
void randompoly(poly* p, int16_t k);
void randompoly_2(poly* p, int16_t k);
#endif