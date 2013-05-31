#ifndef _EMD_H
#define _EMD_H
/*
    emd.h

    Last update: 3/24/98

    An implementation of the Earth Movers Distance.
    Based of the solution for the Transportation problem as described in
    "Introduction to Mathematical Programming" by F. S. Hillier and
    G. J. Lieberman, McGraw-Hill, 1990.

    Copyright (C) 1998 Yossi Rubner
    Computer Science Department, Stanford University
    E-Mail: rubner@cs.stanford.edu   URL: http://vision.stanford.edu/~rubner
*/

#include <string.h>
#include <stdlib.h>

/* DEFINITIONS */
#define MAX_SIG_SIZE   100
#define MAX_ITERATIONS 500
// #define INFINITY       1e20
#define EPSILON        1e-6f

typedef struct
{
	float L, a, b;
} feature_t;

class signature_t
{
public:
	int n;                /* Number of features in the signature */
	feature_t *Features;  /* Pointer to the features vector */
	float *Weights;       /* Pointer to the weights of the features */

	signature_t(char * signature): n(0), Weights(new float[MAX_SIG_SIZE]), Features(new feature_t[MAX_SIG_SIZE])
	{
		char *token = strtok(signature, "[] ,");

		while (token != NULL) {
			Weights[n] = atof(token);
			Features[n].L = atof(strtok(NULL, "[] ,"));
			Features[n].a = atof(strtok(NULL, "[] ,"));
			Features[n].b = atof(strtok(NULL, "[] ,"));
			token = strtok(NULL, "[] ,");
			n++;
		}
	};

	virtual void print() {
		printf("n=%i, ", n);
		for (int i=0; i<n; ++i) {
			printf("%f (L=%f, a=%f, b=%f) ", Weights[i], Features[i].L, Features[i].a, Features[i].b);
		}
		printf("\n");
	};

	virtual ~signature_t() {
		delete[] Features;
		delete[] Weights;
	}
};


// float __attribute__((used)) compute_emd(const char * const jsonSignature1, const char * const jsonSignature2);


#endif

