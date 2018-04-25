#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

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
	// необходима проверка на кол-во символов, что если много - то попросить по-короче
	cout << "Электронный ежедневник" << endl << "Как мне к вам обращаться?" << endl; 
	// при первом заходе он запросит имя, при послежущих он будет спрашивать имя, 
	//если что - менять предлагать
	cin >> NameOfUser;
	cout << endl << endl << "Приветствую тебя, " << NameOfUser << "!" << endl;
	return 0;
}

int MenuForCreating()
{
	char Button[3];
	while (1)
	{
		cout << "Что бы вы хотели сделать?" << endl;
		cout << "C - создать ";
		cout << "E - редактировать " << endl;
		cout << "D - удалить ";
		cout << "A - добавить ";
		cout << "ESC - выйти " << endl;
		cin >> Button;
/*		if(!strcmp("C", Button))
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
			break();
		else //условие ошибки 
		{
			//
*/
	}	
	return 0;
}













