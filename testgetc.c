#include <stdio.h>

int main() {
  char c;
  int Lengde = 7;
  char word[Lengde];
  int i = 0;
    {
      while (c = getchar() != '\n'){
	c = getchar();
	word[i] = c;
	i++;
	printf("\n%d[", word[i]);
      }
    }
}
