//
//  RobotBody.cpp
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#include "RobotBody.h"

namespace ra
{
    const float RobotBody::space = 2;
    
    RobotBody::RobotBody() : CombinedShape(sf::Vector2<float>(0, 0),
                                           sf::Vector2<float>(20, -140))
    {
        this->chassis = new Chassis();
        this->rect1 = new sf::RectangleShape(sf::Vector2<float>(40, 30));
        this->rect1->setOrigin(this->rect1->getSize().x / 2,
                               this->rect1->getSize().y + this->chassis->height + RobotBody::space);
        this->rect2 = new sf::RectangleShape(sf::Vector2<float>(40, 30));
        this->rect2->setOrigin(this->rect2->getSize().x / 2,
                               this->rect2->getSize().y + this->rect1->getSize().y + this->chassis->height + RobotBody::space * 2);
        this->control = new yc::sfml::EllipseShape(sf::Vector2<float>(60, 30));
        this->control->setOrigin(this->control->getRadius().x,
                                 this->control->getRadius().y * 2 + this->rect2->getSize().y + this->rect1->getSize().y + this->chassis->height + RobotBody::space * 3);
        this->add(0, this->chassis);
        this->add(1, this->rect1);
        this->add(2, rect2);
        this->add(3, control);
    }
    
    RobotBody::~RobotBody()
    {
        delete this->chassis;
        delete this->rect1;
        delete this->rect2;
        delete this->control;
    }

    
    RobotBody::Chassis::Chassis(float height,
                                float heightBelow,
                                float widthAbove,
                                float widthBelow)
    :height(height), heightBelow(heightBelow), widthAbove(widthAbove), widthBelow(widthBelow)
    {
        this->setPointCount(6);
        this->setPoint(0, sf::Vector2<float>(-this->widthBelow / 2, 0));
        this->setPoint(1, sf::Vector2<float>(this->widthBelow / 2, 0));
        this->setPoint(2, sf::Vector2<float>(this->widthBelow / 2, -this->heightBelow));
        this->setPoint(5, sf::Vector2<float>(-this->widthBelow / 2, -this->heightBelow));
        this->setPoint(3, sf::Vector2<float>(this->widthAbove / 2, -this->height));
        this->setPoint(4, sf::Vector2<float>(-this->widthAbove / 2, -this->height));
    }
}