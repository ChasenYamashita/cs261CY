/* bag2set.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynArray.h"


/* Converts the input bag into a set using dynamic arrays 
	param: 	da -- pointer to a bag 	
	return value: void
        result: after exiting the function da points to a set 		
*/
void bag2set(struct DynArr *da)
{
	TYPE *set; // array holding the elements to make up the set
	TYPE elmt; // holds current element of da
	int iter, k=0, n, idx;
	double check = 0.0;
	
	set = malloc(sizeDynArr(da) * sizeof(TYPE));
	
	for(iter = 0; iter < sizeDynArr(da); iter++)
	{	
		elmt = getDynArr(da, iter);			/*Get element from da*/
		
		if(containsDynArr(set, elmt) == -1) /*check to see if set has it, add if it doesn't*/
		{
			set[k] = elmt;
			k++;
		}
		
		removeDynArr(da, elmt);			/*removes the elmt from da after*/
		
	}
			   
							   
	free(set); /*cleans up set*/
	
	
	
     /* FIX ME */

}

/* An example how to test your bag2set() */
int main(int argc, char* argv[]){

	int i;
        struct DynArr da;  /* bag */
        
        initDynArr(&da, 100);
        da.size = 10;
        da.data[0] = 1.3;
	for (i=1;i<da.size;i++){
	    da.data[i] = 1.2;
	 }

        printf("Bag:\n\n");
	for (i=0;i<da.size;i++){
          printf("%g  \n", da.data[i]);
        }
        
        printf("\n\n\n");
        printf("Set:\n\n");
        bag2set(&da);
	for (i=0;i<da.size;i++){
          printf("%g ", da.data[i]);
					
        }
        printf("\n");
        
		freeDynArr(&da);
		
	return 0;	
}

