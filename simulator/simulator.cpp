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

//            struct timespec start, stop;
//            clock_gettime(CLOCK_REALTIME, &start);
//            while (true){
//                clock_gettime(CLOCK_REALTIME, & stop);
//                if (((stop.tv_nsec - start.tv_nsec) > ((uint32_t)5e6)) || (stop.tv_nsec < start.tv_nsec) ){
//                    break;
//                }
//            }

            BENCH_ENTER_ROI

            for(int appId = 0; appId < workload.size(); appId++){
                auto* wk = workload[appId];
                cout << "appId" <<wk->getAppId() << "has been invoked" << endl;
                #ifndef GEM_5
                    // todo we may give an input to the thread starting bech function
                    auto* thdStartVar = new benchStartVar{wk, nullptr}; /// <<-----
                    pthread_create(&workloadId[appId]
                                   , nullptr
                                   , app::APP::benchStart
                                   , (void*) (thdStartVar)
                                   );


                for (int appId = 0; appId < workload.size(); appId++) {
                    pthread_join(workloadId[appId], nullptr);
                }
                #else
                    wk->bench(nullptr);
                #endif

            }

        }
    }
}