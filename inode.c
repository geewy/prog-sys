#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
        struct stat sb;

        if(stat(argv[1], &sb) == -1)
        {
                perror("stat");
                return -1;
        }

        else
        {
                printf("Numéro inode : %1d\n", (long)sb.st_ino);
                printf("Date de création du fichier: %s", ctime(&sb.st_mtime));
        }

        return 0;
}
