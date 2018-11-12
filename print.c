#include <stdio.h>
#include <stdlib.h>

/********************Function cmpt1********************
 Count the number of words in a string
 input: char * = pointer to the string
 output: int = number of words in the sentence
****************************************************/
int cmpt1(char *c)
{
        int i = 0, cmpt = 0;

        // as long as we are not at the end of the string
        while(c[i] != '\0')
        {
                if(c[i] == ' ') // if we have a space we just finished a word
                {
                        cmpt++;
                        i++;
                }

                else // otherwise the word continuous
                        i++;

        }

        cmpt++; // add the last word of the string
        return cmpt;
}


/*********************Function cmpt2*********************
 Look for the longest word in a chain of characters and 
 returns the number of characters
 input: char * = pointer to the string
 output: int = number of characters of the longest word
*******************************************************/
int cmpt2(char *c)
{
        int i = 0, motActuel = 0, taille = 0;

        // as long as we are not at the end of the string
        while(c[i]!='\0')
        {
                if(c[i] != ' ')
                {
                        motActuel++; // we increment the size of the current word until we reach a space

                        if(taille < motActuel && c[i]!='.') // if the size of the current word is greater than the size of the word before,
                                                            // the size of the longest word becomes the size of the current word
                                taille = motActuel;

                        i++;
                }

                else // if we have a space we are at a new word, the size of the current word is 0
                {
                        i++;
                        motActuel = 0;
                }
        }

        return taille;
}

/****************Fonction affichage*******************
 Display the words in the table below others
 input: char ** = double pointer on the board
        int = number of words in the table
 exit: no car void
****************************************************/
void affichage(char** tab, int nb_mot)
{
        int i = 0;

        for(i=0; i < nb_mot; i++)
                printf("%s\n", tab[i]);
}

int main(int argc, char **argv[])
{
        char *sentence=NULL;
        char **words=NULL;
        size_t sentenceTaille = 0;
        int i=0, j=0, k=0, nbMot=0, taille=0;

        // we ask the user to enter a sentence that we retrieve in a secure way
        printf("Veuillez saisir une phrase\n");
        getline(&sentence, &sentenceTaille, stdin);

        // we initialize the variables according to the values found thanks to the functions according to the string of character recovered
        nbMot = cmpt1(sentence);
        taille = cmpt2(sentence);

        // dynamically allocate the words array[nbMot][taille]
        words=malloc(nbMot*sizeof(*words));
        for(i=0; i<nbMot ; i++)
                words[i]=malloc(taille*sizeof(char*));
        
        do 
        {
                if(sentence[i]!=' ')
                        words[j][k++] = sentence[i];
              
                else
                {
                      words[j++][k]='\0';
                      k=0;
              }
              
        }while(sentence[i++]!='\0');
        
        // we display the word table obtained
        affichage(words, nbMot);
        
        return 0;
}                                                                                                                                                                                            1,1          Haut
