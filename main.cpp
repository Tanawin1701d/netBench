#include <iostream>
#include "simulator/simulator.h"
#include "app/myApp/streamingVdo.h"

using namespace netBench;

int main() {

    /// build simulator core
    sim::simManager mySim;
    /// build work load
    auto* wk = new app::streamVDO(0);
          wk->initApp();
          wk->initApp(app::res::FULLHD, 2, 1, 1);
    auto* wk2 = new app::streamVDO(1);
          wk2->initApp();
          wk2->initApp(app::res::FULLHD, 2, 1, 1);
    /// set up sim manager
    mySim.addApp(wk);
    //mySim.addApp(wk2);

    // start simulation
    mySim.simulate();
    return 0;
}
