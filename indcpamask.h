#ifndef INDCPAMASK_H
#define INDCPAMASK_H

#include <stdint.h>
#include "params.h"
#include "poly.h"
extern poly* a_;
//extern poly* p;
extern poly* m_;
extern poly* m_prime;
extern poly* m1_;
extern poly* mask;
//void gen_a(poly* a_);
//void encode(poly* m_);
//void decode(poly* m_);
//void gen_m(poly* m_);
void indcpamask_keypair(poly* p, poly* s1_prime, poly* s2_prime);
void indcpamask_enc(poly* m, poly* c1_primeprime, poly* c2_primeprime);
//void indcpa_dec(poly* m1_, poly* c1_, poly* c2_, poly* sk_);
void indcpamask_dec(poly* m1, poly* c1_primeprime, poly* c2_primeprime, poly* sk1_prime, poly* sk2_prime);
#endif