#include <stddef.h>
#include <stdint.h>
#include "params.h"
#include "indcpa.h"
#include "poly.h"
#include "rng.h"
#include "cbd.h"
#include "universal.h"
struct poly A_;
poly* a_ = &A_;
//struct poly P;
//poly* p = &P;
struct poly M1_;
poly* m1_= &M1_;
struct poly M_;
poly* m_ = &M_;
struct poly M_PRIME;
poly* m_prime = &M_PRIME;
struct poly MASK;
poly* mask = &MASK;

void indcpamask_keypair(poly* p, poly* s1_prime, poly* s2_prime) {
    printf("��Կ���ɹ��̣���ʼ��*****************************************\n");
    //struct poly A;
    //poly* a = &A;
    gen_a(a);                 //���ɹ�Կa
    coeff_center(a, TRLWE_Q);
    printf("��Կa(���Ļ�)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", a->coeffs[i]);
    }
    printf("\n");


    uint8_t buf1[32];
    randomarray(buf1, 32);

    bin_sample(mask, buf1);//��������mask   
    printf("����mask=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", mask->coeffs[i]);
    }
    printf("\n");


    struct poly E0;
    poly* e0 = &E0;
    uint8_t buf2[32];
    randomarray(buf2, 32);

    bin_sample(e0, buf2);//�������e0 {0,1}�ֲ�   
    printf("���e0=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e0->coeffs[i]);
    }
    printf("\n");

    struct poly S1;
    poly* s1 = &S1;
    uint8_t buf3[32];
    randomarray(buf3, 32);
    bin_sample(s1, buf3); //����(δ����)˽Կs1   
    printf("(δ����)˽Կs1=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", s1->coeffs[i]);
    }
    printf("\n");

    poly_xor(s1_prime, mask, s1);        //����(����)˽Կs1_prime
    printf("(����)˽Կs1_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", s1_prime->coeffs[i]);
    }
    printf("\n");

    struct poly S2;
    poly* s2 = &S2;
    uint8_t buf4[32];
    randomarray(buf4, 32);
    bin_sample(s2, buf4);    //����(δ����)˽Կs2   
    printf("(δ����)˽Կs2=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", s2->coeffs[i]);
    }
    printf("\n");

    poly_xor(s2_prime, mask, s2);      //����(����)˽Կs2_prime
    printf("(����)˽Կs2_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", s2_prime->coeffs[i]);
    }
    printf("\n");


    struct poly AS;           
    poly* as = &AS;                 //as=a(s1_prime + s2_prime)
    struct poly S1_PRIME_S2_PRIME;
    poly* s1_prime_s2_prime = &S1_PRIME_S2_PRIME;
    poly_xor(s1_prime_s2_prime, s1_prime, s2_prime);               //����s1_prime + s2_prime
    printf("s1_prime + s2_prime:\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", s1_prime_s2_prime->coeffs[i]);
    }
    printf("\n");
    poly_mul_center(as, a, s1_prime_s2_prime);                     //����a(s1_prime + s2_prime)
    printf("as=a(s1_prime + s2_prime):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", as->coeffs[i]);
    }
    printf("\n");

    poly_sub(p, e0, as);

    printf("��Կp(p=e0-a(s1_prime + s2_prime))=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", p->coeffs[i]);
    }
    printf("\n");
    printf("��Կ���ɹ��̣�������*****************************************\n");
}

void indcpamask_enc(poly* m, poly* c1_primeprime, poly* c2_primeprime) {
    printf("���ܹ��̣���ʼ��*****************************************\n");

    gen_m(m);                   //������Ϣm
    printf("m=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m->coeffs[i]);
    }
    printf("\n");
    encode(m);                  //encode��Ϣm
    printf("encode(m)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m->coeffs[i]);
    }
    printf("\n");

    //struct poly M_PRIME;
    //poly* m_prime = &M_PRIME;
    gen_m(m_prime);           //������Ϣm_prime
    printf("m_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m_prime->coeffs[i]);
    }
    printf("\n");
    encode(m_prime);          //encode��Ϣm_prime
    printf("encode(m_prime)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m_prime->coeffs[i]);
    }
    printf("\n");


    struct poly E1;        //�������e1 {0,1}�ֲ� 
    poly* e1 = &E1;
    uint8_t buf1[32];
    randomarray(buf1, 32);
    bin_sample(e1, buf1);
    printf("���e1=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e1->coeffs[i]);
    }
    printf("\n");

    struct poly E2;       //�������e2 {0,1}�ֲ�
    poly* e2 = &E2;
    uint8_t buf2[32];
    randomarray(buf2, 32);
    bin_sample(e2, buf2); 
    printf("���e2=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e2->coeffs[i]);
    }
    printf("\n");

    struct poly E3;     //�������e3 {0,1}�ֲ�
    poly* e3 = &E3;
    uint8_t buf3[32];
    randomarray(buf3, 32);
    bin_sample(e3, buf3);
    printf("���e3=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e3->coeffs[i]);
    }
    printf("\n");

    struct poly E1_PRIME;           //�������e1_prime {0,1}�ֲ�  
    poly* e1_prime = &E1_PRIME;
    uint8_t buf4[32];
    randomarray(buf4, 32);
    bin_sample(e1_prime, buf4);  
    printf("���e1_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e1_prime->coeffs[i]);
    }
    printf("\n");

    struct poly E2_PRIME;         //�������e2prime {0,1}�ֲ�
    poly* e2_prime = &E2_PRIME;
    uint8_t buf5[32];
    randomarray(buf5, 32);
    bin_sample(e2_prime, buf5);
    printf("���e2_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e2_prime->coeffs[i]);
    }
    printf("\n");

    struct poly E3_PRIME;        //�������e3prime {0,1}�ֲ�
    poly* e3_prime = &E3_PRIME;
    uint8_t buf6[32];
    randomarray(buf6, 32);
    bin_sample(e3_prime, buf6);
    printf("���e3_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", e3_prime->coeffs[i]);
    }
    printf("\n");


    struct poly AE1;
    poly* ae1 = &AE1;
    poly_mul_center(ae1, a, e1);             //����ae1
    printf("poly_mul_center(ae1):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", ae1->coeffs[i]);
    }
    printf("\n");

    struct poly C1;
    poly* c1 = &C1;
    poly_add(c1, ae1, e2);
    printf("����c1(c1=ae1+e2)=\n");          //����c1=ae1+e2
    for (int i = 0; i < 256; i++) {
        printf("%d ", c1->coeffs[i]);
    }
    printf("\n");

    struct poly AE1_PRIME;
    poly* ae1_prime = &AE1_PRIME;
    poly_mul_center(ae1_prime, a, e1_prime);             //����ae1_prime
    printf("poly_mul_center(ae1_prime):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", ae1_prime->coeffs[i]);
    }
    printf("\n");

    struct poly C1_PRIME;
    poly* c1_prime = &C1_PRIME;
    poly_add(c1_prime, ae1_prime, e2_prime);
    printf("����c1_prime(c1_prime=ae1_prime+e2_prime)=\n");          //����c1_prime=ae1_prime+e2_prime
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
    poly_mul_center(pe1, p, e1);             //����pe1
    printf("poly_mul_center(pe1):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", pe1->coeffs[i]);
    }
    printf("\n");

    poly_add(pe1_e3, pe1, e3);               //����pe1+e3
    printf("pe1_e3(pe1_e3=pe1+e3)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", pe1_e3->coeffs[i]);
    }
    printf("\n");

    poly_add(c2, pe1_e3, m);               //����pe1+e3
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
    poly_mul_center(pe1_prime, p, e1_prime);             //����pe1_prime
    printf("pe1_prime:\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", pe1_prime->coeffs[i]);
    }
    printf("\n");

    poly_add(pe1_prime_e3_prime, pe1_prime, e3);               //����pe1_prime+e3_prime
    printf("pe1_prime_e3_prime=pe1_prime+e3_prime=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", pe1_prime_e3_prime->coeffs[i]);
    }
    printf("\n");

    poly_add(c2_prime, pe1_prime_e3_prime, m_prime);               //����pe1_prime+e3_prime+m_prime
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
    printf("���ܹ��̣�������*****************************************\n");
}

void indcpamask_dec(poly* m1, poly* c1_primeprime, poly* c2_primeprime, poly* sk1_prime, poly* sk2_prime) {
    printf("���ܹ��̣���ʼ��*****************************************\n");
    struct poly S1_PRIME_C1_PRIMEPRIME;
    poly* s1_prime_c1_primeprime = &S1_PRIME_C1_PRIMEPRIME;
    struct poly ALPHA_PRIME;
    poly* alpha_prime = &ALPHA_PRIME;

    poly_mul_center(s1_prime_c1_primeprime, sk1_prime, c1_primeprime);             //����s1_prime_c1_primeprime
    printf("poly_mul_center(s1_prime_c1_primeprime):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", s1_prime_c1_primeprime->coeffs[i]);
    }
    printf("\n");

    poly_add(alpha_prime, s1_prime_c1_primeprime, c2_primeprime);               //����alpha_prime=s1_prime_c1_primeprime_c2_primeprime
    printf("alpha_prime(alpha_prime=s1_prime_c1_primeprime+c2_primeprime)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", alpha_prime->coeffs[i]);
    }
    printf("\n");

    struct poly ALPHA_PRIMEPRIME;
    poly* alpha_primeprime = &ALPHA_PRIMEPRIME;

    poly_mul_center(alpha_primeprime, sk2_prime, c1_primeprime);             //����alpha_primeprime=s2_prime+c1_primeprime
    printf("alpha_primeprime=poly_mul_center(s2_prime_c2_primeprime):\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", alpha_primeprime->coeffs[i]);
    }
    printf("\n");

    struct poly ALPHA;
    poly* alpha = &ALPHA;
    poly_add(alpha, alpha_prime, alpha_primeprime);

    decode(alpha);
    printf("decode(alpha)=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m->coeffs[i]);
    }
    printf("\n");
    printf("alpha=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", alpha->coeffs[i]);
    }
    printf("\n");

    poly_xor(m1, alpha, m_prime);
    printf("m1=\n");
    for (int i = 0; i < 256; i++) {
        printf("%d ", m1->coeffs[i]);
    }
    printf("\n");
    printf("���ܹ��̣�������*****************************************\n");
}
//int main() {
//    struct poly C1_PRIMEPRIME;
//    poly* c1_primeprime = &C1_PRIMEPRIME;
//    struct poly C2_PRIMEPRIME;
//    poly* c2_primeprime = &C2_PRIMEPRIME;
////
////    struct poly P;
////    struct poly S;
////    poly* p = &P;
////    poly* s = &S;
////    indcpa_keypair(p, s);
////
////
////    indcpa_enc(m,c1,c2);
////    indcpa_dec(m1, c1, c2, s);
//
//    struct poly S1_PRIME;
//    struct poly S2_PRIME;
//
//    poly* s1_prime = &S1_PRIME;
//    poly* s2_prime = &S2_PRIME;
//    indcpamask_keypair(p, s1_prime,s2_prime);
//    indcpamask_enc(m, c1_primeprime, c2_primeprime);
//    indcpamask_dec(m1, c1_primeprime, c2_primeprime, s1_prime, s2_prime);
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