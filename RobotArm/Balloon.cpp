//
//  Balloon.cpp
//  RobotArm
//
//  Created by Yu Chen on 11/24/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#include "Balloon.h"
#include "Random.hpp"

namespace ra
{
    Balloon::Balloon(float radius) : CircleShape(radius)
    {
        this->setOrigin(this->getRadius(), this->getRadius());
    }
    
    bool Balloon::checkCollision(const sf::CircleShape &c1, const sf::CircleShape &c2)
    {
        float distanceSqr = powf(c1.getPosition().x - c2.getPosition().x, 2) + powf(c1.getPosition().y - c2.getPosition().y, 2);
        if (distanceSqr <= powf(c1.getRadius() + c2.getRadius(), 2))
            return true;
        return false;
    }
    
    std::vector<Balloon> Balloon::getRandomBalloons(int number, int radius,
                                                     const sf::Vector2<int>& position,
                                                     const sf::Vector2<int>& size)
    {
        int numberOfBalloons = number;
        std::vector<Balloon> balloons;
        while(balloons.size() < numberOfBalloons) {
            auto itr = balloons.begin();
            Balloon balloon = getRandomBalloon(radius, position, size);
            while (itr != balloons.end()) {
                if (Balloon::checkCollision(balloon, *itr)) {
                    balloon = getRandomBalloon(radius, position, size);
                    itr = balloons.begin();
                } else {
                    itr ++;
                }
            }
            balloons.push_back(balloon);
        }
        return balloons;
    }
    
    Balloon Balloon::getRandomBalloon(int radius,
                                       const sf::Vector2<int>& position,
                                       const sf::Vector2<int>& size)
    {
        bc::Random random;
        int posx = random.getInt(position.x + radius, position.x + size.x - radius);
        int posy = random.getInt(position.y + radius, position.y + size.y - radius);
        Balloon balloon(radius);
        balloon.setPosition(sf::Vector2<float>(posx, posy));
        return balloon;
    }
}