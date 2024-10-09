#include "Base.hpp"

Base::~Base() {
    std::cout << "Base destructor called" << std::endl;
}

Base* generate(void)
{
    std::srand(std::time(0));
    int randValue = std::rand() % 3;

    switch (randValue)
    {
        case 0:
            std::cout << "Generated A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated C" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "Class A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "Class B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "Class C" << std::endl;
  else
    std::cout << "Not Class A, B or C" << std::endl;
}

void identify(Base &p) {
	Base temp;
	
  try {
    temp = dynamic_cast<A &>(p);
		(void) temp;
    std::cout << "Class A" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    temp = dynamic_cast<B &>(p);
		(void) temp;
    std::cout << "Class B" << std::endl;
  } catch (std::exception &e) {
  }
  try {
    temp = dynamic_cast<C &>(p);
		(void) temp;
    std::cout << "Class C" << std::endl;
  } catch (std::exception &e) {
  }
}