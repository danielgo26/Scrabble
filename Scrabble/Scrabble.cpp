#include <iostream>
#include "mainFunctions.h"
#include <windows.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>	
using namespace std;


int main()
{
	StartGame();
}

void StartGame()
{
	HideConsole(false);
	Clear();
	OpenMainPage();
}

void OpenMainPage()
{
	PrintMainMenu();
	int userInputIndex = 0;
	Print("Choose index: ");
	cin >> userInputIndex;
	while (userInputIndex != 1 && userInputIndex != 2 && userInputIndex != 3 && userInputIndex != 4)
	{
		Clear();
		SetColor(4);
		cout << "Choose a correct number!" << endl;
		SetColor(7);
		PrintMainMenu();
		Print("Choose index: ");
		cin >> userInputIndex;
	}

	GetUserInput(userInputIndex);
}

void Clear()
{
	system("cls");
}

void PrintMainMenu()
{
	PrintLineWithSymbol('*', 7);
	Print("-Menu-");
	PrintLineWithSymbol('*', 7);
	PrintNewLine();
	Print("1. Start new game");
	PrintNewLine();
	Print("2. Settings");
	PrintNewLine();
	Print("3. Add a new word");
	PrintNewLine();
	Print("4. Close");
	PrintNewLine();
	PrintLineWithSymbol('*', 20);
	PrintNewLine();
}

void PrintLineWithSymbol(char symbol, int countRepetitions)
{
	for (int i = 0; i < countRepetitions; i++)
	{
		cout << symbol;
	}
}

void PrintNewLine()
{
	cout << endl;
}

void Print(string text)
{
	cout << text;
}

void SetColor(int colorIndex)
{
	HANDLE console_color;
	console_color = GetStdHandle(
		STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(
		console_color, colorIndex);
}

void GetUserInput(int userInputIndex)
{
	switch (userInputIndex)
	{
	case 1:
		StartScrabble();
		break;
	case 2:
		OpenSettings();
		break;
	case 3:
		EnterNewWord();
		break;
	case 4:
		Close();
		break;
	default:
		break;
	}
}

void StartScrabble()
{

}

void OpenSettings()
{

}

void EnterNewWord()
{
	Clear();
	Print("Here you can add new words to our dictionary!");
	PrintNewLine();
	Print("Enter a word to be added: ");
	string newWord = "";
	cin >> newWord;
	if (CheckIfDictionaryContainsWord(newWord))
	{
		Print("The dictionary already contains ");
		Print(newWord);
	}
	else
	{
		Print("You got us a new word!!!");
	}


}

bool CheckIfDictionaryContainsWord(string newWord)
{
	fstream my_file;
	my_file.open("Words", ios::out);
	if (my_file)
	{
		string a;
		getline(my_file, a);
		Print(a);
		my_file.close();
	}
	return false;
}

bool AreEqual(string a, string b)
{
	int lengthStr1 = GetLength(a);
	int lengthStr2 = GetLength(b);
	if (lengthStr1 != lengthStr2)
	{
		return false;
	}
	int counter = 0;
	while (a[counter] != '\0' && b[counter] != '\0')
	{
		if (a[counter] != b[counter])
		{
			return false;
		}
		counter++;
	}
	return true;
}

int GetLength(string str)
{
	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return length;
}

void Close()
{
	for (int i = 0; i < 5; i++)
	{
		Clear();
		Print("Bye, bye");
		PrintLineWithSymbol('.',i*2);
		SetTimerExiting();
	}

	HideConsole(true);
}

void HideConsole(bool hasToBeHided)
{
	WCHAR path[260];

	GetModuleFileName(NULL, path, 260);

	HWND console = FindWindow(L"ConsoleWindowClass", path);
	if (hasToBeHided)
	{
		ShowWindow(console, SW_HIDE); // hides the window
	}
	else
	{
		ShowWindow(console, SW_SHOW); // shows the window
	}
}

void SetTimerExiting()
{
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	sleep_for(nanoseconds(1));
	sleep_until(system_clock::now() + seconds(1));
}