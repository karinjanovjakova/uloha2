#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
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

char mat_multiply(MAT *a,MAT *b,MAT *c)
{
	int i,j,k;
	float prvok=0.0;
	if ((a->cols!=b->rows)||(a==NULL)||(b==NULL))
	{
		return 0;
	} 
	for (i=0;i<a->rows;i++)
	{
		for (j=0;j<b->cols;j++)
		{
			for (k=0;k<a->cols;k++)
			{
				prvok=prvok+ELEM(a,i,k)*ELEM(b,k,j);
			}
			ELEM(c,i,j)=prvok;
			prvok=0.0;
		}
	}
}

void mat_destroy (MAT *mat)
{
	free(mat->elem);
	free(mat);
}

void mat_unit(MAT *mat)
{
	int i,j;
	
	for (i=0;i<mat->rows;i++)
	{
		for (j=0;j<mat->cols;j++)
		{
			if (i==j)
				ELEM(mat,i,j)=1.0;
			else
				ELEM(mat,i,j)=0.0;
		}
	}
}

main()
{
	srand(time(0));
	MAT *a, *b, *c;
	unsigned int rows,cols;
	printf("Zadaj rozmery prvej matice:\n");
	scanf("%d %d",&rows,&cols);
	a=mat_create_with_type(rows, cols);
	//mat_unit(a);
	mat_random(a);
	mat_print(a);
	
	printf("Zadaj rozmery druhej matice:\n");
	scanf("%d %d",&rows,&cols);
	b=mat_create_with_type(rows, cols);
	mat_random(b);
	mat_print(b);
	
	c=mat_create_with_type(a->rows, b->cols);
	mat_multiply(a,b,c);
	if (a->cols==b->rows)
	mat_print(c);
	
	
	mat_destroy(a);
	mat_destroy(b);
	mat_destroy(c);
}
