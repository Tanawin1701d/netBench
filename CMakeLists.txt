cmake_minimum_required(VERSION 3.21)
project(netBench1)

set(CMAKE_CXX_STANDARD 14 )
#set(CMAKE_POSITION_INDEPENDENT_CODE ON)
add_definitions(-DGEM_5)
#add_definitions(-DPIN_TOOLS)

#find_path(KERNELHEADERS_DIR
#        include/linux/user.h
#        PATHS /usr/src/linux-headers-${KERNEL_RELEASE}
#        )
#
#message(STATUS "Kernel release: ${KERNEL_RELEASE}")
#message(STATUS "Kernel headers: ${KERNELHEADERS_DIR}")

add_executable(netBench1
        main.cpp
        app/simApi/gem5/asm/generic/m5ops.h
        app/simApi/gem5/m5ops.h
        app/simApi/pin/sim_api.h
        app/simApi/api.h


        app/myApp/streaming/streamingVdo.h
        app/myApp/streaming/streamingVdo.cpp

        app/app.h
        app/app.cpp

        netBuffer/mBuf.h

        simulator/simulator.h
        simulator/simulator.cpp

        app/myApp/waiter/waiter.h
        app/myApp/waiter/waiter.cpp
        app/myApp/waiter/waiter.h

        #app/simApi/n5thread/m5threads/pthread.c
        #app/simApi/gem5/m5thread/m5thread.cpp
        #app/simApi/gem5/m5thread/m5thread.h
        #lib/m5threads/pthread.c
        app/myApp/customSyscall/systester.cpp app/myApp/customSyscall/systester.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(netBench1 PRIVATE Threads::Threads
        ${CMAKE_SOURCE_DIR}/app/simApi/libm5.a
        #${CMAKE_SOURCE_DIR}/app/simApi/libpthread.a
        )



