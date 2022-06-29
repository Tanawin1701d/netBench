//
// Created by tanawin on 28/6/65.
//

#ifndef NETBENCH_APP_H
#define NETBENCH_APP_H



#include "../netBuffer/mBuf.h"
#include "simApi/pin/sim_api.h"
#include "simApi/gem5/m5ops.h"
#include "simApi/api.h"

namespace netBench{
    namespace app{

        //////////////////////////////
        class APP;
        typedef int APPID;
        struct benchStartVar{
            APP*  cls;
            void* benchArgs;
        };        
        
        //////////////////////////////
        /// class for simulate
        class APP{
        protected:
            APPID appId{} ;
        public:
            explicit APP(APPID appId);
            virtual void initApp() = 0;
            virtual void* bench(void*)   = 0;

            static void*  benchStart(void* owner){
                benchStartVar meta = *((benchStartVar*)owner);
                return meta.cls->bench(meta.benchArgs);
            }

            APPID getAppId() const;

        };

        ////////////////////////////////
    }

}
#endif //NETBENCH_APP_H
