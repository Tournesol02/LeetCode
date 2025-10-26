#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Make a function that takes in length of a linked list and assigns a random value each node


 struct ListNode {
   int val;
   struct ListNode * next;
 };


//faire une fonction qui cree une liste chainée
struct ListNode * AddPtrFin(struct ListNode * ptr, int val){

  struct ListNode * NewElement = malloc(sizeof(struct ListNode)); //Creer un nouvel element qu'on souhaite ajouter dans le fin
  NewElement->val=val;
  NewElement->next=NULL;
  
  if (ptr != NULL){
    struct ListNode * tmp = ptr;
    while (tmp->next != NULL){
      tmp = tmp->next;
    }
    tmp->next=NewElement;
  }
  else{
    ptr=NewElement;
  }
  return ptr; //Retourne la nouvelle liste enchainée
}
//Creer une liste chainé des valeurs aleatoires
struct ListNode * MakeList(int LongeurListe){
  struct ListNode * Debut = malloc(sizeof(struct ListNode));
  int r = rand() % 9;
  Debut->val = r;
  Debut->next = NULL;
  for (int i=0;i<LongeurListe-1;i++){
    int nummer = rand() % 9;
    AddPtrFin(Debut,nummer);
  }
  return Debut;
}
  
  

