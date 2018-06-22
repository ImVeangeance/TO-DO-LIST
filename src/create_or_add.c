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
	
	system("clear");	
    printf("New note:\n\n\n");
		
		Note* note = InitNote();

		printf("Input the note: (When you enter a note with more than one word, use '_' to separate the words.)\n");
		scanf("%142s", note->memo);

		int pr;
		while(1){
			printf("Input a priority from 3 (important) to 1 (inconsiderable)\n");
			scanf("%d", &pr);
			if((pr) >= 1 && (pr) <= 3){
				note->priority = pr;
			    break;
			}
			else	
				printf("Wrong priority, input again\n");
			
		}
	    
	    printf("%s\n", note->memo);
	    printf("%d\n", note->priority);
	    
	    fwrite(note, sizeof(Note), 1, database);   
		getch();
	        free(note);
		system("clear");

	fclose(database);	
}









