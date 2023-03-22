#include<stdio.h>
#include<stdint.h>
#include "poly.h"
#include "params.h"
#include <string.h>
void poly_init(poly* r)
{
    memset(r, 0, 512);
}
void poly_4_init(poly_4* r)
{
    memset(r, 0, 8);
}
void poly_add(poly* r, const poly* a, const poly* b)
{
    unsigned int i;
    for (i = 0; i < KYBER_N; i++)
        r->coeffs[i] = (a->coeffs[i] + b->coeffs[i])&0xFF;
    coeff_center(r, KYBER_Q);
}
void poly_sub(poly* r, const poly* a, const poly* b)
{
    unsigned int i;
    for (i = 0; i < KYBER_N; i++)
        r->coeffs[i] = (a->coeffs[i] - b->coeffs[i]+ KYBER_Q)% KYBER_Q;
    coeff_center(r, KYBER_Q);
}

void poly_mul(poly* r, const poly* a, const poly* b) 
{
    poly_init(r);
    for (int i = 0; i < KYBER_N; i++) {
        int16_t res = 0;
        for (int j = 0; j < KYBER_N; j++) {
            int16_t ab = a->coeffs[i] * b->coeffs[j];
            int16_t ab_m = ab % KYBER_Q;
            int8_t  sig = (i + j) > (KYBER_N - 1) ? 1 : 0;
            if (sig == 1) {
                ab_m = KYBER_Q - ab_m;
            }
            int16_t temp = ab_m % KYBER_Q;
            res = temp;
            r->coeffs[(i + j) % KYBER_Q] = (res + r->coeffs[(i + j) % KYBER_Q]) % KYBER_Q;
        }

    }
}
void toy_poly_mul(poly_4* r, const poly_4* a, const poly_4* b) {
    poly_4_init(r);
    for (int i = 0; i < TOY_N; i++) {
        int16_t res = 0;
        for (int j = 0; j < TOY_N; j++) {
            int16_t ab = a->coeffs[i] * b->coeffs[j];
            int16_t ab_m = ab % TOY_Q;
            int8_t  sig = (i + j) > (TOY_N - 1) ? 1 : 0;
            if (sig == 1) {
                ab_m = TOY_Q - ab_m;
            }
            int16_t temp = ab_m % TOY_Q;
            res = temp;
            r->coeffs[(i + j) % TOY_Q] = (res+ r->coeffs[(i + j) % TOY_Q])% TOY_Q;
        }

    }
}
void poly_mul_center(poly* r, const poly* a, const poly* b) {
    poly_init(r);
    for (int i = 0; i < KYBER_N; i++) {
        for (int j = 0; j < KYBER_N; j++) {
            int16_t ab = a->coeffs[i] * b->coeffs[j];
            int8_t  sig = (i + j) > (KYBER_N - 1) ? 1 : 0;
            if (sig == 1) {
                ab = -ab;
            }
            r->coeffs[(i + j) % KYBER_Q] = (ab + r->coeffs[(i + j) % KYBER_Q]) % KYBER_Q;
        }

    }
    coeff_center(r, KYBER_Q);
}
void toy_poly_mul_center(poly_4* r, const poly_4* a, const poly_4* b) {
    poly_4_init(r);
    for (int i = 0; i < TOY_N; i++) {
        for (int j = 0; j < TOY_N; j++) {
            int16_t ab = a->coeffs[i] * b->coeffs[j];
            int8_t  sig = (i + j) > (TOY_N - 1) ? 1 : 0;
            if (sig == 1) {
                ab = - ab;
            }
            r->coeffs[(i + j) % TOY_Q] = (ab + r->coeffs[(i + j) % TOY_Q]) % TOY_Q;
        }

    }
    coeff_center_poly4(r, TOY_Q);
}
void coeff_center(poly* a, uint16_t t) {
    for (int i = 0; i < t; i++) {
        if (a->coeffs[i] > (t / 2 - 1)) {
            a->coeffs[i] -= t;
        }
        if (a->coeffs[i] < -(t / 2)) {
            a->coeffs[i] += t;
        }
    }
}
void coeff_center_poly4(poly_4* a, uint16_t t) {
    for (int i = 0; i < t; i++) {
        if (a->coeffs[i] > (t / 2 - 1)) {
            a->coeffs[i] -= t;
        }
    }
}
//int main() {
//    //struct poly P;
//    //struct poly S;
//    //struct poly R;
//    //poly* p = &P;
//    //poly* s = &S;
//    //poly* r = &R;
//    //poly_init(p);
//    //poly_init(s);
//    //poly_init(r);
//    struct poly_4 PP;
//    struct poly_4 SS;
//    struct poly_4 RR;
//    poly_4* pp = &PP;
//    poly_4* ss = &SS;
//    poly_4* rr = &RR;
//    poly_4_init(pp);
//    poly_4_init(ss);
//    poly_4_init(rr);
//
//    for (int i = 0; i < 4; i++) {
//        pp->coeffs[i] = 3;
//        ss->coeffs[i] = -(i+1);
//    }
//
//    //for (int i = 0; i <256; i++) {
//    //    p->coeffs[i] = i;
//    //    s->coeffs[i] = 1;
//    //}
//    //toy_poly_mul(rr,pp, ss);
//    //poly_mul(r, p, s);
//    //coeff_center(p, KYBER_Q);
//    toy_poly_mul_center(rr, pp, ss);
//    for (int i = 0; i < 4; i++) {
//        printf("%d ",rr->coeffs[i]);
//    }
//    return 0;
//}