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
	char ret[10];
	srand(time(0));
	retazec(10, (char *)ret );
	for (i=0;i<10;i++)
	{
		printf("%c ", ret[i]);
	}
}
