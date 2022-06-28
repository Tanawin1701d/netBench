//
// Created by tanawin on 28/6/65.
//

#ifndef NETBENCH_MBUF_H
#define NETBENCH_MBUF_H


#include "io.h"


namespace netBench {
    typedef unsigned long long ull;

    namespace netBuf {

        template<typename T>
        class mBuf{ //: public readable<T>, writable<T> {
        private:
            T*     dayta;
            size_t size;
        public:
            /// constructor
            explicit mBuf(size_t size) : dayta(new T[size]())
                                       , size (size         ){};
            /// deconstructor
            ~mBuf() {
                delete[] dayta;
            }
            /// size
            size_t getSize() const{
                return size;
            };
            ull getSizeInBytes() const{
                return (ull)size * sizeof(T);
            };
            /// read dayta
            T readDayta(size_t offset){
                return (offset >= size) ? T() : dayta[offset];
            };
            T *readPointer(size_t offset){
                return (offset >= size) ? nullptr : dayta + offset;
            } ;
            /// write dayta
            void writeDayta(size_t offset, size_t fillSize, T* copyDayta){
                if ( (offset + fillSize) <= size ){
                    std::copy(copyDayta, copyDayta + fillSize, dayta + offset);
                }
            }
        };



    }

}


#endif //NETBENCH_MBUF_H
