//
// Created by tanawin on 29/6/65.
//

#ifndef NETBENCH_API_H
#define NETBENCH_API_H

#if defined(GEM_5)
    #define BENCH_ENTER_ROI m5_switch_cpu();
    #define BENCH_EXIT_ROI m5_switch_cpu();
#elif defined(PIN_TOOLS)
    #define BENCH_EXIT_ROI SimRoiEnd();
    #define BENCH_EXIT_ROI SimRoiStart();
#endif
    #define BENCH_ENTER_ROI
    #define BENCH_EXIT_ROI


#endif //NETBENCH_API_H
