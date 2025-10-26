#include <stdio.h>
#include <string.h> 

void main(){
  char test1[5] = {'H', 'A', 'R', 'R', 'Y'};
  char test2[6] = {'H', 'A', 'N', 'N', 'A', 'H'};

  int palindrom(char chaine[]){
    char * Debut;
    char * Fin;
    int Retour = 1;
    Debut = chaine;
    Fin = chaine + strlen ( chaine ) - 1;


    while (Retour && Debut < Fin){   /* Si le pointeur Debut depasse le pointeur Fin, on sort */
      if( *Debut++ != *Fin-- ){ /* Regarde si le contenu du pointeur prochaine de Debut est different du contenu
				   du pointeur avant de Fin */
	Retour = 0;
	return Retour; 
      }
    }
  }

 
  if(palindrom(test1)){
    /*  printf("\nRegarde si la chaine test1 est un pal");
	printf("\nAlors test1 est un palindrome"); */
    /* for(int i=0; i<5;i++){
      printf("%s", & test1[i]);
      } */
  }
  else{
    printf("Pas un pal test1\n%s", test1);
  }
  
  printf("\nRegarde si la chaine test2 est un pal");
  printf("\n%s ", test2);
  if(palindrom(test2)){
    printf("\nAlors test2 est un palindrome.\n");
      printf("[ ");
      for(int i=0; i<5;i++){
    printf("%s ", & test2[i]);
  }
      printf(" ]"); 
  }
}
