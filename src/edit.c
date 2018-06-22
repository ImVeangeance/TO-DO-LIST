#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include "function.h"

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
