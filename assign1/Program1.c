/* CS261- HW1 - Program1.c*/
/* Name: Chasen Yamashita
 *  Date: 4/7/18
 *  Solution description: The return value is different because x and y were passed by reference, and dereferenced in foo() to change their values. 
  z was passed by value rather than reference, and the returned value of foo() reflects this */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){

printf("foo called \n");

    /* Increment a */
    (*a)++;

    /* Decrement  b */
    (*b)--;

    /* Assign a-b to c */
    c = ((*a)-(*b));

    /* Return c */
	return c;
}

int main(){

   srand (time(NULL));

    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = rand() % 10, y = rand() % 10, z = rand() % 10 , n = 0;

    /* Print the values of x, y and z */
    printf("x = %d \n y = %d \n z = %d \n", x, y, z);

    /* Call foo() appropriately, passing x,y,z as parameters */
    n = foo(&x, &y, z);   

    /* Print the values of x, y and z */
    printf("x = %d \n y = %d \n z = %d \n", x, y, z);

    /* Print the value returned by foo */
    printf("n = %d \n", n);

    /* Is the return value different than the value of z?  Why? */
    return 0;

    /* The return value is different because x and y were passed by reference, 
      and dereferenced in foo() to change their values. z was passed by value 
      rather than reference, and the returned value of foo() reflects this. */
}
    
    
