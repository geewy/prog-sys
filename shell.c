#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int nb_enVar;
	
	nb_enVar = system(“printenv | wc -l’’) ;
	printf(“%d\n’’, nb_enVar);

	return nb_enVar ;
}
