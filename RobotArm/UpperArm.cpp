//
//  UpperArm.cpp
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#include "UpperArm.h"

namespace ra
{
    UpperArm::UpperArm() : CombinedShape(sf::Vector2<float>(0, 0),
                                         sf::Vector2<float>(0, -90))
    {
        this->c1 = new sf::CircleShape(20);
        this->c1->setOrigin(this->c1->getRadius(), this->c1->getRadius());
        this->c1->setOutlineColor(sf::Color::White);
        this->c1->setOutlineThickness(2);
        this->c2 = new sf::CircleShape(30);
        this->c2->setOrigin(this->c2->getRadius(), this->c2->getRadius());
        this->c2->setOutlineColor(sf::Color::White);
        this->c2->setOutlineThickness(2);
        this->rect = new sf::RectangleShape(sf::Vector2<float>(40, 120));
        this->rect->setOrigin(this->rect->getSize().x / 2, this->rect->getSize().y);
        this->add(0, this->rect);
        this->add(1, this->c2);
        this->add(2, this->c1);
    }
    UpperArm::~UpperArm()
    {
        delete this->c1;
        delete this->c2;
        delete this->rect;
    }
}