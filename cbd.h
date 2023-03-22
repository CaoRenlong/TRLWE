#ifndef CBD_H
#define CBD_H
#include "params.h"
#include <stdint.h>
#include "poly.h"

void cbd(poly* r, const uint8_t buf[2 * KYBER_N / 4]);
void cbd2(poly* r, const uint8_t buf[ KYBER_N / 4]);
void cbd3(poly* r, const uint8_t buf[KYBER_N / 4]);
//void cbd_256(poly* r, const uint8_t buf[2*KYBER_N]);
#endif