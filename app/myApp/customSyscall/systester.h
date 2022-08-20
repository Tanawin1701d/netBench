//
// Created by tanawin on 14/7/65.
//

#ifndef WAITBENCH1_SYSTESTER_H
#define WAITBENCH1_SYSTESTER_H

#include"../../app.h"

namespace netBench::app {
    class systester : public APP {
    private:
        bool primeDirective = false;
    public:
        explicit systester(int appId);

        void initApp() override;

        void *bench(void *input) override;

        void initApp(bool isPrimeDirective);

    };
}

#endif //WAITBENCH1_SYSTESTER_H
