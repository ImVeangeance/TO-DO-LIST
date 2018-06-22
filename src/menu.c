#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include "function.h"

void Menu(void){
	
	printf("\n");
	char Helper[4];
	
	printf(" ___________________________\n");
	printf("|V - View                   |\n");
	printf("|C - Create new list        |\n");
	printf("|A - Add in existing list   |\n");
	printf("|D - Delete note            |\n");
	printf("|E - Edit note              |\n");
	printf("|ESC - Escape               |\n");
	printf(" ___________________________\n\n\n");
	printf("'help' - about notes struct\n\n");
	
	scanf("%s", Helper);
	
	if(!strcmp("help", Helper)){
		
		printf("\nThis programm using for keeping the notes,\n"); 
		printf("Example:\n");
		printf("_________________________________________________________\n");
		printf("Note,     Priority::\n");
		printf("Going out with friends,     2.\n");
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
			    case 'E':
				    Edit(database, buffile);
				    break;
			    case 'D':
				    Delete(database, buffile);
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
