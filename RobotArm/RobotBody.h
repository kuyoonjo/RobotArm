//
//  RobotBody.h
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#ifndef __RobotArm__RobotBody__
#define __RobotArm__RobotBody__

#include "CombinedShape.h"
#include "EllipseShape.h"

namespace ra
{
    class RobotBody : public CombinedShape
    {
    public:
        static const float space;
        sf::Vector2<float> center;
        explicit RobotBody();
        ~RobotBody();
    private:
        class Chassis;
        class ControlRoom;
        Chassis* chassis;
        sf::RectangleShape* rect1;
        sf::RectangleShape* rect2;
        yc::sfml::EllipseShape* control;
    };
    
    class RobotBody::Chassis : public sf::ConvexShape
    {
    public:
        float height;
        float heightBelow;
        float widthAbove;
        float widthBelow;
        explicit Chassis(float height = 20,
                         float heightBelow = 15,
                         float widthAbove = 40,
                         float widthBelow = 130);
    };
}

#endif /* defined(__RobotArm__RobotBody__) */
