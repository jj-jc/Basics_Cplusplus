#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

class Timer
{
    public:
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        std::chrono::duration<float> duration;

        Timer()
        {
            start = std::chrono::high_resolution_clock::now();
        }

        ~Timer()
        {
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;


            float ms = duration.count() * 1000.0f;
            std::cout << "Timer took " << ms << "ms" << std::endl;
            // std::cout << "Timer took " << duration.count() << "ms" << std::endl;

        }
};

void function()
{
    Timer timer;
    for(int i = 0; i < 100; i++)
        std::cout << "Hello " << std::endl;
}

int main()
{

    // using namespace std::chrono_literals; 
    // auto start = std::chrono::high_resolution_clock::now();
    // std::this_thread::sleep_for(1s); // needs the std::chrono_literals namespace
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<float> duration = end - start;



    // std::cout << duration.count() << "s" << std::endl;

    function();


}