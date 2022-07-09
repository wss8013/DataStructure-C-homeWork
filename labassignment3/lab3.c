// Shasha Wang
// wang.shas@northeastern.edu

#include <stdio.h>
#define MAX 8

int main()
{
    int arr[MAX] = {80,35,56,45,10,90,12,67};
    int i,j,temp;
    for(i = 1 ;i < MAX;i++){
      temp = arr[i];
      j = i - 1;
      // Move elements one position ahead which are greater than temp 
      while(j >= 0 && arr[j] > temp){
	arr[j+1] = arr[j];
        j = j - 1;
      }
      arr[j+1] = temp;
    }
    printf("Sorted list in ascending order: \n");
    for(i = 0;i < MAX;i++){
      printf("%d \n",arr[i]);
    }
    return 0;
}
