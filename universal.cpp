#include <stddef.h>
#include <stdint.h>
#include "params.h"
#include "poly.h"
#include "rng.h"
#include "cbd.h"
#include "universal.h"
void gen_a(poly* a) {
    randompoly(a, 256);
    printf("¹«Ô¿a=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", a->coeffs[i]);
    }
    printf("\n");
}
void gen_m(poly* m) {
    randompoly_2(m, TRLWE_N);
    //printf("m=\n");
    //for (int i = 0; i < 256; i++) {
    //    printf("%d ", m->coeffs[i]);
    //}
    //printf("\n");
}
void encode(poly* m) {
    for (int i = 0; i < TRLWE_N; i++) {
        if (m->coeffs[i] == 1) {
            m->coeffs[i] = 128;
        }
    }
    //printf("encode(m)=\n");
    //for (int i = 0; i < 256; i++) {
    //    printf("%d ", m->coeffs[i]);
    //}
    //printf("\n");

}
void decode(poly* m) {
    for (int i = 0; i < TRLWE_N; i++) {
        if (m->coeffs[i] >= -TRLWE_Q / 4 && m->coeffs[i] <= TRLWE_Q / 4) {
            m->coeffs[i] = 0;
        }
        else {
            m->coeffs[i] = 1;
        }
    }
    //printf("decode(m1)=\n");
    //for (int i = 0; i < 256; i++) {
    //    printf("%d ", m->coeffs[i]);
    //}
    //printf("\n");

}