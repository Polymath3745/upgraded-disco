#include <vector>
#include <iostream>
//.'
void VectorStuff()
{
    std::vector<int> numbers; // Creates an empty vector of integers

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    int firstElement = numbers[0];
    int secondElement = numbers.at(1);

    for (int i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << std::endl;
    }
}
