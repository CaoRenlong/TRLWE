#include <stddef.h>
#include <stdint.h>
#include "params.h"
#include "indcpa.h"
#include "poly.h"
#include "rng.h"
#include "cbd.h"
#include "universal.h"
#include "indcpamask.h"
#include "indcpaunmask.h"
//struct poly A_;
//poly* a_ = &A_;
////struct poly P;
////poly* p = &P;
//struct poly M1_;
//poly* m1_ = &M1_;
//struct poly M_;
//poly* m_ = &M_;
//struct poly M_PRIME;
//poly* m_prime = &M_PRIME;
//struct poly MASK;
//poly* mask = &MASK;

void indcpaunmask_keypair(poly* p, poly* s1, poly* s2) {
    printf("密钥生成过程（开始）*****************************************\n");

    //gen_a(a);                 //生成公钥a
    //coeff_center(a, TRLWE_Q);
    int a00[256] = { 14 ,-113 ,-99 ,84 ,44 ,25 ,-24 ,13 ,37 ,-13 ,-27 ,-35 ,55 ,-4 ,110 ,-43 ,107 ,67 ,92 ,-116 ,-77 ,-106 ,-57 ,-74 ,-13 ,73 ,43 ,-79 ,-28 ,-120 ,-121 ,14 ,84 ,45 ,91 ,99 ,2 ,124 ,-68 ,39 ,83 ,47 ,112 ,-36 ,-22 ,55 ,-69 ,52 ,82 ,70 ,-104 ,82 ,98 ,-96 ,61 ,-59 ,-24 ,3 ,-121 ,25 ,106 ,66 ,4 ,67 ,-61 ,123 ,91 ,-113 ,113 ,-45 ,114 ,-72 ,2 ,-120 ,-9 ,123 ,37 ,-84 ,-118 ,-38 ,47 ,-112 ,-125 ,-70 ,1 ,84 ,-111 ,22 ,-57 ,-39 ,42 ,-26 ,-75 ,26 ,77 ,38 ,-103 ,-109 ,-85 ,93 ,-27 ,-70 ,90 ,-55 ,-61 ,62 ,108 ,-88 ,-94 ,-119 ,-96 ,-68 ,-1 ,80 ,30 ,-112 ,87 ,121 ,-98 ,-18 ,106 ,-5 ,-24 ,-69 ,-57 ,20 ,-99 ,-57 ,-95 ,1 ,-96 ,-111 ,-10 ,-1 ,68 ,76 ,50 ,-9 ,60 ,104 ,-92 ,-24 ,-48 ,-27 ,63 ,-41 ,58 ,-21 ,2 ,-77 ,53 ,-24 ,-49 ,-125 ,-125 ,-37 ,-69 ,76 ,-87 ,-7 ,106 ,-90 ,-117 ,54 ,33 ,-126 ,-30 ,-51 ,78 ,118 ,33 ,121 ,-15 ,-111 ,122 ,12 ,-60 ,7 ,49 ,-104 ,-2 ,-12 ,81 ,99 ,117 ,22 ,118 ,38 ,-123 ,102 ,35 ,-76 ,13 ,-91 ,-22 ,-56 ,26 ,-77 ,35 ,19 ,13 ,13 ,48 ,-83 ,47 ,121 ,-5 ,-65 ,104 ,-121 ,-47 ,-58 ,98 ,103 ,119 ,-6 ,21 ,-34 ,-83 ,32 ,-67 ,-26 ,-108 ,-32 ,-80 ,23 ,-70 ,25 ,17 ,-88 ,74 ,-26 ,32 ,-68 ,-111 ,71 ,119 ,103 ,12 ,-65 ,-52 ,-78 ,46 ,-14 ,5 ,84 ,36 ,59 ,50 ,18 ,-60 ,87 ,-6 ,126 ,-25 ,-55 };
    for (int i = 0; i < 256; i++) {
        a->coeffs[i] = a00[i];
    }
    printf("公钥a(中心化)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", a->coeffs[i]);
    }
    printf("\n");


    uint8_t buf1[64];
    randomarray(buf1, 64);

    bin_sample(mask, buf1);//生成掩码mask   
    printf("掩码mask=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", mask->coeffs[i]);
    }
    printf("\n");


    struct poly E0;
    poly* e0 = &E0;
    uint8_t buf2[64];
    randomarray(buf2, 64);
    //cbd3(e0, buf2);
    //bin_sample(e0, buf2);//生成误差e0 {0,1}分布   
    int e00[256] = {-1 ,-1 ,0 ,0 ,-1 ,0 ,1 ,1 ,1 ,0 ,-1 ,0 ,1 ,-1 ,0 ,0 ,1 ,-1 ,0 ,-1 ,-1 ,1 ,-1 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,-1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,0 ,1 ,0 ,-1 ,0 ,1 ,0 ,-1 ,0 ,0 ,-1 ,-1 ,0 ,0 ,0 ,0 ,0 ,0 ,-1 ,1 ,-1 ,0 ,1 ,1 ,0 ,1 ,1 ,-1 ,-1 ,-1 ,-1 ,0 ,1 ,1 ,0 ,-1 ,-1 ,1 ,0 ,1 ,0 ,0 ,1 ,-1 ,1 ,0 ,1 ,0 ,0 ,-1 ,-1 ,0 ,0 ,1 ,-1 ,0 ,0 ,-1 ,-1 ,0 ,0 ,0 ,0 ,-1 ,1 ,0 ,-1 ,1 ,0 ,0 ,0 ,0 ,1 ,-1 ,0 ,-1 ,0 ,-1 ,1 ,0 ,0 ,1 ,1 ,1 ,-1 ,-1 ,-1 ,0 ,1 ,0 ,-1 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,-1 ,1 ,-1 ,0 ,0 ,-1 ,0 ,0 ,1 ,0 ,-1 ,0 ,-1 ,0 ,0 ,-1 ,0 ,-1 ,0 ,1 ,0 ,-1 ,0 ,1 ,0 ,0 ,-1 ,0 ,1 ,-1 ,-1 ,-1 ,1 ,0 ,0 ,-1 ,0 ,1 ,1 ,0 ,0 ,1 ,-1 ,-1 ,0 ,1 ,-1 ,1 ,0 ,0 ,-1 ,0 ,0 ,0 ,-1 ,1 ,-1 ,-1 ,0 ,0 ,1 ,-1 ,0 ,-1 ,-1 ,-1 ,1 ,0 ,1 ,1 ,-1 ,-1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,-1 ,1 ,0 ,-1 ,1 ,0 ,0 ,1 ,-1 ,0 ,0 ,0};
    for (int i = 0; i < 256; i++) {
        e0->coeffs[i] = e00[i];
    }
    printf("误差e0=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e0->coeffs[i]);
    }
    printf("\n");

    //struct poly S1;
    //poly* s1 = &S1;
    uint8_t buf3[64];
    randomarray(buf3, 64);
    bin_sample(s1, buf3); //生成(未掩码)私钥s1   
    //cbd3(s1, buf3);
    //int s00[256] = { -1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,-1 ,0 ,1 ,0 ,1 ,-1 ,-1 ,-1 ,0 ,1 ,0 ,1 ,1 ,0 ,0 ,-1 ,0 ,0 ,0 ,1 ,0 ,-1 ,0 ,-1 ,0 ,0 ,0 ,1 ,-1 ,1 ,-1 ,0 ,-1 ,1 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,-1 ,-1 ,1 ,0 ,-1 ,0 ,-1 ,0 ,0 ,0 ,0 ,1 ,-1 ,-1 ,-1 ,1 ,0 ,0 ,-1 ,0 ,1 ,0 ,1 ,0 ,0 ,-1 ,0 ,0 ,-1 ,0 ,-1 ,0 ,0 ,0 ,1 ,0 ,-1 ,1 ,0 ,0 ,1 ,0 ,-1 ,-1 ,0 ,0 ,0 ,-1 ,0 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,0 ,1 ,-1 ,0 ,1 ,0 ,-1 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,1 ,-1 ,0 ,-1 ,-1 ,0 ,0 ,0 ,1 ,0 ,1 ,1 ,-1 ,0 ,1 ,0 ,-1 ,0 ,-1 ,1 ,1 ,0 ,-1 ,0 ,-1 ,0 ,-1 ,0 ,0 ,0 ,-1 ,1 ,-1 ,0 ,0 ,0 ,1 ,-1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,0 ,-1 ,0 ,-1 ,-1 ,0 ,0 ,0 ,-1 ,0 ,0 ,1 ,1 ,-1 ,0 ,0 ,1 ,-1 ,0 ,0 ,0 ,-1 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,1 ,1 ,0 ,-1 ,0 ,0 ,0 ,0 ,0 ,0 ,-1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,-1 ,-1 ,-1 ,1 ,-1 ,-1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,-1 ,0 ,-1 ,0 ,1 ,0 ,0 ,0 ,0 ,-1 ,-1 ,-1 ,0 ,-1 ,0 ,1 ,0 };
    //for (int i = 0; i < 256; i++) {
    //    s1->coeffs[i] = s00[i];
    //}
    printf("(未掩码)私钥s1=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", s1->coeffs[i]);
    }
    printf("\n");

    //poly_xor(s1_prime, mask, s1);        //生成(掩码)私钥s1_prime
    //printf("(掩码)私钥s1_prime=\n");
    //for (int i = 0; i < 256; i++) {
    //    printf("%d ", s1_prime->coeffs[i]);
    //}
    //printf("\n");

    //struct poly S2;
    //poly* s2 = &S2;
    uint8_t buf4[64];
    randomarray(buf4, 64);
    bin_sample(s2, buf4);    //生成(未掩码)私钥s2   
    //cbd3(s2, buf4);

    printf("(未掩码)私钥s2=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", s2->coeffs[i]);
    }
    printf("\n");

    //poly_xor(s2_prime, mask, s2);      //生成(掩码)私钥s2_prime
    //printf("(掩码)私钥s2_prime=\n");
    //for (int i = 0; i < 256; i++) {
    //    printf("%d ", s2_prime->coeffs[i]);
    //}
    //printf("\n");


    struct poly AS;
    poly* as = &AS;                 //as=a(s1 + s2)
    struct poly S1_S2;
    poly* s1_s2 = &S1_S2;
    poly_add(s1_s2, s1, s2);
    //poly_xor(s1_s2, s1, s2);               //计算s1 + s2
    printf("s1 + s2:\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", s1_s2->coeffs[i]);
    }
    printf("\n");
    poly_mul_center(as, a, s1_s2);                     //计算a(s1 + s2)
    printf("as=a(s1 + s2):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", as->coeffs[i]);
    }
    printf("\n");

    struct poly AS1;
    poly* as1 = &AS1;                 
    poly_mul_center(as1, a, s1);
    printf("a * s1:\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", as1->coeffs[i]);
    }
    printf("\n");
    struct poly AS2;
    poly* as2 = &AS2;
    poly_mul_center(as2, a, s2);
    printf("a * s2:\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", as2->coeffs[i]);
    }
    printf("\n");
    struct poly AS1_AS2;
    poly* as1_as2 = &AS1_AS2;
    poly_add(as1_as2, as1, as2);
    //poly_xor(as1_as2, as1, as2);               //计算as1 + as2
    printf("as1 + as2:\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", as1_as2->coeffs[i]);
    }
    printf("\n");
    printf("比较as1_as2与 as\n");
    poly_compare(as1_as2, as);
    printf("\n");



    poly_sub(p, e0, as);

    printf("公钥p(p=e0-a(s1 + s2))=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", p->coeffs[i]);
    }
    printf("\n");
    printf("密钥生成过程（结束）*****************************************\n");
}

void indcpaunmask_enc(poly* m, poly* c1_primeprime, poly* c2_primeprime) {
    printf("加密过程（开始）*****************************************\n");

    gen_m(m);                   //生成消息m
    printf("m=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m->coeffs[i]);
    }
    printf("\n");
    encode(m);                  //encode消息m
    printf("encode(m)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m->coeffs[i]);
    }
    printf("\n");

    //struct poly M_PRIME;
    //poly* m_prime = &M_PRIME;
    gen_m(m_prime);           //生成消息m_prime
    printf("m_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m_prime->coeffs[i]);
    }
    printf("\n");
    encode(m_prime);          //encode消息m_prime
    printf("encode(m_prime)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m_prime->coeffs[i]);
    }
    printf("\n");


    struct poly E1;        //生成误差e1 {0,1}分布 
    poly* e1 = &E1;
    uint8_t buf1[64];
    randomarray(buf1, 64);
    //bin_sample(e1, buf1);
    cbd3(e1, buf1);
    printf("误差e1=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e1->coeffs[i]);
    }
    printf("\n");

    struct poly E2;       //生成误差e2 {0,1}分布
    poly* e2 = &E2;
    uint8_t buf2[64];
    randomarray(buf2, 64);
    //bin_sample(e2, buf2);
    cbd3(e2, buf2);
    printf("误差e2=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e2->coeffs[i]);
    }
    printf("\n");

    struct poly E3;     //生成误差e3 {0,1}分布
    poly* e3 = &E3;
    uint8_t buf3[64];
    randomarray(buf3, 64);
    //bin_sample(e3, buf3);
    cbd3(e3, buf3);
    printf("误差e3=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e3->coeffs[i]);
    }
    printf("\n");

    struct poly E1_PRIME;           //生成误差e1_prime {0,1}分布  
    poly* e1_prime = &E1_PRIME;
    uint8_t buf4[64];
    randomarray(buf4, 64);
    //bin_sample(e1_prime, buf4);
    cbd3(e1_prime, buf4);
    printf("误差e1_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e1_prime->coeffs[i]);
    }
    printf("\n");

    struct poly E2_PRIME;         //生成误差e2prime {0,1}分布
    poly* e2_prime = &E2_PRIME;
    uint8_t buf5[64];
    randomarray(buf5, 64);
    //bin_sample(e2_prime, buf5);
    cbd3(e2_prime, buf5);
    printf("误差e2_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e2_prime->coeffs[i]);
    }
    printf("\n");

    struct poly E3_PRIME;        //生成误差e3prime {0,1}分布
    poly* e3_prime = &E3_PRIME;
    uint8_t buf6[64];
    randomarray(buf6, 64);
    //bin_sample(e3_prime, buf6);
    cbd3(e3_prime, buf6);
    printf("误差e3_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e3_prime->coeffs[i]);
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

    struct poly C1;
    poly* c1 = &C1;
    poly_add(c1, ae1, e2);
    printf("密文c1(c1=ae1+e2)=\n");          //计算c1=ae1+e2
    for (int i = 0; i < 256; i++) {
        printf("%d ", c1->coeffs[i]);
    }
    printf("\n");

    struct poly AE1_PRIME;
    poly* ae1_prime = &AE1_PRIME;
    poly_mul_center(ae1_prime, a, e1_prime);             //计算ae1_prime
    printf("poly_mul_center(ae1_prime):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", ae1_prime->coeffs[i]);
    }
    printf("\n");

    struct poly C1_PRIME;
    poly* c1_prime = &C1_PRIME;
    poly_add(c1_prime, ae1_prime, e2_prime);
    printf("密文c1_prime(c1_prime=ae1_prime+e2_prime)=\n");          //计算c1_prime=ae1_prime+e2_prime
    for (int i = 0; i < 256; i++) {
        printf("%d ", c1_prime->coeffs[i]);
    }
    printf("\n");


    struct poly PE1;
    poly* pe1 = &PE1;
    struct poly PE1_E3;
    poly* pe1_e3 = &PE1_E3;
    struct poly C2;
    poly* c2 = &C2;
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

    //printf("m=\n");
    //for (int i = 0; i < 256; i++) {
    //    printf("%d ", m->coeffs[i]);
    //}
    //printf("\n");

    poly_add(c2, pe1_e3, m);               //计算pe1+e3+m
    printf("c2(c2=pe1+e3+m)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", c2->coeffs[i]);
    }
    printf("\n");

    struct poly PE1_PRIME;
    poly* pe1_prime = &PE1_PRIME;
    struct poly PE1_PRIME_E3_PRIME;
    poly* pe1_prime_e3_prime = &PE1_PRIME_E3_PRIME;
    struct poly C2_PRIME;
    poly* c2_prime = &C2_PRIME;
    poly_mul_center(pe1_prime, p, e1_prime);             //计算pe1_prime
    printf("pe1_prime:\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", pe1_prime->coeffs[i]);
    }
    printf("\n");

    poly_add(pe1_prime_e3_prime, pe1_prime, e3_prime);               //计算pe1_prime+e3_prime
    printf("pe1_prime_e3_prime=pe1_prime+e3_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", pe1_prime_e3_prime->coeffs[i]);
    }
    printf("\n");

    poly_add(c2_prime, pe1_prime_e3_prime, m_prime);               //计算pe1_prime+e3_prime+m_prime
    printf("c2_prime=pe1_prime+e3_prime+m_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", c2_prime->coeffs[i]);
    }
    printf("\n");

    poly_add(c1_primeprime, c1, c1_prime);
    printf("c1_primeprime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", c1_primeprime->coeffs[i]);
    }
    printf("\n");
    poly_add(c2_primeprime, c2, c2_prime);
    printf("c2_primeprime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", c2_primeprime->coeffs[i]);
    }
    printf("\n");
    printf("加密过程（结束）*****************************************\n");
}

void indcpaunmask_dec(poly* m1, poly* c1_primeprime, poly* c2_primeprime, poly* s1, poly* s2) {
    printf("解密过程（开始）*****************************************\n");
    struct poly S1_C1_PRIMEPRIME;
    poly* s1_c1_primeprime = &S1_C1_PRIMEPRIME;
    struct poly ALPHA_PRIME;
    poly* alpha_prime = &ALPHA_PRIME;

    poly_mul_center(s1_c1_primeprime, s1, c1_primeprime);             //计算s1_c1_primeprime
    printf("s1_c1_primeprime=s1*c1_primeprime:\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", s1_c1_primeprime->coeffs[i]);
    }
    printf("\n");

    poly_add(alpha_prime, s1_c1_primeprime, c2_primeprime);               //计算alpha_prime=s1_c1_primeprime_c2_primeprime
    printf("alpha_prime(alpha_prime=s1_c1_primeprime+c2_primeprime)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", alpha_prime->coeffs[i]);
    }
    printf("\n");

    struct poly ALPHA_PRIMEPRIME;
    poly* alpha_primeprime = &ALPHA_PRIMEPRIME;

    poly_mul_center(alpha_primeprime, s2, c1_primeprime);             //计算alpha_primeprime=s2+c1_primeprime
    printf("alpha_primeprime=poly_mul_center(s2_c2_primeprime):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", alpha_primeprime->coeffs[i]);
    }
    printf("\n");

    struct poly ALPHA;
    poly* alpha = &ALPHA;
    poly_add(alpha, alpha_prime, alpha_primeprime);
    printf("alpha=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", alpha->coeffs[i]);
    }
    printf("\n");

    decode(alpha);
    printf("decode(alpha)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", alpha->coeffs[i]);
    }
    printf("\n");
    printf("alpha=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", alpha->coeffs[i]);
    }
    printf("\n");
    decode(m_prime);
    poly_xor(m1, alpha, m_prime);
    printf("m1=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m1->coeffs[i]);
    }
    printf("\n");

    printf("解密过程（结束）*****************************************\n");
}
//int main() {
//    struct poly C1_PRIMEPRIME;
//    poly* c1_primeprime = &C1_PRIMEPRIME;
//    struct poly C2_PRIMEPRIME;
//    poly* c2_primeprime = &C2_PRIMEPRIME;
//    //
//    //    struct poly P;
//    //    struct poly S;
//    //    poly* p = &P;
//    //    poly* s = &S;
//    //    indcpa_keypair(p, s);
//    //
//    //
//    //    indcpa_enc(m,c1,c2);
//    //    indcpa_dec(m1, c1, c2, s);
//
//    struct poly S1;
//    struct poly S2;
//
//    poly* s1 = &S1;
//    poly* s2 = &S2;
//    indcpaunmask_keypair(p, s1, s2);
//    indcpaunmask_enc(m, c1_primeprime, c2_primeprime);
//    indcpaunmask_dec(m1, c1_primeprime, c2_primeprime, s1, s2);
//    poly_compare(m1, m);
//    if (poly_equal(m1, m)) {
//        printf("加解密失败！");
//    }
//    else
//    {
//        printf("加解密成功！");
//    }
//    //bin_sample()
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