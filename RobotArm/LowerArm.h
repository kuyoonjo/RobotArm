//
//  LowerArm.h
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#ifndef __RobotArm__LowerArm__
#define __RobotArm__LowerArm__

#include "CombinedShape.h"

namespace ra
{
    class LowerArm : public CombinedShape
    {
    public:
        explicit LowerArm();
        ~LowerArm();
    private:
        sf::CircleShape* c;
        sf::CircleShape* cc;
        sf::CircleShape* c1;
        sf::CircleShape* c2;
        sf::RectangleShape* rect;
    };
}

#endif /* defined(__RobotArm__LowerArm__) */
