#include <stdio.h>
#include "/home/brage/Skole/3ANNEE/LangageC/LeetCode/AddTwoNumbers/CreateList.h"
#include <time.h>

#define CONDITION 1 //Donne une liste chainée avec le nombre 1, nombre 2 et la somme des deux nombres à la fin
#define ALEATOIRE 1 //Tu veux utiliser la fonction MakeList de repertoire CreateList.h
#define LEETCODE 0 // 1 vaut TRUE et tous les autres valeurs vaut zero

//Pour compiler le fichier: gcc AddTwoNumbers.c CreateList.h -o AddTwoNumbers

/* Words from the author.
   
Cette programme utilise des librairies hors le langage C.
J'ai donc créé une librarie moi-même qui contient la fonction MakeList and AddPtrFin
Voila, la structure d'une pointeur de valeur val et qui peut pointer vers une autre pointer
Cette struct est definie dans le fichier CreateList.h qui est un header. Il faut compiler le header avec cette
programme pour pouvoir utiliser la librarie CreateList.h.

 struct ListNode {
   int val;
   struct ListNode * next;
 };

 J'ai mis dans le debut de programme des statiques qui y sont pendant l'execution.
 CONDITION verifie si la fonction AddTwoNumbers va renvoyer une liste chainée avec les deux nombres entrées et
 la somme des deux. Fait le calcul beaucoup plus facile vers le fin, et on peut afficher les deux nombres
 entrées et la somme des deux dans la fin pour n'importe quel liste chainée d'entrée.
 ALEATOIRE est une condition qui verifie si les listes chainées qui sont aux inputs sont aleatoires ou
 pre-definie dans le main.
 LEETCODE est la condition qui renvoye le pointeur en envers comme le sujet le demande. Pas trop lisible.
 
*/

int LenNumber(int Number){
  if (Number == 0){
    return 1;
  }
  int teller = 0;
  while (Number != 0){
    Number = Number / 10; //Comme c'est un integer alors au cas d'un decimal ca vaut 0
    teller += 1;
  }
  return teller;
}

int PowerFunction(int base, int exponent){
  int result = 1;
  for (int i=0; i<exponent; i++){
    result *= base;
  }
  return result;
}

void FreeFunction(struct ListNode * ptr){
  while (ptr != NULL){
    struct ListNode * tmp = ptr;
    ptr = ptr->next;
    free(tmp);
  }
}

struct ListNode* AddTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

  //Faire une liste contenant les chiffres de la premiere nombre
  int compteur1 = 0;
  int tmp1[32]; //Safe bet for a long linked list
  while (l1 != NULL){
    tmp1[compteur1] = l1->val;
    l1 = l1->next;
    compteur1 += 1;
  }
  int Num1[compteur1];
  int nummer1 = 0;
  for (int i=0; i<compteur1;i++){
    Num1[i] = tmp1[compteur1 - 1 - i]; //Correct use of compteur1 and incrementation
    nummer1 = nummer1 + Num1[i] * PowerFunction(10,i);
  }

  //Faire une liste contenant les chifres de la deuxieme nombre
 
  int tmp2[32]; 
  int compteur2 = 0;
  while (l2 != NULL){
    tmp2[compteur2] = l2->val;
    l2 = l2->next;
    compteur2 += 1; //Compteur sort toujours avec une chiffre plus grand que le nombre reel
  }
  int Num2[compteur2];
  int nummer2 = 0;
  for (int i=0; i<compteur2;i++){
    Num2[i] = tmp2[compteur2 - 1 - i]; 
    nummer2 = nummer2 + Num2[i] * PowerFunction(10,i); //nummer2 est le second nombre de pointer
    
  }
  long long sum = nummer1 + nummer2;

  //Il faut creer une linked list
  int LenList = LenNumber(sum);
  struct ListNode * ptr = malloc(sizeof(struct ListNode));
  if (LEETCODE){ //Renvoie une liste chaine à l'envers, comme demandé par l'exercice
  for (int i=LenList; i>0;i--){
    int tempVal = (sum / (int)PowerFunction(10,LenList- i)) % 10;
    struct ListNode * NewElement = malloc(sizeof(struct ListNode));
    NewElement->val = tempVal;
    NewElement->next = NULL;
    if (ptr != NULL){
      struct ListNode * tmp = ptr;
      while (tmp->next != NULL){
	tmp = tmp->next;
      }
      tmp->next=NewElement;
    }
    else{
      ptr=NewElement; //Essayer de retourne deux pointers qui aient les valeurs de nummer1 et nummer2
    }
  }
  }

  else{
    for (int i=0; i<LenList;i++){
    int tempVal = (sum / (int)PowerFunction(10,LenList - 1 - i)) % 10;
    struct ListNode * NewElement = malloc(sizeof(struct ListNode));
    NewElement->val = tempVal;
    NewElement->next = NULL;
    if (ptr != NULL){
      struct ListNode * tmp = ptr;
      while (tmp->next != NULL){
	tmp = tmp->next;
      }
      tmp->next=NewElement;
    }
    else{
      ptr=NewElement; //Essayer de retourne deux pointers qui aient les valeurs de nummer1 et nummer2
    }
    }
  }
  ptr = ptr ->next;
  if (CONDITION){
    struct ListNode * tmp = ptr;
    while (tmp->next!=NULL){
      tmp=tmp->next;
    }
    struct ListNode * PointNr1 = malloc(sizeof(struct ListNode));
    struct ListNode * PointNr2 = malloc(sizeof(struct ListNode));
    struct ListNode * SummePointer = malloc(sizeof(struct ListNode));
    PointNr1->val = nummer1;
    PointNr2->val = nummer2;
    SummePointer->val = sum;
    tmp->next = PointNr1;
    PointNr1->next = PointNr2;
    PointNr2->next = SummePointer;
    SummePointer->next = NULL;
    return ptr;
  }
  return ptr; 
}

int main()
{
  int nombre1,nombre2,summen;
  srand(time(NULL));
  
  struct ListNode * ptr1 = malloc(sizeof(struct ListNode));
  struct ListNode * ptr4 = malloc(sizeof(struct ListNode));
  struct ListNode * Output = malloc(sizeof(struct ListNode));
  
  if (!ALEATOIRE){
    struct ListNode * ptr2 = malloc(sizeof(struct ListNode));
    struct ListNode * ptr3 = malloc(sizeof(struct ListNode));
    struct ListNode * ptr5 = malloc(sizeof(struct ListNode));
    struct ListNode * ptr6 = malloc(sizeof(struct ListNode));
    
    ptr1 -> val = 5;
    ptr2 -> val = 4;
    ptr3 -> val = 2;
    
    ptr1 -> next = ptr2;
    ptr2 -> next = ptr3;
    ptr3 -> next = NULL;
    
    ptr4 -> val = 6;
    ptr5 -> val = 0;
    ptr6 -> val = 9;
    
    ptr4 -> next = ptr5;
    ptr5 -> next = ptr6;
    ptr6 -> next = NULL;
    
    Output = AddTwoNumbers(ptr1,ptr4);
  }
  else{
    ptr1 = MakeList(3);
    ptr4 = MakeList(3);
    Output = AddTwoNumbers(ptr1,ptr4);
  }

  if (LEETCODE){
    int compteur = 0;
    int tmpList[32];
    struct ListNode * ptr1Tmp = ptr1;
    while (ptr1Tmp != NULL){
      tmpList[compteur] = ptr1Tmp->val;
      ptr1Tmp = ptr1Tmp->next;
      compteur += 1;
    }
    printf("[ ");
    for (int i=compteur;i>0;i--){
      printf("%d-> ",tmpList[i-1]);
	}
    printf("NULL ]\n");
    
    compteur = 0;
    while (ptr4 != NULL){
      tmpList[compteur] = ptr4->val;
      ptr4 = ptr4->next;
      compteur += 1;
    }
    printf("\n[ ");
    for (int i=compteur;i>0;i--){
      printf("%d-> ",tmpList[i-1]);
	}
    printf("NULL ]\n");
    if (CONDITION){
    printf("\n[");
    while (Output->next->next->next != NULL){
      printf("%d-> ",Output->val);
      Output = Output->next;
    }
    printf("NULL ]\n");
    }
    else{
        printf("\n[");
    while (Output!= NULL){
      printf("%d-> ",Output->val);
      Output = Output->next;
    }
    printf("NULL ]\n");
    }
  }

  else{
    
    if (CONDITION){
      struct ListNode * OutputTmp = Output;
      while (OutputTmp->next->next->next != NULL){
	OutputTmp = OutputTmp->next;
      }
      int nombre1 = OutputTmp->val;
      int nombre2 = OutputTmp->next->val;
      int summen = OutputTmp->next->next->val;
  
      printf("[");
      while (ptr1 != NULL){
	printf("%d-> ", ptr1->val);
	ptr1 = ptr1->next;
      }
      printf("NULL ]\n");
      printf("Nombre 1 vaut: %d\n\n",nombre1);
      
      printf("[");
      while (ptr4 != NULL){
	printf("%d-> ", ptr4->val);
	ptr4 = ptr4->next;
      }
      printf("NULL ]\n");
      printf("Nombre 2 vaut: %d\n\n",nombre2);
      
      printf("[");
      while (Output->next->next->next != NULL){
	printf("%d-> ",Output->val);
	Output = Output->next;
      }
      printf("NULL ]\n");
      printf("Output vaut: %d \n\n",summen);
      printf("Après des calculs longues, on a trouvé que la somme vaut:\n%d + %d = %d\n", nombre1,nombre2,summen);
    }
    
    else{
      printf("[");
      while (ptr1 != NULL){
	printf("%d-> ", ptr1->val);
	ptr1 = ptr1->next;
      }
      printf("NULL ]\n");
      
      printf("[");
      while (ptr4 != NULL){
	printf("%d-> ", ptr4->val);
	ptr4 = ptr4->next;
      }
      printf("NULL ]\n");
      
      printf("[");
      while (Output != NULL){
	printf("%d-> ",Output->val);
	Output = Output->next;
      }
      printf("NULL ]\n");
      printf("Vous avez mis CONDITION à 0 donc, on vous montre pas la somme ni les valeurs des nombres entrées\n");
    }
  }
  
  //On free tous nos liste chainées
  FreeFunction(ptr1);
  FreeFunction(ptr4);
  FreeFunction(Output);
  
  return 0;
}
