#include <iostream>
#include "mainFunctions.h"
#include <windows.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>	
#include<string>
#include<vector>
using namespace std;

int randomGeneratedLettersCount = 10;
int roundsCount = 10;
int currRound = 0;
int totalPoints = 0;
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
	Clear();
	PrintMainMenu();
	char userInputIndex;
	Print("Choose index: ");
	cin >> userInputIndex;
	while (userInputIndex != '1' && userInputIndex != '2' && userInputIndex != '3' && userInputIndex != '4')
	{
		Clear();
		SetColor("red");
		cout << "Choose a correct number!" << endl;
		SetColor("white");
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

void Print(char symbol)
{
	cout << symbol;
}

void Print(int number)
{
	cout << number;
}

void SetColor(string colorName)
{
	int colorIndex = 0;
	colorIndex = GetColorIndexFromText(colorName);
	HANDLE console_color;
	console_color = GetStdHandle(
		STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(
		console_color, colorIndex);
}

int GetColorIndexFromText(string colorName)
{
	if (colorName.compare("black") == 0)
	{
		return 0;
	}
	else if (colorName.compare("red") == 0)
	{
		return 4;
	}
	else if (colorName.compare("green") == 0)
	{
		return 2;
	}
	else if (colorName.compare("white") == 0)
	{
		return 7;
	}
	else if (colorName.compare("yellowWhite") == 0)
	{
		return 11;
	}
	else if (colorName.compare("lightBlue") == 0)
	{
		return 11;
	}
	else if (colorName.compare("lightYellow") == 0)
	{
		return 14;
	}
	return 7;
}

void GetUserInput(char userInputIndex)
{
	Clear();
	switch (userInputIndex)
	{
	case '1':
		StartScrabble();
		break;
	case '2':
		OpenSettings();
		break;
	case '3':
		EnterNewWord();
		break;
	case '4':
		Close();
		break;
	default:
		break;
	}
}

void StartScrabble()
{
	currRound++;
	char* randomLetters = GetRandomLetters(randomGeneratedLettersCount);
	PrintGameInterface(totalPoints, currRound, randomLetters);
	string userWord = "";
	SetColor("lightYellow");
	cin >> userWord;
	if (CheckIsWordValid(randomLetters, userWord))
	{
		Clear();
		SetColor("green");
		Print("You found the word!!!");
		PrintNewLine();
		PrintExitMessage("Can you do it one more time? Just a second..", 3, "yellowWhite");
		totalPoints += GetLength(userWord);
	}
	if (currRound < roundsCount)
	{
		StartScrabble();
	}
	else
	{
		Clear();
		PrintLineWithSymbol(' ', 20);
		SetColor("whiteYellow");
		Print("Game over!");
		PrintNewLine();
		PrintLineWithSymbol(' ', 17);
		SetColor("lightBlue");
		Print("Your score is: ");
		Print(totalPoints);
		PrintLineWithSymbol('\n', 2);
		PrintLineWithSymbol(' ', 7);
		PrintExitMessage("Congratulations! Till the next game..", 5, "yellowWhite");
		Clear();
		OpenMainPage();
	}
}

void PrintGameInterface(int score, int currRound, char* randomLetters)
{
	Clear();
	SetColor("lightBlue");
	PrintLineWithSymbol('*', 58);
	PrintNewLine();
	PrintLineWithSymbol('*', 25);
	SetColor("white");
	Print("Scrabble");
	SetColor("lightBlue");
	PrintLineWithSymbol('*', 25);
	PrintNewLine();
	PrintLineWithSymbol('*', 58);
	SetColor("white");
	PrintLineWithSymbol('\n', 2);
	SetColor("lightBlue");
	PrintLineWithSymbol('*', 16);
	PrintNewLine();
	Print("*");
	SetColor("white");
	Print("Score: ");
	SetColor("lightYellow");
	Print(totalPoints);
	int scoreLength = GetLength(totalPoints);
	PrintLineWithSymbol(' ', 7 - scoreLength);
	SetColor("lightBlue");
	Print("*");
	PrintNewLine();
	SetColor("lightBlue");
	Print("*");
	SetColor("white");
	Print("Round: ");
	SetColor("lightYellow");
	Print(currRound);
	Print("/");
	Print(roundsCount);
	int allRoundsLength = GetLength(roundsCount);
	int currRoundsLength = GetLength(currRound);
	PrintLineWithSymbol(' ', 6 - (allRoundsLength + currRoundsLength));
	SetColor("lightBlue");
	Print("*");
	PrintNewLine();
	SetColor("lightBlue");
	PrintLineWithSymbol('*', 16);
	PrintLineWithSymbol('\n', 4);

	SetColor("white");
	PrintRandomLetters(randomLetters, randomGeneratedLettersCount);
	PrintNewLine();
	Print("Enter your word: ");
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

int GetLength(int number)
{
	int length = 0;
	if (number == 0)
	{
		return 1;
	}
	while (number > 0)
	{
		number /= 10;
		length++;
	}
}

bool Contains(char letter, char* letters, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (letter == letters[i])
		{
			letters[i] = NULL;
			return true;
		}
	}
	return false;
}

bool CheckIsWordValid(char* allowedLetters, string userWord)
{
	int index = 0;
	while (userWord[index] != '\0')
	{
		char currChar = userWord[index];
		if (!Contains(currChar, allowedLetters, randomGeneratedLettersCount))
		{
			Clear();
			SetColor("red");
			Print("You can use only the given diggits!");
			PrintNewLine();
			PrintExitMessage("Try harder the next time! The next round is coming", 3, "yellowWhite");
			return false;
		}
		index++;
	}
	if (!CheckIfDictionaryContainsWord(userWord))
	{
		Clear();
		SetColor("red");
		Print("Your word is not valid!");
		PrintNewLine();
		PrintExitMessage("More luck the next time! The next round is coming", 3, "yellowWhite");
		return false;
	}
	return true;

}

char* GetRandomLetters(int countDigits)
{
	char* randomDigits = new char[countDigits];
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	srand(time(NULL));
	for (int i = 0; i < countDigits; i++)
	{
		randomDigits[i] = letters[rand() % 26];
	}
	return randomDigits;
}

void PrintRandomLetters(char* letters, int length)
{
	Print("Your letters are: ");
	for (int i = 0; i < length; i++)
	{
		SetColor("yellowWhite");
		Print(letters[i]);
		if (i != length - 1)
		{
			SetColor("white");
			Print(" | ");
		}
	}
	SetColor("white");
}

void OpenSettings()
{
	Print("");
}

bool CheckWordIsValid(string word)
{
	int index = 0;
	while (word[index] != '\0')
	{
		char currDigit = word[index];
		if (!((currDigit >= 'a' && currDigit <= 'z') || (currDigit >= 'A' && currDigit <= 'Z')))
		{
			return false;
		}
		index++;
	}
	return true;
}

void EnterNewWord()
{
	Print("Here you can add new words to our dictionary!");
	PrintNewLine();
	Print("Enter a word to be added: ");
	string newWord = "";
	SetColor("lightYellow");
	cin >> newWord;
	SetColor("white");
	if (!CheckWordIsValid(newWord))
	{
		Clear();
		SetColor("red");
		Print("Enter a valid word!");
		SetColor("white");
		PrintNewLine();
		EnterNewWord();
	}
	if (CheckIfDictionaryContainsWord(newWord))
	{
		SetColor("green");
		Print("The dictionary already contains ");
		Print(newWord);
		Print("!");
		PrintNewLine();
		PrintExitMessage("Returning to main menu", 5, "yellowWhite");
		OpenMainPage();
	}
	else
	{
		SetColor("yellowWhite");
		Print("You got us a new word!!!");
		SetColor("white");
		PrintNewLine();
		int indexWordToBeAdded = GetIndexNewWord(newWord);
		AddWordInDictionary(newWord, indexWordToBeAdded);
		SetColor("green");
		Print("Successfully added in the dictionary!");
		PrintNewLine();
		PrintExitMessage("Returning to main menu", 5, "yellowWhite");
		OpenMainPage();
	}


}

int GetIndexNewWord(string newWord)
{
	int index = 0;
	char currWordFirstLetter;
	ToUpper(newWord);
	char newWordFirstLetter = newWord[0];

	ifstream my_file;
	my_file.open("Words.txt");

	while (!my_file.eof())
	{
		string currWord = "";
		getline(my_file, currWord);;
		currWordFirstLetter = currWord[0];
		if (currWordFirstLetter == newWordFirstLetter)
		{
			break;
		}
		index++;
	}
	my_file.close();
	return index;
}

void AddWordInDictionary(string newWord, int indexPosition)
{
	ToUpper(newWord);
	std::fstream file("Words.txt");
	std::istream_iterator<string> start(file), end;
	std::vector<string> content(start, end);
	content.insert(content.begin() + indexPosition, newWord);
	file.close();

	fstream file2;
	file2.open("Words.txt", ios_base::out);

	vector<string>::iterator itr;

	for (itr = content.begin(); itr != content.end(); itr++)
	{
		file2 << *itr << endl;
	}

	file2.close();
}

void PrintExitMessage(string message, int countRepetitions, string colorName)
{
	SetColor(colorName);
	Print(message);
	for (int i = 0; i < countRepetitions; i++)
	{
		Print("..");
		SetTimerCounting(1);
	}
	SetColor("white");
}

void ToUpper(string& str)
{
	int index = 0;
	const int indexDiffLowerUpperCase = 'A' - 'a';
	while (str[index] != '\0')
	{
		if (str[index] >= 'a' && str[index] <= 'z')
		{
			str[index] += indexDiffLowerUpperCase;
		}
		index++;
	}
}

bool CheckIfDictionaryContainsWord(string newWord)
{
	ifstream my_file;
	my_file.open("Words.txt");
	string currWord = "";
	char currWordFirstDigit;
	ToUpper(newWord);
	char newWordFirstDigit = newWord[0];
	while (!my_file.eof())
	{
		getline(my_file, currWord);
		currWordFirstDigit = currWord[0];
		if (currWordFirstDigit == newWordFirstDigit)
		{
			if (currWord.compare(newWord) == 0)
			{
				my_file.close();
				return true;
			}
		}
	}
	my_file.close();
	return false;
}

void Close()
{
	Clear();
	PrintExitMessage("Bye, bye", 5, "yellowWhite");
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

void SetTimerCounting(int countNanoseconds)
{
	using namespace std::this_thread; // sleep_for, sleep_until
	using namespace std::chrono; // nanoseconds, system_clock, seconds

	sleep_for(nanoseconds(countNanoseconds));
	sleep_until(system_clock::now() + seconds(countNanoseconds));
}