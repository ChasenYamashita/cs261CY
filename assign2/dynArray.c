/*	dynArr.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dynArray.h"

/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	
	v->size = 0;
	v->capacity = capacity;
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.		
*/
DynArr* newDynArr(int cap)
{
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);

	initDynArr(r,cap);
	return r;
}

/* Deallocate data in dynamic array. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array structure. 

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap 

	param: 	v		pointer to the dynamic array
	param:	newCap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{
	TYPE *dat;
	int g;
	assert(v);
	
	dat = (TYPE *) realloc(v->data, (sizeof(TYPE) * newCap));
	
	for(g = 0; g < v->size; g++){
		dat[g] = v->data[g];
	}
	free(v->data);
	v->data = dat;
	v->capacity = newCap;
	
	/* FIXME: You will write this function */
}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val)
{
	
		if(v->capacity <= sizeDynArr(v)){
		
			_dynArrSetCapacity(v, (sizeDynArr(v) * 2));
		}
	
	v->data[v->size] = val;
	v->size += 1;
	
	
	/* /////////// Stuff that didn't work because of oversights
	
	
	int e;
	TYPE *dat;  // Delcaring an pointer for to-be new array

	dat = (TYPE *) malloc(sizeof(TYPE) * (capacity+1));
	
	for(e = 0; e < v->capacity; e++){
		
		dat[e] = v->data[e];
	}
	
	dat[v->capacity] = val;   // Appending new value
	
	++(v->size);          // Adding to size
	++(v->capacity);      // Adding to capacity
	
	free(v->data);
    v->data = dat;    // assign v->data the new array with added element	*/
	
	/* FIXME: You will write this function */
}

/*	Get an element from the dynamic array from a specified position
	
	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/
TYPE getDynArr(DynArr *v, int pos)
{
	assert((v!=NULL) && (sizeDynArr(v) > pos) && (pos >= 0));
	return v->data[pos];
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert 
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
	assert((v!=NULL) && (sizeDynArr(v) > pos) && (pos >= 0));
	v->data[pos]=val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{

	TYPE tmp;
	assert((v!=NULL) && (sizeDynArr(v) > i) && (i>= 0)&& (sizeDynArr(v) > j) && (j>= 0));

	tmp=v->data[i];
	v->data[i]=v->data[j];
	v->data[j]=tmp;

}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void removeAtDynArr(DynArr *v, int idx){

    int k;
    for(k = idx; k < v->size; k++){
		
		v->data[k] = v->data[k+1];
		/*printf("\nDouble Check, k = %d\n", k);*/
	}

	v->size = v->size - 1;
	
	/* FIXME: You will write this function */
}

/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the 
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dynArr is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/
int isEmptyDynArr(DynArr *v)
{
	return sizeDynArr(v)==0?1:0;
}

/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/
void pushDynArr(DynArr *v, TYPE val)
{	
	assert(v!=NULL);
	
	if(v->capacity == 0)
	{
		_dynArrSetCapacity(v, v->capacity+1);
	}
	
	addDynArr(v, val);
	
	/* FIXME: You will write this function */

}

/*	Returns the element at the top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/
TYPE topDynArr(DynArr *v)
{
	assert((v!=NULL) && (sizeDynArr(v) > 0) );
	return v->data[v->size-1];
}

/* Removes the element on top of the stack 

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/
void popDynArr(DynArr *v)
{
		
	assert((v!=NULL) && (sizeDynArr(v) > 0) );
	
	if((v->size == 0) || (v->capacity == 0))
	{	
		printf("Stack is empty.\n");
		return; 	
	}

	removeAtDynArr(v, (v->size - 1));
	

	/* FIXME: You will write this function */
}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
        output: -1 if val was not found; o.w. the index of val in data
*/
int containsDynArr(DynArr *v, TYPE val)
{
	signed int found = -1, d;
	
	assert(v->data);
	
	for(d = 0; d < v->size; d++)
	{	
		if(v->data[d] == val)
		{
			found = d;
			return found;  /* returns index*/
		}

	}
	return found; /*returns -1 if not found*/
	
	/* FIXME: You will write this function */
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removeDynArr(DynArr *v, TYPE val)
{
	int e = containsDynArr(v,val);
	
	if(sizeDynArr(v) == 0){			/*removes nothing if size is 0*/
		return;	
		}
	removeAtDynArr(v, e);
	
	/* FIXME: You will write this function */	
}
