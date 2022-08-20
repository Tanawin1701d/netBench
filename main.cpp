#include <iostream>
#include "simulator/simulator.h"
#include "app/myApp/streaming/streamingVdo.h"
#include "app/myApp/waiter/waiter.h"
#include "app/myApp/customSyscall/systester.h"

using namespace netBench;

int main() {

    /// build simulator core
    sim::simManager mySim;
    /// build work load
    auto* wk = new app::streamVDO(0);
          wk->initApp();
          wk->initApp(app::res::DD, 100, 1000000, 1);
//    auto* wk2 = new app::streamVDO(1);
//          wk2->initApp();
//          wk2->initApp(app::res::DD, 500, 25, 1);
//    auto* wk = new app::WAITER(0);
    /// test
//    auto* wk = new app::WAITER(0);
//          wk->initApp();
//          wk->initApp(1);
//    auto* wk = new app::systester(0);
//          wk->initApp(true);
    /// set up sim manager
    mySim.addApp(wk);
   // mySim.addApp(wk2);
    cout << "pre-fork-thead\n";
    // start simulation
    mySim.simulate();
    return 0;
}
