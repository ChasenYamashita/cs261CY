#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "hashMap.h"

char* getWord(FILE *file); /* prototype */


/****************************************/

int main (int argc, const char * argv[]) {
    const char* filename;
    struct hashMap hashTable;
    struct hashLink *temp;
    char *tempK;
    int tableSize = 1000;
    FILE *fileptr;
    int *occ;
    int i;
    struct timeval stop, start; /* variables for measuring execution time */

    /* you can manually type in your
     filename and path in command line arguments 
     */
    if(argc == 2)
        filename = argv[1]; /*specify your input text file here */
    else
        filename = "input.txt"; 
    
    printf("opening file: %s\n", filename);
    
    gettimeofday(&start, NULL);
   
	
    /*... concordance code goes here ... */

	fileptr = fopen(filename, "r");

	initMap(&hashTable, tableSize);
	
	while(tempK != NULL){
		tempK = getWord(fileptr);
		if (tempK != NULL) {
			insertMap(&hashTable, tempK, 1);
		}
		else {
		}
	}
	
    /* FIX ME */

    /* - Initialize the Hash table
       - In the loop 
           - Read a word from the file using getWord() 
           - Add the word to Hash table
           - Update concordance
        - End the loop
    */

    /* Close the file */
    fclose(fileptr);

    /* Print out the resulting Hash table and concordance */
    for(i=0;i < hashTable.tableSize; i++){
	temp = hashTable.table[i];
			
	while(temp!=0){
	   printf("%s:%d\n", temp->key,temp->value);
	   temp=temp->next;
			
	}
    }


    gettimeofday(&stop, NULL);
    printf("\nYour execution time for concordance is %f microseconds\n", (double) (stop.tv_usec - start.tv_usec));


    printf("Table emptyBuckets = %d\n",emptyBuckets(&hashTable));
    printf("Table size = %d\n",sizeMap(&hashTable));
    printf("Table capacity = %d\n",capacityMap(&hashTable));
    printf("Table load = %f\n",tableLoad(&hashTable));

	freeMap(&hashTable);
    return 0;
}


/* ****************************
 getWord takes a FILE pointer and returns a string which was
 the next word in the file. Words are defined (by this function) to be
 characters or numbers separated by periods, spaces, or newlines.
 
 When there are no more words in the input file this function will return NULL.
 
 getWord will malloc some memory for the char* it returns. 
 Free this memory when you no longer need it.
*/
char* getWord(FILE *file)
{
	
	int length = 0;
	int maxLength = 16;
	char character;
    
	char* word = (char*)malloc(sizeof(char) * maxLength);
	assert(word != NULL);
    
	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   character == 39) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}
    
	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	return word;
}
