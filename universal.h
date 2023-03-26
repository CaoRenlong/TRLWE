#ifndef UNIVERSAL_H
#define UNIVERSAL_H
#include "params.h"
#include <stdint.h>
#include "poly.h"

void gen_a(poly* a);
void gen_m(poly* m);
void encode(poly* m);
void decode(poly* m);
#endif