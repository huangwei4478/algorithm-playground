//
//  Timing.hpp
//  SolveSoduku
//
//  Created by huangwei on 2020/7/3.
//  Copyright © 2020 huangwei. All rights reserved.
//

#ifndef Timing_hpp
#define Timing_hpp

#include <iostream>
#include <chrono>
#include <thread>

struct Timer {
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;

    Timer() {
      start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
      end = std::chrono::high_resolution_clock::now();
      duration = end - start;
      float ms = duration.count() * 1000.0f;
      std::cout << "Timer took " << ms << "ms" << std::endl;
    }
};


#endif /* Timing_hpp */
