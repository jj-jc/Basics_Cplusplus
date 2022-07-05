#include <iostream>
#include <string>


void printValue(int value)
{
    std::cout << value << std::endl;
}

void printValue(std::string value)
{
    std::cout << value << std::endl;
}

template<typename T> 
void printTemplate(T value)
{
    std::cout << value << std::endl;
}

template <typename T, int N>
class Array
{
    private:
        T m_Array[N];
    public:
        int getSize() const {return N;}
};

int main()
{
    printValue(5);
    printValue("Hello World");

    printTemplate(5);
    printTemplate<int>(5);
    printTemplate("Hello World");
    printTemplate(5.5f);

    Array<int, 5> array;
    int arrarySize = array.getSize();
    printTemplate(arrarySize);

    // Array<int, 5> array;


}