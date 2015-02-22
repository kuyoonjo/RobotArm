//
//  Random.cpp
//  BouncingCircles
//
//  Created by Yu Chen on 9/29/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#include "Random.hpp"
namespace bc {
    Random::Random() {
        //
    }
    int Random::getInt(int min, int max) {
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::uniform_int_distribution<int> distribution(min, max);
        int dice_roll = distribution(generator);
        return dice_roll;
    }
}