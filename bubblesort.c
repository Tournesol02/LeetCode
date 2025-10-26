#include <stdio.h>

int main(){

  int tab[5] = {3,1,6,2,4};
  int sizetab =sizeof(tab)/sizeof(tab[0]);
  printf("\nLongeur de tableu vaut: %d", sizetab);
  printf("\n[");
  for(int i=0; i < sizetab; i++){
	 printf("%d ",tab[i]);
  }
  printf("]\n");
  int bytte = 1;
  int j;
  while( bytte !=0) { 
	bytte=0;
	for(int l=0;l < sizetab-1;l++){
	  if (tab[l] > tab[l+1]) {
	    j=tab[l];
	    tab[l]=tab[l+1];
	    tab[l+1]=j; 
	    bytte++;
	  }
	}
    }
  printf("[");
  for(int k=0; k<sizetab; k++){
    printf("%d ",tab[k]);
}
  printf("]\n");
    
  }
