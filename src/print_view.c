#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include "function.h"

int Print(FILE *database){
	
	database = fopen("database.txt","rb");   
	Note* note = InitNote();
	
	int i = 1;
	fread(note, sizeof(Note), 1, database);
	
	while (!feof(database)){
		
	    printf("№ %i.\nNote - %sPriority - %i\n\n", i, note->memo, note->priority);
	    fread(note, sizeof(Note), 1, database);
	    i++;
	    
	}
	
	return i - 1;
}


void View(FILE * database){
	
	Print(database);
	getch();
	
}
