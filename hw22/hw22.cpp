#include <iostream>
#include <map>
#include <stack>
#include <sstream>
#include <vector>
#include <string>
#include <set>

unsigned int uniqueWordsCount(const std::string& line) 
{
    if (line.size() == 0)
    {
        return 0;
    }
        
    std::istringstream iss(line);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word) 
    {
        words.push_back(word);
    }
        
    const std::set<std::string, std::less<>> uniqueWords(words.begin(), words.end());
    return uniqueWords.size();
}

std::string mostOccurredWord(const std::string& line)
{
    if (line.size() == 0)
    {
        return "";
    }        

    std::istringstream iss(line);
    std::map<std::string, int, std::less<>> words;
    std::string word;

    while (iss >> word) 
    {
        ++words[word];
    }

    std::map<std::string, int, std::less<>>::iterator occurredWord{ std::max_element(words.begin(), words.end(), [](auto& left, auto& right) { return left.second < right.second; }) };
    return occurredWord->first;
}

bool balancedBrackets(const std::string& line)
{
    std::stack<char> brackets;
    for (const char ch : line)
    {
        if (brackets.empty()) {
            if (ch == ')' || ch == '}' || ch == ']')
            {
                return false; 
            }
            
            brackets.push(ch);
        }
        else
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                brackets.push(ch);
            }
            else if (brackets.top() == '(' && ch == ')' || brackets.top() == '{' && ch == '}' || brackets.top() == '[' && ch == ']')
            {
                brackets.pop();
            }
            else 
            {
                return false;
            }
        }
    }

    return (brackets.empty()) ? true : false;
}

int main()
{
    // Task 1
    std::cout << "Number of unique words: " << uniqueWordsCount("Hello Hey Hello Bye Hey") << std::endl;
    // Task 2
    std::cout << "The most frequently used word: " << mostOccurredWord("Hello Hey Hello Bye Hey Hey Hello Bye Hey") << std::endl;
    // Task 3
    std::cout << "Brackets check: " << balancedBrackets("(({()}))([]{})[]{}") << std::endl;
}