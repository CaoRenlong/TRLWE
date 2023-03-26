#ifndef ADDITIVERLWE_H
#define ADDITIVERLWE_H

#include <stdint.h>
#include "params.h"
#include "poly.h"


void additiveRLWE_keypair(poly* p, poly* s1);
void additiveRLWE_enc(poly* m, poly* c1_primeprime, poly* c2_primeprime);
void additiveRLWE_dec(poly* m1, poly* c1_primeprime, poly* c2_primeprime, poly* s1);
#endif