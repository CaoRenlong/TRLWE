#ifndef INDCPA_H
#define INDCPA_H

#include <stdint.h>
#include "params.h"
#include "poly.h"
extern poly* a;
extern poly* p;
extern poly* m;
extern poly* m1;
void gen_a(poly* a);
void indcpa_keypair(poly* pk, poly* sk);
void encode(poly* m);
void decode(poly* m);
void gen_m(poly* m);
void indcpa_enc(poly* m, poly* c1, poly* c2);
void indcpa_dec(poly* m1, poly* c1, poly* c2, poly* sk);
#endif