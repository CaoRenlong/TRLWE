#ifndef POLY_H
#define POLY_H
#include<stdio.h>
#include<stdint.h>
struct poly{
	int16_t coeffs[256];
};
struct poly_4 {
	int16_t coeffs[4];
};
void poly_init(poly* r);
void poly_4_init(poly_4* r);
void poly_add(poly* r, const poly* a, const poly* b);
void poly_sub(poly* r, const poly* a, const poly* b);
void poly_mul(poly* r, const poly* a, const poly* b);
void toy_poly_mul(poly_4* r, const poly_4* a, const poly_4* b);
void coeff_center(poly* a, uint16_t t);
void toy_poly_mul_center(poly_4* r, const poly_4* a, const poly_4* b);
void coeff_center_poly4(poly_4* a, uint16_t t);
void poly_mul_center(poly* r, const poly* a, const poly* b);
#endif
