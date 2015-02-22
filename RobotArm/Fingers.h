//
//  Fingers.h
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#ifndef __RobotArm__Fingers__
#define __RobotArm__Fingers__

#include "CombinedShape.h"
#include "Balloon.h"

namespace ra
{
    class Fingers : public CombinedShape
    {
    private:
        class Arch;
    public:
        explicit Fingers();
        ~Fingers();
        void setPosition(float x, float y);
        void setPosition(const sf::Vector2<float>& position);
        void rotate(float angle);
        void move(float offsetX, float offsetY);
        void move(const sf::Vector2f& offset);
        bool interacts(const ra::Balloon& balloon);
        Arch* left;
        Arch* right;
        
    };
    
    class Fingers::Arch : public sf::CircleShape, public ss::Pendulum
    {
    public:
        explicit Arch(const sf::Vector2<float>& C, const sf::Vector2<float>& O);
        virtual sf::Vector2f getPoint(unsigned int index) const override;
        void setPosition(float x, float y);
        void setPosition(const sf::Vector2<float>& position);
        void rotate(float angle);
        void move(float offsetX, float offsetY);
        void move(const sf::Vector2f& offset);
    };
}

#endif /* defined(__RobotArm__Fingers__) */
