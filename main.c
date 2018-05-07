#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


int Greeting();
void Menu();


int main()
{
	
	setlocale(LC_ALL, "Russian");
	Greeting();
	Menu();
	system("pause"); // Need to del in last commit
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

void Menu()
{
	char Button[3];
	printf("\n\n");
	while (1)
	{
		printf("____________________________\n");
		printf("Что бы вы хотели сделать?\n");
		printf("L - просмотр текущих заметок\n");
		printf("C - создать ");
		printf("E - редактировать \n");
		printf("D - удалить ");
		printf("A - добавить ");
		printf("ESC - выйти \n");
		scanf("%s", Button);
		if(!strcmp("L", Button))
		{
			//
		}
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
		if((!strcmp("ESC", Button)) || (!strcmp("Esc", Button)) || (!strcmp("esc", Button)))
		{
			break;
			system("cls");
		}		
		else //условие ошибки 
		{
			//
		}
		system("cls");	
	}	
}













