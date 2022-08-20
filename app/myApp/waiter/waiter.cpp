//
// Created by tanawin on 6/7/65.
//

#include "waiter.h"


namespace netBench{
    namespace app{


        WAITER::WAITER(APPID apId): APP(apId) {}

        void WAITER::initApp() {}

        void WAITER::initApp(long delay) {
            this->delay = delay;
        }

        void *WAITER::bench(void *arg) {

            uint64_t startSpec = getTime();


            timespec ww;
            ww.tv_nsec = 25;
            clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &ww, NULL);
            uint64_t stopSpec = getTime();
            cout << "start nanosec that use with in delay :" << startSpec << '\n';
            cout << "stop  nanosec that use with in delay :" << stopSpec << '\n';
            cout << "amount tick that use with in delay :"   << stopSpec - startSpec << '\n';





            return nullptr;
        }
    }

}