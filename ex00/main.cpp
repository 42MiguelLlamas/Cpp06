#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Needed 1 argument only. E.G: './Scalar 1' " << std::endl;
		return 1;
	}
	
	std::string literal = argv[1];
    ScalarConverter::convert(literal);
    
    return 0;
}