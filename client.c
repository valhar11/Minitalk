#include <stdio.h>
#include <stdlib.h>

void afficheBinaire(int);
int puissance(int a , int b);

int puissance(int a , int b)
{
	if(b==0)
	{
	    return 1 ;
	}
	int a1 = a ;
	for(int i = 1 ; i<b ; i++ )
	    a *= a1;
	return a ;
}

int main (int argc, char **argv)
{
	
	int n = atoi(argv[1]);
 
    for(int i = 0 ; n != 0 ; i++)
    {
 
        n += power(10,i) * (n % 2);
        n /= 2 ;
 
    }

	printf("%d", n);

}