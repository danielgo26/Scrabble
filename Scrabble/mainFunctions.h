/**
*
* Solution to course project Scrabble
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Daniel Yordanov
* @idnumber 3MI0600149
* @compiler Visual Studio Compiler
*
* <?????????????? ?? ?????>
*
*/
void StartGame();
void OpenMainPage();
void PrintMainMenu();
void PrintLineWithSymbol(char symbol, int countRepetitions);
void PrintNewLine();
void Print(std :: string text);
void Print(char symbol);
void SetColor(std :: string colorName);
void GetUserInput(std :: string userInputIndex);
void StartScrabble();
void OpenSettings();
void EnterNewWord();
void PrintExitMessage(std :: string message, int countRepetitions, std :: string colorName);
bool CheckIfDictionaryContainsWord(std :: string newWord);
void Close();
void Clear();
void HideConsole(bool hasToBeHided);
void SetTimerCounting(int countNanoseconds);
void ToUpper(std :: string& str);
void AddWordInDictionary(std :: string newWord, int indexPosition);
int GetIndexNewWord(std :: string newWord);
int GetColorIndexFromText(std :: string colorName);
bool CheckWordIsValid(std :: string word);
char* GetRandomLetters(int countDigits);
void PrintRandomLetters(char* letters, int length);
bool CheckIsWordValid(char* allowedLetters, std :: string userWord);
bool Contains(char letter, char* letters, int length);
int GetLength(std :: string str);
int GetLength(int number);
void PrintGameInterface(int score, int currRound, char* randomLetters);
void PrintSettingsInterface();
void OpenChangeRoundsMenu();
void OpenChangeLettersMenu();
bool IsValidNumber(std :: string str);
int ConvertToInt(std :: string str);
