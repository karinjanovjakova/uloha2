#include<stdio.h>
#include<stdlib.h>

void retazec (int pocet, char * r)
{
	int i; 
    char pole[37]="abcdefghijklmnopqrstuvwxyz0123456789";
    for (i = 0; i < pocet-1; ++i) 
	{
        r[i] = pole[rand() % (sizeof(pole) - 1)];
    }
    r[pocet-1] = 0;   
}

int main() 
{
	int i;
	char * sm;
	char ret[10];
	sm=ret;
	retazec(10,sm);
	for (i=0;i<10;i++)
	{
		printf("%c ", sm[i]);
	}
}
