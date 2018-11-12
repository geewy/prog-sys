#include <stdio.h>
#include <stdlib.h>

int main(char **envp[])
{
	int i=0, nb_Var;

	while(&envp[i]!=NULL)
	{
		nb_Var = i+1;
		printf(“%d\n, &envp[i]);
		i++;
	}
	getchar();
	return nb_Var;
}
