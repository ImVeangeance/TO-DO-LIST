#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


void Greeting();
void Menu();
int Looking();
int Editing();
int Creating();
int Deleting();
//int Adding(); - ?? nado li


int main()
{
	
	setlocale(LC_ALL, "Russian");
	Greeting();
	Menu();
	Creating();
	system("pause"); // Need to del in last commit
	return 0;
}

void Greeting()
{
	char NameOfUser[20];
	// 
	printf("\nЭлектронный ежедневник\n");
 	printf("Как мне к вам обращаться?\n[Используйте не более 20 символов на имя]\n"); 
	scanf("%s", NameOfUser);
	//Create the namesaver;
	printf("\n\nПриветствую тебя, ");
	printf("%s", NameOfUser);
	printf("!\n");
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
	printf("A - добавить дело |\n");
	printf("|ESC - выйти                   |\n");
	printf(" _____________________________\n\n\n");
	printf("'Help' - команда для вывода меню\n\n");
	scanf("%s", Helper);
	if((!strcmp("help", Helper)) || (!strcmp("helP", Helper)) || (!strcmp("heLp", Helper)) 
	|| (!strcmp("heLP", Helper)) || (!strcmp("hElp", Helper)) || (!strcmp("hElP", Helper))
	|| (!strcmp("hELp", Helper)) || (!strcmp("hElP", Helper)) || (!strcmp("Help", Helper))
	|| (!strcmp("HelP", Helper)) || (!strcmp("HeLp", Helper)) || (!strcmp("HeLP", Helper)) 		
	|| (!strcmp("HElp", Helper)) || (!strcmp("HElP", Helper)) || (!strcmp("HELp", Helper))			 		
    || (!strcmp("HELP", Helper)))
	{
		printf("\nЭта программа предназначена для хранения ваших заметок,\n"); 
        printf("действия над которыми Вы будете совершать в процессе.\n");
		printf("Примеры заметки для этой программы:\n");
		printf("_________________________________________________________\n");
		printf("Дата(при желании), Заметка/Действие  , Приоритет:\n");
		printf("08.08.2018       , Встреча с друзьями, Высокий приоритет.\n");
		printf("_________________________________________________________\n\n\n");
		//Describe about all(not ended)
		printf("Напишите 'хорошо' для продолжения\n");
		char Beginer[6];
		do
		{
			scanf("%s", Beginer);
			system("clear");
			Menu();
		} while(!strcmp("хорошо", Beginer));
	}
     else 
     {
        if(!strcmp("L", Helper))
	{
		//Looking();
	}
	if(!strcmp("C", Helper))
	{
		//Creating();
	}
	if(!strcmp("E", Helper))
	{
		//Editing();
	}
	if(!strcmp("D", Helper))
	{
		//Deleting():
	}
	if(!strcmp("A", Helper))
	{
		//Adding();
	}
	if((!strcmp("ESC", Helper)) || (!strcmp("Esc", Helper)) || (!strcmp("esc", Helper)))
	{
		system("clear");
		system("break");
	}		
	else //условие ошибки 
	{
		system("clear");
		Menu();
	}
     }
//	system("clear");	
}

int Creating()
{
	int count=1;
	int i=0;
	struct spis
	{ 
		int number;
		char data[25];
		char memo[140];
		int priority;
	};
	struct spis note[count];

	for(i=0;i<count;i++)
	{
		note[i].number=i++;
		printf("Номер дела - №%d\n", note[i].number);

		printf("Введите дату в удобном для вас формате:\n");
		scanf("%s\n", note[i].data);

		printf("Заметка:\n");
		scanf("%s\n", note[i].memo);

		printf("Введите приоритет заметки - [0;2], от большего к меньшему:\n");
		scanf("%d\n", note[i].priority);
	}
	//
}











