/* CS261- HW1 - Program3.c*/
/* Name: Chasen Yamashita
 * Date: 4/6/18
 * Solution description: A Bubble sort I (sort of) assembled compares each array int with the subsequent element. It swaps only if some number below it has a lower value, so as to make the array ascending from 0 to n.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the array of integeres of length n*/ 

	 int swap, cur, next;
	 
	 for(cur = 0; cur < n; cur++){
		 for(next = 0+cur; next < n; next++){
		   if(number[cur] > number[next]){
			   swap = number[next];
			   number[next] = number[cur];
			   number[cur] = swap;
		   }
		   else{}
		 }
	 }
     	 
}

int main(){
	
	srand(time(NULL));
	int ar=0;
	
    /*Declare an integer n and assign it a value of 20.*/
	
	int n;
	printf("Input an integer: ");
	scanf("%d", &n);
	printf("\n");
	if(n == 0){return 0;}
    
    /*Allocate memory for an array of n integers using malloc.*/
    
	int *array;
	array = malloc(n * sizeof(int));
	
    /*Fill this array with random numbers, using rand().*/
    /*Print the contents of the array.*/
	
	printf("Unsorted Data:\n");
	for(ar = 0; ar < n; ar++){
	   array[ar] = rand() % 101;
	   printf("%d\n", array[ar]);
	}

    /*Pass this array along with n to the sort() function of part a.*/
	
	sort(array, n);
    
    /*Print the contents of the array.*/  
    printf("\n Sorted Data:\n");
	for(ar = 0; ar < n; ar++){
	   printf("%d\n", array[ar]);
	}	
	
	free(array);
    
    return 0;
}
