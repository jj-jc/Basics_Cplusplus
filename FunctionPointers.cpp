    
#include <iostream>
#include <vector>

static bool s_Finished = false;

void doWork()
{
    std::cout << "Hello World!" << std::endl;
}

void printA(int a)
{
    std::cout << "Hello World!" << a << std::endl;
}

void printValue(int& value)
{
    std::cout << "Value: " << value << std::endl;
}

void foreach(std::vector<int> values, void(*func)(int&))
{
    for (int &value: values)
    {
        func(value);
    }
}



int main()
{
    typedef void(*doWork_ptr)();
    typedef void(*printA_ptr)(int);

    auto function = doWork; 

    function();
    function();

    void(*cherno)() = doWork;
    cherno();

    doWork_ptr copydoWork = doWork;
    doWork_ptr();

    printA_ptr copyprintA = printA;
    copyprintA(2);
    
    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<int> values = {1,2,4,5,1,3};
    foreach(values, printValue);

    std::cout << std::endl;
    std::cout << std::endl;

    foreach(values, [](int &value){ std::cout << "Value:" << value << std::endl;});


}