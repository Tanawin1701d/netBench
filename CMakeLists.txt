cmake_minimum_required(VERSION 3.21)
project(netBench)

set(CMAKE_CXX_STANDARD 14)

add_definitions(-DGEM_5)


add_executable(netBench
        main.cpp
        app/simApi/gem5/asm/generic/m5ops.h
        app/simApi/gem5/m5ops.h
        app/simApi/pin/sim_api.h
        app/simApi/api.h



        app/myApp/streamingVdo.h
        app/myApp/streamingVdo.cpp

        app/app.h
        app/app.cpp

        netBuffer/mBuf.h

        simulator/simulator.h
        simulator/simulator.cpp

        )

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(netBench PRIVATE Threads::Threads ${CMAKE_SOURCE_DIR}/app/simApi/libm5.a)


