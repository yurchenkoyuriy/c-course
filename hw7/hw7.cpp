#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ctype.h>

int main()
{    
    std::srand(std::time(nullptr));
    const int GeneratingRange = 50;
    const float pinta_to_liter = 0.56826240812;
    bool gameStart = false;

    int user_choice{};
    int goal_number{};
    int tries{ 0 };
    int best_tries{ 999 };
    int total_pints{};

    std::cout << "WELCOME TO SUPER GAME - DRUNK LARRY!" << std::endl;
    std::cout << "TRY TO GUESS HOW MUCH PINT'S LARI DRANK TODAY!" << std::endl;
    
    while (true) 
    {   
        if (!gameStart)
        {
            std::cout << std::endl << "Wait a moment I'm getting drunk. I can drink in the range (0-50)..." << std::endl;
            std::cout << std::endl << "Enter -1 to give up!!!" << std::endl;
            
            goal_number = std::rand() % (GeneratingRange + 1);
            gameStart = !gameStart;
            std::cout << goal_number << std::endl;
        }

        std::cout << "Make your guess: ";
        std::cin >> user_choice;
        tries++;

        if (user_choice == -1) // Exit from game
        {
            std::cout << "ALREADY GIVING UP???" << std::endl;
            std::cout << "HA-HA-HA! COME BACK WHEN U'll BE MORE BRAVE, LOOSER" << std::endl;
            break;
        }
        else if (user_choice == goal_number) // Vin game, show statistics and restart game
        {            
            best_tries = (best_tries > tries) ? tries : best_tries;
            total_pints += goal_number;
            
            std::cout << std::endl << "!!! CONGRATS !!! " << goal_number << " THIS IS HOW MUCH I DRANK !!!" << std::endl << std::endl;
            std::cout << "You spent " << tries << " tries" << std::endl;
            std::cout << "Your highscore is " << best_tries << " tries" << std::endl;
            std::cout << "Total pints drunk: " << total_pints << " (" << total_pints * pinta_to_liter << " liters)" << std::endl << std::endl;

            std::cout << "Try to beat your highscore next time!" << std::endl;
            std::cout << "!!! BEWARE !!! NEXT IT WON'T BE THAT EASY !!!" << std::endl;

            tries = 0;
            gameStart = !gameStart;            
        }
        else if (user_choice < -1 || user_choice > 50) // Out of range
        {
            std::cout << "I'm watching this I need to guess how much YOU drank ;). My drinking limits are from 0 to 50!" << std::endl;
        }
        else // Get a hint
        {
            int precision = goal_number - user_choice;

            if (precision >= 0) 
            {
                if (precision < 3) 
                {
                    std::cout << "Wow this is a very nice try. You're almost there. But the right amount of drunk is a little more." << std::endl;
                } 
                else if (precision < 10) 
                {
                    std::cout << "Not bad. But the amount I drank is greater than your guess." << std::endl;
                }
                else
                {
                    std::cout << "Your guess is much more than the amount I drank." << std::endl;
                }
            }
            else 
            {
                if (precision > -3) 
                {
                    std::cout << "Wow this is a very nice try. You're almost there. But the right amount of drunk is a little less." << std::endl;
                } 
                else if (precision > -10) 
                {
                    std::cout << "Not bad. But the amount I drank is less than your guess." << std::endl;
                }
                else
                {
                    std::cout << "Your guess is much less than the amount I drank." << std::endl;
                }
            }            
        }
    }
}
