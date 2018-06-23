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
    printf("New note:\n");
		
		Note* note = InitNote();

		printf("[144 symbols only]\n Input the note:\n");
		fgets(note->memo, 144, stdin);
		fgets(note->memo, 144, stdin);

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









