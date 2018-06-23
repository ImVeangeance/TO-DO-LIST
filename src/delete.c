#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
#include "function.h"
FILE *database;
FILE *buffile;

void Delete(int delka){
	
	database = fopen("database.txt","rb");
	buffile = fopen("buffile.txt","wb");
	system("CLS");
	
	int num_del;                   
	int num = Print(database);     
	
	if(num == 0)
		return;

	num_del=delka;
	
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

