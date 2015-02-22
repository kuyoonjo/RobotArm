//
//  Random.h
//  BouncingCircles
//
//  Created by Yu Chen on 9/29/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#ifndef __BouncingCircles__Random__
#define __BouncingCircles__Random__

#include <stdlib.h>
#include <ctime>
#include <random>
namespace bc {
    class Random {
    public:
        Random();
        int getInt(int min, int max);
    };
}

#endif /* defined(__BouncingCircles__Random__) */
