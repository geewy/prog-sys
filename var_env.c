#include <stdio.h>
#include <stdlib.h>
void main(void)
{
	// allocation of variables
	char *work, *langue, *log ;
	// retrieve the value of current values ​​using gentenv
	work=getenv(“HOME”) ;
	langue= getenv(“LANG”) ;
	log= getenv(“LOGNAME”) ;
	// display variables
	printf(“Home Directory :%s\nLangue : %s\nLogin : %s\n’’, work, langue, log) ;
}
