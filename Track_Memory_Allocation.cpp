#include <iostream>
#include <memory>

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics s_AllocationMetrics;

static void printMemoryUsage()
{
    std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}

// overload new operator to controll the memoery allocation
void *operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes\n";

    s_AllocationMetrics.TotalAllocated += size;

    return malloc(size);
}

void operator delete(void *memory, size_t size)
{
    std::cout << "Deleting from " << memory << ", " << size << " bytes\n";

    s_AllocationMetrics.TotalFreed += size;

    free(memory);
}

struct Object
{
    int x, y, z;
};

int main()
{
    std::string string = "Cherno";

    printMemoryUsage();
    Object *obj = new Object; // this is a new allocation.

    std::unique_ptr<Object> object = std::make_unique<Object>();

    printMemoryUsage();
    delete obj;
    printMemoryUsage();
}