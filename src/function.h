#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#ifndef function_h_
#define function_h_
#include <stdio.h>

typedef struct Note{
	
	char memo[144];
    int priority;
		
}Note;

FILE *buffile;
FILE *database;

Note* InitNote(void);
int Print(FILE *database);
void View(FILE * database);
void CreateOrAdd(FILE *database, char state);
void Copy(FILE *database, FILE *buffile);
void Edit(FILE *database, FILE *buffile);
void Delete(FILE *database, FILE *buffile, int delka);
void Menu(void);

#endif
