//
//  Config.h
//  RobotArm
//
//  Created by Yu Chen on 11/23/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#ifndef RobotArm_Config_h
#define RobotArm_Config_h

#include <SFML/Graphics.hpp>

namespace ra
{
    namespace Config
    {
        const sf::String title = "Robot Arm";
        const sf::VideoMode videoMode(800, 600);
        const int framerateLimit = 60;
        const sf::String font = "Courier New.ttf";
        const float fontSize = 15;
        const sf::Vector2<float> msgPosition(20, 540);
        const sf::Vector2<float> bodyStartPosition(100, 500);
        const float moveSpeed = 1;
        const float rotateSpeed = 1;
        const float PI = 360;
        const float halfPI = 180;
        const float quarterPI = 90;
        const sf::Vector2<float> bodyLimit(100, 700);
        const sf::Vector2<float> upperArmLimit(-40, 60);
        const sf::Vector2<float> lowerArmLimit(0, 136);
        const sf::Vector2<float> fingerLimit(90, 180);
    }
}

#endif
