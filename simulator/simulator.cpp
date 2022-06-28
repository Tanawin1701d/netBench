//
// Created by tanawin on 28/6/65.
//

#include "simulator.h"

namespace netBench {

    namespace sim {
        simManager::simManager() {

        }

        void simManager::addApp(netBench::app::APP *wl) {

            workload.push_back(wl);

        }

        void simManager::simulate() {

            for(int appId = 0; appId < workload.size(); appId++){
                auto* wk = workload[appId];
                // todo we may give an input to the thread starting bech function
                benchStartVar thdStartVar = {wk, nullptr}; /// <<-----
                pthread_create(&workloadId[appId]
                               , nullptr
                               , app::APP::benchStart
                               , (void*) (&thdStartVar)
                               );
            }
            for (int appId = 0; appId < workload.size(); appId++) {
                pthread_join(workloadId[appId], nullptr);
            }

        }
    }
}