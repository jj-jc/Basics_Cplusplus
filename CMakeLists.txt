cmake_minimum_required(VERSION 3.12.0)
project("C++")
set(CMAKE_CXX_STANDARD 17)

# Set the libraries generated outside of the project inside the workspace
# set(CMAKE_LIBRAY_OUTPUT_DIRECTORY "/home/jjjurado/Dev/OpenGL") 
# message("${CMAKE_LIBRAY_OUTPUT_DIRECTORY}")
# option(MY_DEBUG "Defines MY_DEBUG option to debug output context in OpenGL" ON)
set(SRC VirtualFunctions.cpp)
add_executable(VirtualFunctions ${SRC})

set(SRC Interfaces.cpp)
add_executable(Interfaces ${SRC})

set(SRC Strings.cpp)
add_executable(Strings ${SRC})

set(SRC StringLiterals.cpp)
add_executable(StringLiterals ${SRC})

set(SRC Mutable.cpp)
add_executable(Mutable ${SRC})

set(SRC TernaryOperators.cpp)
add_executable(TernaryOperators ${SRC})

set(SRC CreationObjects.cpp)
add_executable(CreationObjects ${SRC})

set(SRC ImplicitExplicit.cpp)
add_executable(ImplicitExplicit ${SRC})

set(SRC Operators.cpp)
add_executable(Operators ${SRC})

set(SRC SmartPointers.cpp)
add_executable(SmartPointers ${SRC})

set(SRC This.cpp)
add_executable(This ${SRC})

set(SRC ObjectsLifetime.cpp)
add_executable(ObjectsLifetime ${SRC})

set(SRC ArrowOperator.cpp)
add_executable(ArrowOperator ${SRC})

set(SRC StdVector.cpp)
add_executable(StdVector ${SRC})

set(SRC LocaStatic.cpp)
add_executable(LocaStatic ${SRC})


find_package( Threads REQUIRED )

set(SRC Threads.cpp)
add_executable(Threads ${SRC})
target_link_libraries(Threads PUBLIC ${CMAKE_THREAD_LIBS_INIT})

set(SRC FunctionPointers.cpp)
add_executable(FunctionPointers ${SRC})

set(SRC Templates.cpp)
add_executable(Templates ${SRC})

set(SRC Iterators.cpp)
add_executable(Iterators ${SRC})

set(SRC Arrays.cpp)
add_executable(Arrays ${SRC})

set(SRC Chrono.cpp)
add_executable(Chrono ${SRC})

set(SRC Benchmarking.cpp)
add_executable(Benchmarking ${SRC})

set(SRC MultidimensionalArray.cpp)
add_executable(MultidimensionalArray ${SRC})

set(SRC Sort.cpp)
add_executable(Sort ${SRC})

set(SRC TypePunning.cpp)
add_executable(TypePunning ${SRC})

set(SRC Unions.cpp)
add_executable(Unions ${SRC})

set(SRC VirtualDestructors.cpp)
add_executable(VirtualDestructors ${SRC})

set(SRC Casting.cpp)
add_executable(Casting ${SRC})

set(SRC DynamicCast.cpp)
add_executable(DynamicCast ${SRC})

set(SRC Structure_Bindings.cpp)
add_executable(Structure_Bindings ${SRC})

set(SRC Singleton.cpp)
add_executable(Singleton ${SRC})

set(SRC Asynchronous.cpp)
add_executable(Asynchronous ${SRC})

set(SRC Track_Memory_Allocation.cpp)
add_executable(Track_Memory_Allocation ${SRC})

set(SRC lrvalues.cpp)
add_executable(lrvalues ${SRC})

## set up boost dependency
find_package(Boost 1.45.0 REQUIRED) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(DeducingTypes DeducingTypes.cpp) 
    target_link_libraries(DeducingTypes ${Boost_LIBRARIES})
endif()

add_executable(Item7 Item7.cpp)

add_executable(Item18 Item18.cpp Item18.hpp)

## Include googleTest dependency without having inside the project
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.x  # Use the latest release from the 1.x branch
)

FetchContent_MakeAvailable(spdlog)


add_executable(Item18Test tests/Item18Test.cpp Item18.cpp)
target_link_libraries(Item18Test gtest gtest_main)

add_executable(SampleTest tests/SampleTest.cpp)
target_link_libraries(SampleTest gtest gtest_main)

add_executable(Item25Test tests/Item25Test.cpp)
target_link_libraries(Item25Test gtest gtest_main)
target_link_libraries(Item25Test spdlog::spdlog)

add_executable(LambdaTest tests/LambdaTest.cpp Lambda.hpp)
target_link_libraries(LambdaTest gtest gtest_main)
target_link_libraries(LambdaTest spdlog::spdlog)