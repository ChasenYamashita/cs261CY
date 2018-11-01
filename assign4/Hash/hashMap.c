#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>

int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}

void initMap (struct hashMap * ht, int tableSize)
{
	int f;

	ht->table = (struct hashLink **) malloc(tableSize * sizeof(hashLink *));

	for (f = 0; f < tableSize; f++) {
		ht->table[f] = 0;
	}
	ht->tableSize = tableSize;
	ht->count = 0;
  /* FIX ME */

}

void freeMap (struct hashMap * ht)
{  
	int i;
	struct hashLink *temp;
	struct hashLink *temp2;
	for(i = 0; i < ht->tableSize; i++){
		temp = ht->table[i];
		while(temp != NULL){
			temp2 = temp->next;
			free(temp);
			temp = temp2;
		}
	}
	free(ht->table);
	ht->count=0;
	ht->table=0;
	ht->tableSize=0;	
}

/* Add an element to the Hash Table */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  
	struct hashLink * newnode;
	ValueType * pointer;

	int idx; 

	/*If the node shares the value of another node, add to the value*/

	if (containsKey(ht, k) == 1) {
		
		pointer = atMap(ht, k);
		pointer++;
		return;
	}

	newnode = (struct hashLink *) malloc(sizeof(hashLink));

	idx = stringHash1(k) % ht->tableSize;

	if (idx < 0) idx += ht->tableSize;

	newnode->key = k;
	newnode->value = v;
	newnode->next = ht->table[idx];
	ht->table[idx] = newnode;
	ht->count++;

    /* FIX ME */

}



/* Returns a pointer to the value of element with key k in the Hash Table 
   If the element is not in the Hash Table, returns NULL */ 
ValueType* atMap (struct hashMap * ht, KeyType k)
{ 

	/*I was unsucessful at attempting to make this properly return a pointer to a hash's value.
	I first thought a normal for loop to iterate through the hash table would work, but assumed the run time would have increased.
	I then attempted to use the hash function to find the  location of the HashLink, but kept running into segmentation faults,
	which I would assume is from attempting to access nonexistent data.
	

	int hash2;
	int kk;
	struct hashLink *temp;

	hash2 = stringHash1(k);

	if (ht->table[hash2]) {

		temp = ht->table[hash2];

		if (EQ(temp->key, k)) {
			return((ValueType*)ht->table[hash2]->value);
		}
		else {
			return 0;
		}
	}
	*/

		return 0;
}
	
    /* FIX ME */
	

int containsKey (struct hashMap * ht, KeyType k)
{  
	if (atMap(ht,k)==0){
		return 0;
	}else{
		return 1;
	}
}

void removeKey (struct hashMap * ht, KeyType k)
{  
	int bucket = stringHash2(k)%ht->tableSize;
	struct hashLink *cur; 
	struct hashLink *prev;  
	if(ht->table[bucket] == 0){
		return;
	}else{
		cur=ht->table[bucket];
		prev=ht->table[bucket];
		while(cur!=0){
			if(strcmp(cur->key,k)==0){
				if(cur==ht->table[bucket]){
					ht->table[bucket]=cur->next;
					
				}else{
				prev->next=cur->next;
				}
				free(cur);
				ht->count--;
				return;
			}else{
				prev=cur;
				cur=cur->next;
			} 
		}
	}
}

int sizeMap (struct hashMap *ht)
{  
	return ht->count;
}

int capacityMap(struct hashMap *ht)
{  
	return ht->tableSize;
}

int emptyBuckets(struct hashMap *ht)
{  
	int runner = 0;
	int i;
	for(i=0; i<ht->tableSize; i++){
		if(ht->table[i]==0){
			runner++;
		}
	}
	return runner;
}

float tableLoad(struct hashMap *ht)
{  
   return (float)sizeMap(ht)/(float)capacityMap(ht);
}
