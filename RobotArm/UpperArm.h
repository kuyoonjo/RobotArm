//
//  UpperArm.h
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#ifndef __RobotArm__UpperArm__
#define __RobotArm__UpperArm__

#include "CombinedShape.h"

namespace ra
{
    class UpperArm : public CombinedShape
    {
    public:
        explicit UpperArm();
        ~UpperArm();
    private:
        sf::CircleShape* c1;
        sf::CircleShape* c2;
        sf::RectangleShape* rect;
    };
}

#endif /* defined(__RobotArm__UpperArm__) */
