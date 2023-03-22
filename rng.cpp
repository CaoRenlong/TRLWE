#include "rng.h"
#include <random>
#include "poly.h"
uint8_t randombytes() {
	return rand()%256;
}
//生成k-byte随机数
void randomarray(uint8_t* buf, int8_t k) {
	for (int i = 0; i < k; i++) {
		buf[i] = randombytes();
	}
}
void randompoly(poly* p, int16_t k) {
	for (int i = 0; i < k; i++) {
		p->coeffs[i] = randombytes();
	}
}
void randompoly_2(poly* p, int16_t k) {
	for (int i = 0; i < k; i++) {
		p->coeffs[i] = randombytes()%2;
	}
}
//int main() {
//	
//	//for (int i = 0; i < 100; i++) {
//	//	uint8_t a = randombytes();
//	//	printf("%d\n", a);
//	//}
//	uint8_t buf[10];
//	randomarray(buf, 10);
//	//for (int i = 0; i < 10; i++) {
//	//	uint8_t a = buf[i];
//	//	printf("%d\n", a);
//	//}
//	struct poly A;
//	poly* a = &A;
//	randompoly(a, 10);
//	for (int i = 0; i < 256; i++) {
//		uint8_t b = a->coeffs[i];
//		printf("%d\n", b);
//	}
//	
//}