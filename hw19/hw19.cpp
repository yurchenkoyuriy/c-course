#include <iostream>
#include <string>
#include <algorithm>

//CASE 1
class A
{
public:
    A()
    {
        std::cout << "A()" << std::endl;
    }

    virtual ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};

class B : public A
{
public:
    B() : my_string("")
    {
        std::cout << "B()" << std::endl;
    }

    B(const std::string& arg_string) : my_string(arg_string)
    {
        std::cout << "B()" << std::endl;
    }

    ~B() override
    {
        std::cout << "~B()" << std::endl;
    }

    void print() const
    {
        std::cout << my_string << std::endl;
    }

    void print(const std::string& text) const
    {
        std::cout << text << std::endl;
    }

private:
    std::string my_string;
};


//CASE 2
class Base {
public:    
    virtual ~Base() = default;

    virtual void print() const {
        std::cout << "Base" << std::endl;
    }
};

class Derived1 : public Base {
public:
    void print() const override {
        std::cout << "Derived1" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void print() const override {
        std::cout << "Derived2" << std::endl;
    }
};



//CASE 3
class Animal
{
public:
    virtual ~Animal() = default;

    virtual void eat() {};

    virtual void sleep() {
        std::cout << "Animal sleep method\n";
    }    
};

class Dog : public Animal
{
public:
    void eat() override
    {
        eatCallsCounter++;
        std::cout << "Dog eating\n" << eatCallsCounter;
    }

private:
    int eatCallsCounter = 0;
};

class Cat : public Animal
{
public:
    void eat() override
    {
        std::cout << "Cat eating\n";
    }
};

void toLower(std::string& str)
{
    //ranged-based for loop
    //read: iterate every char of the string from left to right and execute something inside with it
    //similar to for (int i = 0; i < str.size(); i++) { str[i]... }
    for (char& ch : str)
    {
        ch = std::tolower(ch);
    }
}

Animal* createAnimal(std::string pet)
{
    
    toLower(pet);
    
    if (pet == "dog") return new Dog;    
    if (pet == "cat") return new Cat;
    
    return new Animal;
}


int main()
{
    //CASE 1
    A* a = new B();
    B* b = static_cast<B*>(a); 

    b->print("sdf");
    b->print();

    delete a;

    //CASE 2
    Derived1 d1;
    d1.print();

    Base* bp = dynamic_cast<Base*>(&d1);
    bp->print();

    Derived2* dp2 = dynamic_cast<Derived2*>(bp);
    
    if (dp2 != nullptr) {
        dp2->print();
    }
    else {
        std::cout << "Failed to cast to Derived2" << std::endl;
    }
    // or was it necessary to do so?
    Derived2* d2 = new Derived2();
    Base* base = dynamic_cast<Derived2*>(d2);

    if (base != nullptr) {
        base->print();
        delete d2;
    }
    else {
        std::cout << "Failed to cast to Derived2" << std::endl;
    }

    //CASE 3
    std::string petChoice;
    std::cout << "Choose your pet:(Dog/Cat):";
    std::cin >> petChoice;

    Animal* animal = createAnimal(petChoice);
    Dog* dog = dynamic_cast<Dog*>(animal);
    if (dog != nullptr)
    {
        dog->eat();
    }
    else 
    {
        std::cout << "Failed to cast to " << petChoice << std::endl;
    }

    delete animal;
    
    return 0;
}