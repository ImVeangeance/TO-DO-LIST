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

void View(FILE * database){
	
	Print(database);
	getch();
	
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

void Edit(FILE *database, FILE *buffile){  

	database = fopen("database.txt","rb");
	buffile = fopen("buffile.txt","wb");
	system("CLS");
	
	int num_edit;                   
	int num = Print(database);     
	
	if(num == 0)
		return;
	
	printf("Input the number of note for deleting\n");
	scanf("%d", &num_edit);	
	while(1){
	    
		if(num_edit > 0 && num_edit <= num)
			break;
		printf("Wrong number, input again\n");
		scanf("%d", &num_edit);
	}
	////
}

void Delete(FILE *database, FILE *buffile){
	
	database = fopen("database.txt","rb");
	buffile = fopen("buffile.txt","wb");
	system("CLS");
	
	int num_del;                   
	int num = Print(database);     
	
	if(num == 0)
		return;
	
	printf("Input the number of note for deleting\n");
	scanf("%d", &num_del);
	
	while(1){
	    
		if(num_del > 0 && num_del <= num)
			break;
		printf("Wrong number, input again\n");
		scanf("%d", &num_del);
	}
	
    Note* buff = InitNote();
	fread(buff, sizeof(Note), 1, database);
	
	int i = 1;
	while(!feof(database)){
		
		if(i != num_del)
		    fwrite(buff, sizeof(Note), 1, buffile);
		    
		fread(buff, sizeof(Note), 1, database);
		i++;
	}
	
	free(buff);
	fclose(database);
    fclose(buffile);
	
    Copy(database, buffile);   
}



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
		
		system("CLS");
		Menu();
   
    }
    else{

		if(!strcmp("ESC", Helper)){
			system("CLS");
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
				    system("CLS");
				    printf("Wrong key, input again\n\n");
		            Menu();
		    }		
		}	
	}
	
	system("CLS");
    Menu();

}
