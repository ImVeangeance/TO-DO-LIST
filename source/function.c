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

int Print(FILE *database){
	
	system("CLS");
	database = fopen("database.txt","rb");   
	Note* note = InitNote();
	
	int i = 1;
	fread(note, sizeof(Note), 1, database);
	
	while (!feof(database)){
		
		printf("%i.   %s\n   %i\n\n", i, note->memo, note->priority);
	    fread(note, sizeof(Note), 1, database);
	    i++;
	    
	}
	
	return i - 1;
}
