#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    srand(time(0)); 
    int random = rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type is C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Type is A" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Type is B" << std::endl;
    } catch (std::bad_cast&) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Type is C" << std::endl;
    } catch (std::bad_cast&) {}
}
int main()
{
    Base* basePtr = generate();
    identify(basePtr);
    identify(*basePtr); 

    delete basePtr;
    return 0;
}