#include "Serializer.hpp"

int main()
{
    Data originalData;
    originalData.intVal = 42;
    originalData.stringVal = "Hello, World!";
    originalData.floatVal = 3.14f;
    originalData.str = "Hola";

    std::cout << "Original Data: " << std::endl;
    std::cout << "int: " << originalData.intVal << std::endl;
    std::cout << "string: " << originalData.stringVal << std::endl;
    std::cout << "float: " << originalData.floatVal << std::endl;
    std::cout << "string: " << originalData.str << std::endl;

    uintptr_t serialized = Serializer::serialize(&originalData);

    std::cout << "\nAlmacenado como unsigned int ptr: " << serialized << std::endl;

    Data* finalData = Serializer::deserialize(serialized);

    std::cout << "\nFinal Data: " << std::endl;
    std::cout << "int: " << finalData->intVal << std::endl;
    std::cout << "string: " << finalData->stringVal << std::endl;
    std::cout << "float: " << finalData->floatVal << std::endl;
    std::cout << "string: " << finalData->str << std::endl;

    return 0;
}