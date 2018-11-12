#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
        if(access(argv[1], F_OK) == 0)
        {
                printf("Le fichier existe\n");

                if(access(argv[1], W_OK) == 0)
                {
                        printf("Le fichier possede les droits d'ecriture\nChangement du guid, nouveau guid 1001\n");
                        chown(argv[1], -1, 1001);
                }

                else
                        printf("Le fichier ne possede pas les droits d'ecriture\n");

                if(access(argv[1], R_OK) == 0)
                        printf("Le fichier possede les droits de lecture\n");

                else
                        printf("Le fichier ne possede pas les droits de lecture\n");

                if(access(argv[1], X_OK) == 0)
                        printf("Le fichier possede les droits d'execution\n");

                else
                        printf("Le fichier ne possede pas les droits d'execution\n");

        }

        else
                printf("Le fichier n'existe pas\n");

        return 0;
}
