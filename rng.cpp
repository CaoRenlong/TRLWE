#include "rng.h"
#include <random>
#include "poly.h"
#include "rng2.h"
#include <openssl/rand.h>
uint8_t randombytes() {
	return rand()%256;
	
}
/*
randombytes(unsigned char* x, unsigned long long xlen)可以替换randomarray(uint8_t* buf, int8_t k)
*/
//生成k-byte随机数
void randomarray(uint8_t* buf, int8_t k) {
	//for (int i = 0; i < k; i++) {
	//	buf[i] = randombytes();
	//}
	//randombytes(buf, k);
	RAND_bytes(buf, k);
}
void randompoly(poly* p, int16_t k) {
	uint8_t* pp;
	pp = (uint8_t*)malloc(k * sizeof(uint8_t));
	//randombytes(pp, k);
	//unsigned char buf[k] = { 0 };
	RAND_bytes(pp, k);
	for (int i = 0; i < k; i++) {
		p->coeffs[i] = pp[i];
		//p->coeffs[i] = randombytes();
	}
}
void randompoly_2(poly* p, int16_t k) {
	uint8_t* pp=NULL;
	pp = (uint8_t*)malloc(k * sizeof(uint8_t));
	//randombytes(pp, k);
	RAND_bytes(pp, k);
	for (int i = 0; i < k; i++) {
		p->coeffs[i] = pp[i]%2;
		//p->coeffs[i] = randombytes()%2;
	}
}
//int main() {
//	
//	//for (int i = 0; i < 100; i++) {
//	//	uint8_t a = randombytes();
//	//	printf("%d\n", a);
//	//}
//	//uint8_t buf[64];
//	//randomarray(buf, 64);
//	//for (int i = 0; i < 10; i++) {
//	//	uint8_t a = buf[i];
//	//	printf("%d\n", a);
//	//}
//	struct poly A;
//	poly* a = &A;
//	//randompoly(a, 256);
//	//unsigned char buf[16] = { 0 };//用来接收产生的随机数
//	//int re = RAND_bytes(buf, sizeof(buf));
//	//randomarray(buf, sizeof(buf));
//	randompoly_2(a, 16);
//	for (int i = 0; i < 16; i++) {
//		printf("%d\n", a->coeffs[i]);
//	}
//	
//}