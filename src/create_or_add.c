#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include "function.h"

Note * InitNote(void){
	
	Note* note = (Note*)malloc(sizeof(Note));
	int i;
	for(i = 0; i < 144; i++) {
		note->memo[i] = 0;
	}
	
	note->priority = 0;
	
	return note;
}


void CreateOrAdd(FILE * database, char state){   
 
	if(state == 'C')
		database = fopen("database.txt","wb");
	else
		database = fopen("database.txt","ab"); 
	
	system("CLS");	
    printf("New note:\n\n\n");
    
	char ch = 0;
	while(ch != 'y'){
		
		Note* note = InitNote();

		printf("Input the note:\n");
		scanf("%142s", note->memo);

		printf("Input a priority from 3 (important) to 1 (inconsiderable)\n");
		
		unsigned char pr = getch();
		while(1){
			
			if((pr - '0') >= 1 && (pr - '0') <= 3){
				note->priority = (pr - '0');
			    break;
			}	
			printf("Wrong priority, input again\n");
			pr = getch();
		}
	    
	    printf("%s\n", note->memo);
	    printf("%d\n", note->priority);
	    
	    fwrite(note, sizeof(Note), 1, database);   

	    printf("Finish?  y/n  ");
	    printf("\n");

		ch = getch();
	    free(note);
		system("CLS");
	}
	
	fclose(database);	
}








