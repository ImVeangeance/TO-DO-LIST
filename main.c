#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


int Greeting();
int MenuForCreating();


int main()
{
	setlocale(LC_ALL, "Russian");
	Greeting();
	MenuForCreating();
	system("pause");
	return 0;
}

int Greeting()
{
	char NameOfUser[20];
	// 
	printf("\nЭлектронный ежедневник\n");
 	printf("Как мне к вам обращаться?\n[Используйте не более 20 символов на имя]\n"); 
	//
	scanf("%s", NameOfUser);
	printf("\n\nПриветствую тебя, ");
	printf("%s", NameOfUser);
	printf("!\n");
	return 0;
}

int MenuForCreating()
{
	char Button[3];
	while (1)
	{
		printf("Что бы вы хотели сделать?\n");
		printf("C - создать ");
		printf("E - редактировать \n");
		printf("D - удалить ");
		printf("A - добавить ");
		printf("ESC - выйти \n");
		scanf("%s", Button);
		if(!strcmp("C", Button))
		{
			//
		}
		if(!strcmp("E", Button))
		{
			//
		}
		if(!strcmp("D", Button))
		{
			//
		}
		if(!strcmp("A", Button))
		{
			//
		}
		if(!strcmp("ESC", Button))
		{
			break;
		}		
		else //условие ошибки 
		{
			//
		}
	}	
	return 0;
}













