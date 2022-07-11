//
// Created by tanawin on 6/7/65.
//

#include "waiter.h"


namespace netBench{
    namespace app{


        WAITER::WAITER(APPID apId): APP(apId) {}

        void WAITER::initApp() {}

        void *WAITER::bench(void *arg) {

            BENCH_ENTER_ROI
            for (int i = 0; i <= 1; i++) {
                struct timespec start, stop;
                clock_gettime(CLOCK_REALTIME, &start);
                while (true) {
                    clock_gettime(CLOCK_REALTIME, &stop);
                    if (((stop.tv_nsec - start.tv_nsec) > 5) || (stop.tv_nsec < start.tv_nsec)) {
                        break;
                    }
                }
            }
            BENCH_EXIT_ROI




            return nullptr;
        }
    }

}