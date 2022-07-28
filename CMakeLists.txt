cmake_minimum_required(VERSION 3.0.0)
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