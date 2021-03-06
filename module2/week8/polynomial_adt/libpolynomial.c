#include <stdio.h>
#include <stdlib.h>
#include "polynomial.h"

struct polynomial
{
	int degree;
	double *coefficients;
};

#define max(a,b) ((a) > (b)) ? (a) : (b)

polynomial plm_init(int degree, double *coefficients)
{
	polynomial a = malloc(sizeof(struct polynomial));
	a->degree = degree;
	a->coefficients = malloc((degree + 1) * sizeof(double));
	for(int i = 0; i <= degree; i++)
		a->coefficients[i] = coefficients[i];
	return a;
}

polynomial plm_sum(polynomial a, polynomial b)
{
	int degree = max(a->degree, b->degree);
	double *coeff = calloc(degree + 1, sizeof(double));
	
	for(int i = 0; i <= a->degree; i++)
		coeff[i] += a->coefficients[i];
	
	for(int i = 0; i <= b->degree; i++)
		coeff[i] += b->coefficients[i];
	
	polynomial c = plm_init(degree, coeff);
	free(coeff);
	
	return c;
}

polynomial plm_mul(polynomial a, polynomial b)
{
	int degree = a->degree + b->degree;
	double *coeff = calloc(degree + 1, sizeof(double));
	
	for(int i = 0; i <= a->degree; i++)
		for(int j = 0; j <= b->degree; j++)
			coeff[i+j] += a->coefficients[i] * b->coefficients[j];
	
	polynomial c = plm_init(degree, coeff);
	free(coeff);
	
	return c;
}

double plm_eval(polynomial a, double value)
{
	double total = 0;
	for(int i = 0; i <= a->degree; i++)
	{
		int pow = 1;
		for(int j = 1; j <= i; j++)
			pow *= value;

		total += a->coefficients[i] * pow;
	}

	return total;
}

void plm_print(polynomial a)
{
	for(int i = 0; i <= a->degree; i++)
	{
		if(a->coefficients[i])
		{
			printf("%+.2f", a->coefficients[i]);
			if(i >= 1) printf("x");
			if(i > 1) printf("^%d", i);
		}
	}
}

void plm_print_coefficients(polynomial a)
{
	for(int i = 0; i <= a->degree; i++)
		printf("%.2f ", a->coefficients[i]);
}

void plm_free(polynomial a)
{
	free(a->coefficients);
	free(a);
}
