#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <pwd.h>

int main(int argc, char *argv[])
{
	int fd, userUID, min=1, max=199, alea, i, length; 
	ssize_t written;	// variables to know if the writing is well passed (write returns -1 in case of error)
	size_t size;		
	time_t now = time(NULL);
	struct tm *t = localtime(&now);		// variable to retrieve the local date and time of the system
	char *userName = getenv("LOGNAME");	// recover the user's login
	struct passwd *getinfo;		// variable to retrieve user info
	char passwd[200] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890<>?,.;/:§!*µ&éèà@-+#";	// string of characters to generate the random password
	char mdp[10];	// will be the random password

	srand(time(NULL));
	
	// use the getpwnam function to retrieve the user's info whose name was retrieved earlier
	getinfo=getpwnam(userName);

	// open and create the file in read / write mode in which we will write with the argument passed as parameters
	fd = open(argv[1], O_RDWR|O_CREAT);

	// we get the size of the character string of the mdp
	length = strlen(passwd);

	// we want a size 10
	for(i=0; i<10; i++)
	{	
		mdp[i] = passwd[rand()%length]; // we set a random character of passwd
	}

	mdp[9] = '\0'; // put the last character of the password to \ 0 so that the string can be read

	// creation of the buffer
	char buffer[200];

	//write in the buffer what will be in the file
	sprintf(buffer,"<geewy_date> %d %d %d </geewy_date>\n<geewy_hour> %dh %dmin %ds</geewy_hour>\n<geewy_user_name> %s </geewy_user_name>\n<geewy_user_UID> %d </geewy_user_UID>\n<geewy_password> %s </geewy_password>\n", t->tm_mday, t->tm_mon, t->tm_year+1900, t->tm_hour, t->tm_min, t->tm_sec, getinfo->pw_name, getinfo->pw_uid, mdp);
	
	// retrieve buffer size
	size = strlen(buffer);

	// test the existence of the file open and create with open ()
	if(fd==-1)
	{	
		printf("Le fichier n'existe pas\n");
		return -1;
	}
	
	// if it exists
	else
	{	
		// w write in the file
		written = write(fd, &buffer, size);

		// we test the writing in the file
		if(written != size)
			printf("Erreur lors de l'ecriture dans le fichier\n");

		else
			fchmod(fd, S_IRUSR);	// if the write was done, we change the rights read-only by the owner of the file
	}
	
	close(fd); 	// closing file
	
	return 0;
}
