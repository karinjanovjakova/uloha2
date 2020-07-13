#include <stdio.h>
#include <stdlib.h>
#define ELEM(M,r,c) (M->elem[(M->cols)*r+c]) 


typedef struct
{
	unsigned int rows;
	unsigned int cols;
	float *elem;
} MAT;

MAT *mat_create_with_type(unsigned int rows, unsigned int cols)
{
	MAT *mat=(MAT *)malloc(sizeof(MAT));
	if (mat==NULL)
		return NULL;
		
	mat->rows=rows;
	mat->cols=cols;
	
	mat->elem=(float *)malloc(sizeof(float)*rows*cols);
	if (mat->elem==NULL)
	{
		free(mat);
		return NULL;
	}
	
	return mat;
}
