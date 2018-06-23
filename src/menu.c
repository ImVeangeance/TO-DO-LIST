#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include "function.h"
FILE *database; 
FILE *buffile;

void Menu(void){

	printf("\n");
	char Helper[4];
	int delka;
	printf(" _________________________\n");
	printf("|V - View                 |\n");
	printf("|C - Create new list      |\n");
	printf("|A - Add in existing list |\n");
	printf("|D - Delete note          |\n");
	printf("|ESC - Escape             |\n");
	printf(" _________________________\n\n\n");
	printf("'help' - about notes struct\n\n");

	scanf("%s", Helper);

	if(!strcmp("help", Helper)){

	printf("\nThis programm using for keeping the notes,\n");
	printf("Example:\n");
	printf("_________________________________________________________\n");
	printf("Note: Priority:\n");
	printf("Going out with friends. 2.\n");
	printf("_________________________________________________________\n\n\n");
	printf("Press any key to continue\n");

	getch();

	system("clear");
	Menu();

	}
	else{

	if(!strcmp("ESC", Helper)){
	system("clear");
	exit(0);
	}
	else{

	switch(Helper[0]){
	case 'V':
		View(database);
		break;
	case 'C':
		CreateOrAdd(database, Helper[0]);
		break;
	case 'D':
		Print(database);
		printf("You want to delete note what number is? -");
		scanf("%d",&delka);
		Delete(delka);
		break;
	case 'A':
		CreateOrAdd(database, Helper[0]);
		break;
	default:
		system("clear");
		printf("Wrong key, input again\n\n");
		Menu();
		}
	}
}

Menu();

}
