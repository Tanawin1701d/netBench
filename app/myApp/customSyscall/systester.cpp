//
// Created by tanawin on 14/7/65.
//

#include "systester.h"


namespace netBench::app{


    systester::systester(int appId) : APP(appId) {

    }

    void systester::initApp() {

    }

    void* systester::bench(void *input) {

        if (primeDirective){
            asm volatile("mov $1701, %eax \n\t"
                "mov $1,    %edi \n\t"
                "syscall"
                );
        }else{
            asm volatile("mov $1701, %eax \n\t"
                "mov $0,    %edi \n\t"
                "syscall"
            );
        }

        return nullptr;
    }

    void systester::initApp(bool isPrimeDirective) {
        primeDirective = isPrimeDirective;
    }
}