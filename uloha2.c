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

void mat_random(MAT *mat)
{
	int i, j;
	
	for (i=0;i<mat->rows;i++)
	{
		for (j=0;j<mat->cols;j++)
		{
			ELEM(mat,i,j)=((float)rand()/(float)(RAND_MAX))*2.0 - 1.0;
		}
	}	
}

void mat_print(MAT *mat)
{
	int i, j;
	
	for (i=0;i<mat->rows;i++)
	{
		for (j=0;j<mat->cols;j++)
		{
			printf("%10.3f",ELEM(mat,i,j));
		}
		printf("\n");
	}
	printf("\n");
}




main()
{	MAT *a;
	unsigned int rows,cols;
	printf("Zadaj rozmery prvej matice:\n");
	scanf("%d %d",&rows,&cols);
	a=mat_create_with_type(rows, cols);
	mat_random(a);
	mat_print(a);
}
