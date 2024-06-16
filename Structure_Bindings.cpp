#include <iostream>
#include <tuple>

std::tuple<std::string, int> CreatePerson()
{
    return {"Cherno", 24};
}

int main()
{
    auto person = CreatePerson();
    std::string &name = std::get<0>(person);
    int age = std::get<1>(person);

    // Nicer way to do it with a lesser C++ standard
    std::string name2;
    int age2;
    std::tie(name2, age2) = CreatePerson();

    // using structured bindings (Only for C++ 17)
    auto [name3, age3] = CreatePerson();
    std::cout << name3 << std::endl;
}