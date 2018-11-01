/* CS261- HW1 - Program4.c*/
/* Name: Chasen Yamashita
 * Date: 4/6/18
 * Solution description: The sort() function from Program3 has been edited to compare character values of both first and last initials. It will only switch if it confirms that both character values of the subsequent element are smaller than the first (ASCI). 
 
 The first for loop organizes the initials' first values alphabetically, and the second for loop compares second initials (switching CY with CA, for example).
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

void swap(char *cur1, char *cur2, char *next1, char *next2){
	
	char swap;
	
	swap = *next1;
	*next1 = *cur1;
	*cur1 = swap;
	
	swap = *next2;
	*next2 = *cur2;
	*cur2 = swap;

}

void sort(struct student* students, int n){
     /*Sort n students based on their initials*/    
	 
		 int cur, next;
	 
	 for(cur = 0; cur < n; cur++){
		 for(next = 0+cur; next < n; next++){
		   if((students[cur].initials[0] > students[next].initials[0])){
			   
			   swap(&students[cur].initials[0], &students[cur].initials[1], &students[next].initials[0], &students[next].initials[1]);
			   
			}
			else{}
		}
	}	

    for(cur = 0; cur < n; cur++){
		 for(next = 0+cur; next < n; next++){
		   if((students[cur].initials[0] == students[next].initials[0]) && (students[cur].initials[1] > students[next].initials[1])){
			   
			  swap(&students[cur].initials[0], &students[cur].initials[1], &students[next].initials[0], &students[next].initials[1]);
			   
			}
			else{}
		}
	}	 	
}

int main(){
	
	srand(time(NULL));
	
    /*Declare an integer n and assign it a value.*/
	
	int n, f, c, dec;
	
	printf("Input an integer: ");
	scanf("%d", &n);
	printf("\n");
	
	if(n == 0){return 0;}
	    
    /*Allocate memory for n students using malloc.*/
	
    struct student *students;
	students = malloc(n * sizeof(struct student));
    
    /*Generate random IDs and scores for the n students, using rand().*/
	
	for(f = 0; f < n; f++ ){
		for(c = 0; c < 2; c++){
		  dec = rand() % 26 + 65;
		  students[f].initials[c] = (char) dec;
		  
	    } 
		students[f].score = rand() % 101;
    }
    
    /*Print the contents of the array of n students.*/
	
	printf("Unsorted Data:\n");
	for(f = 0; f < n; f++ ){
	
	printf("%d. %c%c \n", f+1, students[f].initials[0], students[f].initials[1]);	
	}

    /*Pass this array along with n to the sort() function*/
	
	sort(students, n);
    
    /*Print the contents of the array of n students.*/
	
    printf("\n Sorted Data:\n");
    for(f = 0; f < n; f++){
	
	printf("%d. %c%c \n", f+1, students[f].initials[0], students[f].initials[1]);	
	}
	
	free(students);
	
	return 0;
}


			   /*wap = students[next].initials[0];
			   students[next].initials[0] = students[cur].initials[0];
			   students[cur].initials[0] = swap;
			   
			   swap = students[next].initials[1];
			   students[next].initials[1] = students[cur].initials[1];
			   students[cur].initials[1] = swap;*/