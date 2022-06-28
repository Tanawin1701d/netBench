//
// Created by tanawin on 28/6/65.
//

#ifndef NETBENCH_IO_H
#define NETBENCH_IO_H


#include<iostream>
using namespace std;

namespace netBench {
    namespace netBuf {

        template<typename T>
        class readable {
        public:
            virtual T readDayta(size_t offset) = 0;

            virtual T *readPointer(size_t offset) = 0;

        };

        template<typename T>
        class writable {
        public:
            virtual void writeDayta(size_t offset, size_t size, T *copyDayta) = 0;

        };


    }
}

#endif //NETBENCH_IO_H
