//
// Created by tanawin on 28/6/65.
//

#ifndef NETBENCH_SIMULATOR_H
#define NETBENCH_SIMULATOR_H

#include <vector>
#include <pthread.h>
#include "../app/app.h"

namespace netBench{

    namespace sim{

        using namespace netBench::app;

        class simManager{
        private:
            static const int MAX_NUM_THREAD = 1024;
            std::vector<APP*> workload;
            pthread_t workloadId[MAX_NUM_THREAD];
        public:
            explicit simManager();
            void addApp(APP* wl);
            void simulate();
        };
    }

}

#endif //NETBENCH_SIMULATOR_H
