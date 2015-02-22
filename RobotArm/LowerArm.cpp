//
//  LowerArm.cpp
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#include "LowerArm.h"

namespace ra
{
    LowerArm::LowerArm() : CombinedShape(sf::Vector2<float>(0, 0),
                                         sf::Vector2<float>(0, -153))
    {
        this->c = new sf::CircleShape(12);
        this->c->setOrigin(this->c->getRadius(), this->c->getRadius());
        this->c->setOutlineColor(sf::Color::White);
        this->c->setOutlineThickness(2);
        this->rect = new sf::RectangleShape(sf::Vector2<float>(60, 180));
        this->rect->setOrigin(this->rect->getSize().x / 2,
                              this->rect->getSize().y - this->c->getRadius() - 15);
        this->cc = new sf::CircleShape(30);
        this->cc->setOrigin(this->cc->getRadius(),
                            this->cc->getRadius() + this->rect->getSize().y - this->c->getRadius() - 15);
        this->c1 = new sf::CircleShape(22);
        this->c1->setOutlineColor(sf::Color::White);
        this->c1->setOutlineThickness(2);
        this->c1->setOrigin(this->c1->getRadius(),
                            this->c1->getRadius() + this->rect->getSize().y - this->c->getRadius() - 15);
        this->c2 = new sf::CircleShape(16);
        this->c2->setOutlineColor(sf::Color::White);
        this->c2->setOutlineThickness(2);
        this->c2->setOrigin(this->c2->getRadius(),
                            this->c2->getRadius() + this->rect->getSize().y - this->c->getRadius() - 15);
        this->add(0, this->rect);
        this->add(1, this->c);
        this->add(2, cc);
        this->add(3, c1);
        this->add(4, c2);
    }
    LowerArm::~LowerArm()
    {
        delete this->c;
        delete this->rect;
        delete this->cc;
        delete c1;
        delete c2;
    }
}