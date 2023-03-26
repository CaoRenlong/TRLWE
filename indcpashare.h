#ifndef INDCPASHARE_H
#define INDCPASHARE_H

#include <stdint.h>
#include "params.h"
#include "poly.h"


void share_keypair(poly* p, poly* s1, poly* s2);
void share_enc(poly* m, poly* c1_primeprime, poly* c2_primeprime);
void share_dec(poly* m1, poly* c1_primeprime, poly* c2_primeprime, poly* s1, poly* s2);
#endif