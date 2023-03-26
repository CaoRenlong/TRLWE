#ifndef INDCPAUNMASK_H
#define INDCPAUNMASK_H

#include <stdint.h>
#include "params.h"
#include "poly.h"


void indcpaunmask_keypair(poly* p, poly* s1_prime, poly* s2_prime);
void indcpaunmask_enc(poly* m, poly* c1_primeprime, poly* c2_primeprime);
void indcpaunmask_dec(poly* m1, poly* c1_primeprime, poly* c2_primeprime, poly* s1, poly* s2);
#endif