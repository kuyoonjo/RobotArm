//
//  Balloon.h
//  RobotArm
//
//  Created by Yu Chen on 11/24/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#ifndef __RobotArm__Balloon__
#define __RobotArm__Balloon__

#include <sfml/Graphics.hpp>
#include <vector>

namespace ra
{
    class Balloon : public sf::CircleShape
    {
    public:
        explicit Balloon(float);
        static bool checkCollision(const sf::CircleShape& c1, const sf::CircleShape& c2);
        static std::vector<Balloon> getRandomBalloons(int number, int radius,
                                                       const sf::Vector2<int>& position,
                                                       const sf::Vector2<int>& size);
    private:
        static Balloon getRandomBalloon(int radius,
                                         const sf::Vector2<int>& position,
                                         const sf::Vector2<int>& size);
    };
}

#endif /* defined(__RobotArm__Balloon__) */
