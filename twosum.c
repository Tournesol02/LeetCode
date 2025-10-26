#include <stdio.h>

void main(){
  
  int nums1[4] = {2,7,11,15};
  int target1 = 9;
  int nums2[3] = {3,2,4};
  int target2 = 6;
  int nums3[2] = {3,3};
  int target3 = 6;
  
  int TwoSum(int tablength, int tab[4], int Target){
    int k=0;
    int i,j = 0;
    while(k==0){
      if (tab[i] + tab[j++] == Target) {
	  k=1;
	}
      if (tab[i] + tab[j++] != Target) {
	  j++;
	}
      else {
	i++;
      }
    }
      printf("\n%d tab[", & i);
      printf("%d] et tab[", & j);
      printf("%d=Target:", & Target);
  }
 TwoSum(4, nums1, target1)
}
