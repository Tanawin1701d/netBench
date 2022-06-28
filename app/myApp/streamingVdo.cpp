//
// Created by tanawin on 28/6/65.
//

#include "streamingVdo.h"


namespace netBench {
namespace app
{
    streamVDO::streamVDO(APPID appId) : APP(appId) {}

    void
    streamVDO::initApp() {}

    void
    streamVDO::initApp(res r, int sec, int fps, int bs){
        buffFrame   = fps * bs;
        buffSec     = bs;
        framePerSec = fps;
        simSec      = sec;
        switch (r){
            case res::FULLHD : { pixelPerFrame = 2073600; break;}
            case res::TWOK   : { pixelPerFrame = 3686400; break;}
            case res::FOURK  : { pixelPerFrame = 8294400; break;}
            default          : { pixelPerFrame = 1      ; break;}
        }
        memBuffer = new netBuf::mBuf<rgb>(pixelPerFrame*buffFrame);

    }

    void*
    streamVDO::bench(void*){

        int simulatedSec = 0;
        auto start = std::chrono::high_resolution_clock::now();

        while (simulatedSec < simSec){
            cout << "threadId : " << std::this_thread::get_id() << endl;
            int writePix = 0;
            int totalBuffPix = buffFrame * pixelPerFrame;
            ///////////////////////////////////////////////////////////
            for (;writePix < totalBuffPix; writePix++){
                rgb* rd = new rgb({    (uint8_t)(rand()%256),
                                       (uint8_t)(rand()%256),
                                       (uint8_t)(rand()%256)
                                  });
                memBuffer->writeDayta((size_t)writePix, (size_t)1, rd);
                delete rd;
            }
            ///////////////////////////////////////////////////////////
            int readPix = 0;
            for (;readPix < totalBuffPix; readPix++){
                memBuffer->readDayta((size_t)readPix);
            }
            ///////////////////////////////////////////////////////////
            simulatedSec += buffSec;
        }


        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
        cout << duration.count() << endl;
    }
}
}

