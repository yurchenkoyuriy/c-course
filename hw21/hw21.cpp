#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

std::function<std::string()> makeLambda()
{
    const std::string val = "string";
    return [val] {return val; }; // &val - dangling reference error
}

unsigned int countDivisibleBy(const std::vector<int>& vec, int number)
{
    return std::count_if(vec.begin(), vec.end(), [number](int value)
    {
        return (value % number == 0);
    });
}

bool compareByLength(const std::string& left, const std::string& right)
{
    return left.size() < right.size();
}

class LengthComparator
{
public:
    bool operator()(const std::string& left, const std::string& right) const
    {
        return left.size() < right.size();
    }
};

int main()
{
    auto bad = makeLambda();
    std::cout << bad() << std::endl;

    std::vector<int> v1 {32, 21, 25, 50, 100};
    std::cout << "elements divisible by 5: " << countDivisibleBy(v1, 5) << std::endl;
        
    std::vector<std::string> strCont1{"d", "sss", "aa", "w", "asdf"};
    std::vector<std::string> strCont2{"d", "sss", "aa", "w", "asdf"};
    std::vector<std::string> strCont3{"d", "sss", "aa", "w", "asdf"};

    std::sort(strCont1.begin(), strCont1.end(), [](auto& left, auto& right) { return left.size() < right.size(); });
    std::sort(strCont2.begin(), strCont2.end(), compareByLength);
    std::sort(strCont3.begin(), strCont3.end(), LengthComparator());
}   