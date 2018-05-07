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
	printf("\n\n");
	char Helper[4];
	printf(" ______________________________\n");
	printf("|L - просмотр текущих заметок  |\n");
	printf("|C - создать ");
	printf("E - редактировать |\n");
	printf("|D - удалить ");
	printf("A - добавить      |\n");
	printf("|ESC - выйти                   |\n");
	printf(" _____________________________\n\n\n");
	printf("'Help' - команда для вывода меню\n\n");
	scanf("%s", Helper);
	if(!strcmp("L", Helper))
	{
		//
	}
	if(!strcmp("C", Helper))
	{
			//Creating();
	}
	if(!strcmp("E", Helper))
	{
		//
	}
	if(!strcmp("D", Helper))
	{
		//
	}
	if(!strcmp("A", Helper))
	{
		//
	}
	if((!strcmp("ESC", Helper)) || (!strcmp("Esc", Helper)) || (!strcmp("esc", Helper)))
	{
		system("clear");
//		break;
	}		
	else //условие ошибки 
	{
		system("clear");
		Menu();
	}
	if((!strcmp("help", Helper)) || (!strcmp("helP", Helper)) || (!strcmp("heLp", Helper)) 
	|| (!strcmp("heLP", Helper)) || (!strcmp("hElp", Helper)) || (!strcmp("hElP", Helper))
	|| (!strcmp("hELp", Helper)) || (!strcmp("hElP", Helper)) || (!strcmp("Help", Helper))
	|| (!strcmp("HelP", Helper)) || (!strcmp("HeLp", Helper)) || (!strcmp("HeLP", Helper)) 		
	|| (!strcmp("HElp", Helper)) || (!strcmp("HElP", Helper)) || (!strcmp("HELp", Helper))			 		|| (!strcmp("HELP", Helper))) // Help
	{
		//Description about programm	
	}
	system("clear");	
}













