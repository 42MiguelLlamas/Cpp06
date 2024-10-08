#include "Serializer.hpp"

int main()
{
    Data originalData;
    originalData.intValue = 42;
    originalData.stringValue = "Hello, World!";
    originalData.floatValue = 3.14f;

    std::cout << "Original Data: " << std::endl;
    std::cout << "intValue: " << originalData.intValue << std::endl;
    std::cout << "stringValue: " << originalData.stringValue << std::endl;
    std::cout << "floatValue: " << originalData.floatValue << std::endl;

    uintptr_t raw = Serializer::serialize(&originalData);

    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "\nDeserialized Data: " << std::endl;
    std::cout << "intValue: " << deserializedData->intValue << std::endl;
    std::cout << "stringValue: " << deserializedData->stringValue << std::endl;
    std::cout << "floatValue: " << deserializedData->floatValue << std::endl;

    return 0;
}