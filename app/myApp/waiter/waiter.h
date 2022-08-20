//
// Created by tanawin on 6/7/65.
//

#ifndef NETBENCH_WAITER_H
#define NETBENCH_WAITER_H
#include"../../app.h"

namespace netBench{
    namespace app{
        class WAITER: public APP{
        private:
            long int delay = 0;
        public:
            explicit WAITER(APPID apId);
            void initApp() override;
            void initApp(long int delay);
            void* bench(void* arg) override;




        };
    }

}

#endif //NETBENCH_WAITER_H
