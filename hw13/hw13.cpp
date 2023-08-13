#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

const int SIZEWORD = 5;
const int DATELENGTH = 9;
const char USERDATA[] = "metadata.txt";
const char WORDSBASE[] = "words.txt";

int randomValue();
int getDailyWord();
int getDate();
void saveProgress(const int data, const char fileName[] = USERDATA);
int loadProgress(const char fileName[] = USERDATA);
bool getWord(const int line, char* hiddenWord, const char fileName[] = WORDSBASE);
bool checkWord(char* userWord, char* hiddenWord, char* result);

int main()
{
    std::srand(std::time(nullptr));
    
    bool gameStart = false;
    bool randomGame = false;
    int userChoice{};    
    int tries{ 0 };
    char result[] = { "*****" };
    char userWord[] = {"*****"};
    char hiddenWord[] = { "*****" };
    
    while (true)
    {
        if (gameStart)
        {
            std::cout << std::endl << "RESULT : " << result << std::endl;
            std::cout << "ENTER  : ";
            std::cin >> userWord;

            tries++;
            
            if (checkWord(userWord, hiddenWord, result))
            {                
                std::cout << std::endl << "That's right!" << std::endl;
                std::cout << "You made " << tries << " tries" << std::endl << std::endl;

                if (randomGame)
                {
                    randomGame = !randomGame;
                }
                else 
                {
                    saveProgress(getDate());
                }
                                
                int i = 0;
                while (result[i] != '\0')
                {
                    result[i] = '*';
                    i++;
                }

                gameStart = !gameStart;                
                tries = 0;
            }
        }
        else 
        {
            std::cout << "1 - Wordle of the day" << std::endl;
            std::cout << "2 - Random Wordle" << std::endl;
            std::cout << "0 - Exit" << std::endl;
            std::cout << "Enter: ";
            std::cin >> userChoice;            
            
            if (userChoice == 0)
            {
                std::cout << std::endl << "Bye bye. Come back tomorrow for a new word!" << std::endl;
                break;
            }
            else if (userChoice == 1)
            {                
                if (getDate() == loadProgress())
                {
                    std::cout << std::endl << "Already found! Come back tommorow!" << std::endl << std::endl;
                } 
                else
                {   
                    if (getWord(getDailyWord(), hiddenWord))
                    {                        
                        gameStart = !gameStart;
                    } 
                    else 
                    {
                        break;
                    }
                    
                }
            }
            else if (userChoice == 2)
            {   
                if (getWord(randomValue(), hiddenWord))
                {
                    gameStart = !gameStart;
                    randomGame = !randomGame;
                }
                else
                {
                    break;
                }
            }
        }        
        
    }
}

int randomValue()
{
    const int GeneratingRange = 366;
    return std::rand() % GeneratingRange + 1;
}

int getDailyWord()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    return now->tm_yday;
}

int getDate()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    int days = static_cast<int>(now->tm_mday) * 1000000;
    int month = (static_cast<int>(now->tm_mon) + 1) * 10000;
    int year = static_cast<int>(now->tm_year) + 1900;

    return days + month + year;
}

void saveProgress(const int data, const char fileName[])
{
    std::fstream file;
    file.open(fileName, std::ios::out);
    file << data;
    file.close();
}

int loadProgress(const char fileName[])
{
    std::fstream file;
    file.open(fileName, std::ios::in);
    int result{ -1 };

    if (file)
    {
        const unsigned int MaxLineSize = DATELENGTH;
        char word[MaxLineSize]{};

        while (!file.eof())
        {
            file.getline(word, MaxLineSize, '\n');
            result = std::atoi(word);
        }
    }

    file.close();
    return result;
}

bool getWord(const int line, char* hiddenWord, const char fileName[]) {
    std::fstream file;

    file.open(fileName, std::ios::in);

    const unsigned int MaxLineSize = 6;
    char word[MaxLineSize]{};

    if (!file)
    {
        std::cout << "File not found!\n";

        return false;
    }
    else
    {
        int currentLine = 0;

        while (!file.eof())
        {
            currentLine++;
            file.getline(word, MaxLineSize, '\n');
            if (currentLine == line) break;
        }

        int i = 0;
        while (*hiddenWord != '\0')
        {
            *hiddenWord = word[i];
            hiddenWord++;
            i++;
        }
    }

    file.close();

    return true;
}

bool checkWord(char* userWord, char* hiddenWord, char* result)
{
    int guessingLetter[SIZEWORD] = {};
    int i = 0;    
    int finds = 0;

    while (*hiddenWord != '\0')
    {
        if (tolower(*userWord) == *hiddenWord)
        {
            *result = toupper(*hiddenWord);
            guessingLetter[i] = '*';
            *userWord = '!';
            finds++;
        }
        else
        {
            guessingLetter[i] = *hiddenWord;
            *result = '*';
        }

        userWord++;
        result++;
        hiddenWord++;
        i++;
    }

    if (finds == SIZEWORD)
        return true;

    userWord -= SIZEWORD;
    result -= SIZEWORD;
            
    for (int i = 0; i < SIZEWORD; i++)
    {   
        for (int j = 0; j < SIZEWORD; j++)
        {
            if (tolower(*userWord) == guessingLetter[j])
            {                    
                *result = guessingLetter[j];
                guessingLetter[j] = '*';
            }                
        }               
        
        userWord++;
        result++;
    }  

    return false;
}