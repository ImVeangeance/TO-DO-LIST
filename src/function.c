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

	printf("Input the cell for editing\n");
	printf(" ________________________\n");
	printf("|      P - priority     |\n");
	printf("|      N - note         |\n");
	printf("|_______________________|\n\n");
	char ch = getch();
	while(1){
		
		if(ch == 'P' || ch == 'N')
			break;
		printf("Wrong cell-name, input again\n");
		ch = getch();
	}
	
	
    Note* buff = InitNote();
	fread(buff, sizeof(Note), 1, database);
	
	int i = 1;
	while(!feof(database)){
		
		if(i == num_edit){
			
		    int j;
			unsigned char pr;
			printf("Input new info\n");
			switch(ch){

			    case 'N': for(j = 0; j < 144; j++){
		                       buff->memo[j] = 0;
	                      }
						  scanf("%142s", buff->memo);
						  break;
						 
				case 'P': pr = getch();
		                  while(1){
			                  if((pr - '0') >= 1 && (pr - '0') <= 3){
				                  buff->priority = (pr - '0');
			                      break;
			                  }	
			                  printf("Wrong priority, input again\n");
			                  pr = getch();
		                  }
						  break;
			}
		}
		
	    fwrite(buff, sizeof(Note), 1, buffile);        		
		fread(buff, sizeof(Note), 1, database);
		i++;
	}
	
	free(buff);
	fclose(database);
    fclose(buffile);
	
    Copy(database, buffile);   
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




