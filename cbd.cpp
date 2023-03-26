#include "cbd.h"
#include "poly.h"
#include<stdint.h>
#include"rng.h"
#include <random>
static uint32_t load32_littleendian(const uint8_t x[4])
{
	uint32_t r;
	r = (uint32_t)x[0];
	r |= (uint32_t)x[1] << 8;
	r |= (uint32_t)x[2] << 16;
	r |= (uint32_t)x[3] << 24;
	return r;
}

static void cbd(poly* r, const uint8_t buf[2 * TRLWE_N / 4])
{
    unsigned int i, j;
    uint32_t t, d;
    int16_t a, b;

    for (i = 0; i < TRLWE_N / 8; i++) { //i<32 
        t = load32_littleendian(buf + 4 * i);//一次处理4byte
        d = t & 0x55555555;                  //d为t奇数bit对应数值
        d += (t >> 1) & 0x55555555;          //d加上t偶数bit对应数值

        for (j = 0; j < 8; j++) {            
            a = (d >> (4 * j + 0)) & 0x3;
            b = (d >> (4 * j + 2)) & 0x3;
            r->coeffs[8 * i + j] = a - b;
        }
    }
}
void cbd2(poly* r, const uint8_t buf[TRLWE_N / 4])//64个byte可以生成256个采样
{
    unsigned int i, j;
    uint32_t t, d;
    int16_t a, b;

    for (i = 0; i < TRLWE_N / 16; i++) { //i<16
        t = load32_littleendian(buf + 4 * i);//一次处理4byte，生成16个采样
        d = t;

        for (j = 0; j < 16; j++) {
            a = (d >> (2 * j + 0)) & 0x1;
            b = (d >> (2 * j + 1)) & 0x1;
            r->coeffs[16 * i + j] = a - b;
        }
    }
}
void cbd3(poly* r, const uint8_t buf[TRLWE_N / 4])//64个byte可以生成256个采样
{
    unsigned int i, j;
    uint8_t t, d;
    int8_t a, b;

    for (i = 0; i < TRLWE_N / 4; i++) { //i<64
        t = (uint8_t)buf[i];          //一次处理1byte，生成4个采样
        d = t;

        for (j = 0; j < 4; j++) {
            a = (d >> (2 * j + 0)) & 0x1;
            b = (d >> (2 * j + 1)) & 0x1;
            r->coeffs[4 * i + j] = a - b;
        }
    }
    //for (int i = 0; i < 256; i++) {
    //    if (r->coeffs[i] == 0 && i%2==0)
    //        r->coeffs[i] = 1;
    //    else {
    //        r->coeffs[i] = -1;
    //    }
    //}
}
void bin_sample(poly* r, const uint8_t buf[TRLWE_N / 8])//32个byte可以生成256个二进制{0,1}采样
{
    //unsigned int i, j;
    ////uint8_t t, d;

    //for (i = 0; i < TRLWE_N / 8; i++) { //i<32
    //    //t = (uint8_t)buf[i];          //一次处理1byte，生成8个采样
    //    //d = t;

    //    for (j = 0; j < 8; j++) {
    //        r->coeffs[8 * i + j] = ((uint8_t)buf[i] >> j) & 0x1;
    //    }
    //}
    for (int i = 0; i < 256; i++) {
        r->coeffs[i]=rand() % 2;
    }
}
//int main() {
//    struct poly P;
//    poly* p = &P;
//
//    //uint8_t buf[64] = {109,120,22,0,31,53,3,143,122,54,2,44,2,165,54,234,
//    //                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
//    //                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
//    //                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
////	uint8_t buf[10];
////	randomarray(buf, 10);
//    uint8_t buf[64];
//    randomarray(buf, 64);
//    cbd3(p, buf);
//    for (int i = 0; i < 256/4; i++) {
//        for (int j = 0; j < 4; j++) {
//            printf("%d",p->coeffs[i*4+j]);
//        }
//        printf("\n");
//        
//    }
//    return 0;
//}

