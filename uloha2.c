#include <stdio.h>
#include <stdlib.h>
#define ELEM(M,r,c) (M->elem[(M->cols)*r+c])

typedef struct
{
	unsigned int rows;
	unsigned int cols;
	float *elem;
} MAT;

