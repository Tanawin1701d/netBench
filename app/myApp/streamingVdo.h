//
// Created by tanawin on 28/6/65.
//

#ifndef NETBENCH_STREAMINGVDO_H
#define NETBENCH_STREAMINGVDO_H

#include <cstdint>
#include <chrono>
#include <thread>
#include "../app.h"
#include "../../netBuffer/mBuf.h"
namespace netBench{
namespace app{

        struct rgb{
            uint8_t red;
            uint8_t green;
            uint8_t blue;
        };

        enum res {
            FULLHD,
            TWOK,
            FOURK
        };

        class streamVDO: public APP{
        private:
            netBench::netBuf::mBuf<rgb>* memBuffer;

            int buffFrame;
            int buffSec;
            int pixelPerFrame;
            int framePerSec;
            int simSec;


        public:
            explicit streamVDO(APPID appId);
            void  initApp(res r, int sec, int fps, int bs);
            void  initApp() override;
            void* bench(void*) override;
        };
}
}

#endif //NETBENCH_STREAMINGVDO_H
