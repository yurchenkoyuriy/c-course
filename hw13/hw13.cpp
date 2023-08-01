#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

const int SIZEWORD = 5;
const char USERDATA[] = "metadata.txt";
const char WORDSBASE[] = "words.txt";

int randomValue();
int getDayOfYear();
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
                    saveProgress(getDayOfYear());
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
                int today = getDayOfYear();
                if (today == loadProgress())
                {
                    std::cout << std::endl << "Already found! Come back tommorow!" << std::endl << std::endl;
                } 
                else
                {   
                    if (getWord(today, hiddenWord))
                    {
                        std::cout << hiddenWord;
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
                    std::cout << hiddenWord;
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

int getDayOfYear()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    return now->tm_yday;
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
        const unsigned int MaxLineSize = 4;
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
    int iteration = 0;
    int finds = 0;
    while (iteration < SIZEWORD)
    {           
        
        hiddenWord += iteration;
        if (tolower(*userWord) == *hiddenWord)
        {
            finds++;
            *result = toupper(*hiddenWord);            
            hiddenWord -= iteration;
        }
        else
        {
            hiddenWord -= iteration;
            *result = '*';
            for (int i = 0; i < SIZEWORD; i++)
            {
                if (tolower(*userWord) == *hiddenWord)
                {
                    if (iteration == i)
                    {
                        finds++;
                        *result = toupper(*hiddenWord);
                    } 
                    else 
                    {
                        *result = *hiddenWord;
                    }                    
                }
                hiddenWord++;
            }
            hiddenWord -= SIZEWORD;
        }
        userWord++;        
        result++;
        iteration++;
    }  

    return (finds == SIZEWORD) ? true : false;
}