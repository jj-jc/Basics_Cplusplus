#include <iostream>
#include <memory>
#include <chrono>

class Timer
{

    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
    public:
        Timer()
        {
            m_StartTimepoint = std::chrono::high_resolution_clock::now();
        }

        void stop()
        {
            auto endTimepoint = std::chrono::high_resolution_clock::now();
            auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
            auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

            auto duration = end - start;
            double ms = duration * 0.001;

            std::cout << duration << "us (" << ms << "ms)\n";
        }

        ~Timer()
        {
            stop();
        }
};

int main()
{
    int value = 0;
    {
        // Timer timer;
        for (int i = 0; i < 1000000; i++)
            value += 2;
    }
    // std::cout << value << std::endl;

    class Vector2
    {
        float x, y;
    };

    std::cout << "Make Shared\n";
    {
        std::array<std::shared_ptr<Vector2>, 100000> sharedPtrs;
        Timer time;
        for (int i = 0; i < sharedPtrs.size(); i++)
            sharedPtrs[i] = std::make_shared<Vector2>();
    }

    std::cout << "New Shared\n";
    {
        std::array<std::shared_ptr<Vector2>, 100000> sharedPtrs;
        Timer time;
        for (int i = 0; i < sharedPtrs.size(); i++)
            sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
    }

    std::cout << "Make Unique\n";
    {
        std::array<std::unique_ptr<Vector2>, 100000> sharedPtrs;
        Timer time;
        for (int i = 0; i < sharedPtrs.size(); i++)
            sharedPtrs[i] = std::make_unique<Vector2>();
    }

    // std::cout << "New Unique\n";
    // {
    //     std::array<std::unique_ptr<Vector2>, 100000> sharedPtrs;
    //     Timer time;
    //     for (int i = 0; i < sharedPtrs.size(); i++)
    //         sharedPtrs[i] = std::unique_ptr<Vector2>(new Vector2());
    // }

}