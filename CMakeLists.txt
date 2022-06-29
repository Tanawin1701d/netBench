cmake_minimum_required(VERSION 3.21)
project(netBench)

set(CMAKE_CXX_STANDARD 14)


add_executable(netBench
        main.cpp

        netBuffer/mBuf.h
        netBuffer/io.h

        app/app.h
        app/app.cpp
        app/myApp/streamingVdo.h
        app/myApp/streamingVdo.cpp

        simulator/simulator.h
        simulator/simulator.cpp
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(netBench PRIVATE Threads::Threads)