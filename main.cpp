#include <stddef.h>
#include <stdint.h>
#include "params.h"
#include "indcpa.h"
#include "poly.h"
#include "rng.h"
#include "cbd.h"

int main() {


    struct poly C1;
    poly* c1 = &C1;
    struct poly C2;
    poly* c2 = &C2;

    struct poly P;
    struct poly S;
    poly* p = &P;
    poly* s = &S;
    indcpa_keypair(p, s);


    indcpa_enc(m,c1,c2);
    indcpa_dec(m1, c1, c2, s);
    //uint8_t buf[64];
    //randomarray(buf, 64);
    //cbd3(s, buf);
    //for (int i = 0; i < 256; i++) {
    //    printf("%d",p->coeffs[i]);
    //}
    //printf("\n");
    //for (int i = 0; i < 256; i++) {
    //    printf("%d", s->coeffs[i]);
    //}
    //printf("\n");
    //struct poly A;
    //poly* a = &A;
    //gen_a(a);
    //for (int i = 0; i < 256; i++) {
    //    printf("%d ", a->coeffs[i]);
    //}
    return 0;
}