#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include "function.h"

void Copy(FILE *database, FILE *buffile){
	
    database = fopen("database.txt","wb");
	buffile = fopen("buffile.txt","rb");
	
	Note* buff = InitNote();
	fread(buff, sizeof(Note), 1, buffile);
	while(!feof(buffile)){
		
		fwrite(buff, sizeof(Note), 1, database);
		fread(buff, sizeof(Note), 1, buffile);  
	}
	
	free(buff);
	fclose(database);
    fclose(buffile);
}
