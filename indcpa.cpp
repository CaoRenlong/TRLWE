#include <stddef.h>
#include <stdint.h>
#include "params.h"
#include "indcpa.h"
#include "poly.h"
#include "rng.h"
#include "cbd.h"
#include "universal.h"
struct poly A;
poly* a = &A;
struct poly P;
poly* p = &P;
struct poly M1;
poly* m1 = &M1;
struct poly M;
poly* m = &M;
//void gen_a(poly* a) {
//    randompoly(a, 256);
//    printf("公钥a=\n");
//    for (int i = 0; i < 256; i++) {
//        printf("%d ", a->coeffs[i]);
//    }
//    printf("\n");
//}
//void gen_m(poly* m) {
//    randompoly_2(m, TRLWE_N);
//    printf("m=\n");
//    for (int i = 0; i < 256; i++) {
//        printf("%d ", m->coeffs[i]);
//    }
//    printf("\n");
//}
//void encode(poly* m) {
//    for (int i = 0; i < TRLWE_N; i++) {
//        if(m->coeffs[i]==1){
//            m->coeffs[i] = 128;
//        }
//    }
//    printf("encode(m)=\n");
//    for (int i = 0; i < 256; i++) {
//        printf("%d ", m->coeffs[i]);
//    }
//    printf("\n");
//    
//}
//void decode(poly* m) {
//    for (int i = 0; i < TRLWE_N; i++) {
//        if (m->coeffs[i]>= -TRLWE_Q/4 && m->coeffs[i] <= TRLWE_Q / 4) {
//            m->coeffs[i] = 0;
//        }
//        else {
//            m->coeffs[i] = 1;
//        }
//    }
//    printf("decode(m1)=\n");
//    for (int i = 0; i < 256; i++) {
//        printf("%d ", m->coeffs[i]);
//    }
//    printf("\n");
//
//}
void indcpa_keypair(poly* pk,poly* sk) {
    //struct poly A;
    //poly* a = &A;
    gen_a(a);        //生成公钥a

    //struct poly P;
    //poly* p = &P;
    uint8_t buf3[64];
    randomarray(buf3, 64);

    coeff_center(a, TRLWE_Q);
    printf("公钥a(中心化)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ,", a->coeffs[i]);
    }
    printf("\n");

    struct poly E0;
    poly* e0 = &E0; 
    uint8_t buf1[64];
    randomarray(buf1, 64);
    cbd3(e0, buf1);     //生成误差e0
    printf("误差e0=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ,", e0->coeffs[i]);
    }
    printf("\n");


    uint8_t buf2[64];
    randomarray(buf2, 64);
    cbd3(sk, buf2);     //生成私钥sk
    printf("私钥sk=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ,", sk->coeffs[i]);
    }
    printf("\n");

    struct poly AS;
    poly* as = &AS;        

    poly_mul_center(as, a, sk);             //计算as
    printf("poly_mul_center(as):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", as->coeffs[i]);
    }
    printf("\n");

    //poly_mul(as, a, sk);         
    //printf("poly_mul(as):\n");
    //for (int i = 0; i < 256; i++) {
    //    printf("%d ", as->coeffs[i]);
    //}
    //printf("\n");

    poly_sub(p, e0, as);

    printf("公钥p(p=e0-as)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ,", p->coeffs[i]);
    }
    printf("\n");
}


void indcpa_enc(poly* m, poly* c1, poly* c2) {
    gen_m(m);
    printf("m=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ,", m->coeffs[i]);
    }
    printf("\n");
    encode(m);
    printf("encode(m)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m->coeffs[i]);
    }
    printf("\n");
    struct poly E1;
    poly* e1 = &E1;
    uint8_t buf1[64];
    randomarray(buf1, 64);
    cbd3(e1, buf1);     //生成误差e0
    printf("误差e1=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ,", e1->coeffs[i]);
    }
    printf("\n");
    struct poly E2;
    poly* e2 = &E2;
    uint8_t buf2[64];
    randomarray(buf2, 64);
    cbd3(e2, buf2);     //生成误差e0
    printf("误差e2=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ,", e2->coeffs[i]);
    }
    printf("\n");
    struct poly E3;
    poly* e3 = &E3;
    uint8_t buf3[64];
    randomarray(buf3, 64);
    cbd3(e3, buf3);     //生成误差e0
    printf("误差e3=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ,", e3->coeffs[i]);
    }
    printf("\n");

    struct poly AE1;
    poly* ae1 = &AE1;

    poly_mul_center(ae1, a, e1);             //计算ae1
    printf("poly_mul_center(ae1):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", ae1->coeffs[i]);
    }
    printf("\n");

    poly_add(c1, ae1, e2);
    printf("密文c1(c1=ae1+e2)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", c1->coeffs[i]);
    }
    printf("\n");

    struct poly PE1;
    poly* pe1 = &PE1;
    struct poly PE1_E3;
    poly* pe1_e3 = &PE1_E3;

    poly_mul_center(pe1, p, e1);             //计算pe1
    printf("poly_mul_center(pe1):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", pe1->coeffs[i]);
    }
    printf("\n");

    poly_add(pe1_e3, pe1, e3);               //计算pe1+e3
    printf("pe1_e3(pe1_e3=pe1+e3)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", pe1_e3->coeffs[i]);
    }
    printf("\n");

    poly_add(c2, pe1_e3, m);               //计算pe1+e3
    printf("c2(c2=pe1+e3+m)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", c2->coeffs[i]);
    }
    printf("\n");

}

void indcpa_dec(poly* m1, poly* c1, poly* c2,poly* sk) {
    struct poly C1S;
    poly* c1s = &C1S;
    struct poly C1S_C2;
    poly* c1s_c2 = &C1S_C2;

    poly_mul_center(c1s, sk, c1);             //计算c1s
    printf("poly_mul_center(c1s):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", c1s->coeffs[i]);
    }
    printf("\n");

    poly_add(m1, c1s, c2);               //计算pe1+e3
    printf("m1(m1=c1s+c2)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m1->coeffs[i]);
    }
    printf("\n");

    decode(m1);
    printf("m1=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m1->coeffs[i]);
    }
    printf("\n");
    decode(m);
    printf("m=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m->coeffs[i]);
    }
    printf("\n");
}
//int main() {
//    struct poly P;
//    struct poly S;
//    poly* p = &P;
//    poly* s = &S;
//    indcpa_keypair(p, s);
//    struct poly C1;
//    poly* c1 = &C1;
//    struct poly C2;
//    poly* c2 = &C2;
//    indcpa_enc(m,c1,c2);
//    indcpa_dec(m1, c1, c2, s);
//    poly_compare(m1, m);
//    if (poly_equal(m1, m)) {
//        printf("加解密失败！");
//    }
//    else
//    {
//        printf("加解密成功！");
//    }
//    //uint8_t buf[64];
//    //randomarray(buf, 64);
//    //cbd3(s, buf);
//    //for (int i = 0; i < 256; i++) {
//    //    printf("%d",p->coeffs[i]);
//    //}
//    //printf("\n");
//    //for (int i = 0; i < 256; i++) {
//    //    printf("%d", s->coeffs[i]);
//    //}
//    //printf("\n");
//    //struct poly A;
//    //poly* a = &A;
//    //gen_a(a);
//    //for (int i = 0; i < 256; i++) {
//    //    printf("%d ", a->coeffs[i]);
//    //}
//    return 0;
//}