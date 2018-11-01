/* CS261- HW1 - Program2.c*/
/* Name: Chasen Yamashita
 * Date: 4/7/18
 * Solution description: Standard C Dynamic Memory allocation is used in this program. An array of a struct is declared and allocated memory, and its contents are accessed in other functions it's referenced in. After using the struct's (randomly generated) data, the allocated memory is freed.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	 struct student *array;
     array = malloc(10 * sizeof(struct student));
     /*return the pointer*/
	 return array;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
	
	int dec, n, c;
	
	for(n = 0; n < 10; n++ ){
		for(c = 0; c < 2; c++){
		  dec = rand() % 26 + 65;
		  students[n].initials[c] = (char) dec;
		  
	    } 
		students[n].score = rand() % 101;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
	
        int n;

	for(n = 0; n < 10; n++ ){
	
	printf("%d. %c%c  %d\n", n+1, students[n].initials[0], students[n].initials[1], students[n].score);	
		}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	 int min = 100, max = 0, avg = 0, n;

	 for(n = 0; n < 10; n++){
		 if(students[n].score > max){
			 max = students[n].score;
		 }
		 
		 if(students[n].score < min){
			 min = students[n].score;
		 }
		 
		 avg = avg + students[n].score;
	 }
	 avg = avg/10;
	 printf("Minimum Score: %d\n Maximum Score: %d\n Average Score: %d\n", min, max, avg);
     
}

void deallocate(struct student* stud){
	
     /*Deallocate memory from stud*/
	 free(stud);
}

int main(){
	
	srand (time(NULL));
	
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
