//
//  Fingers.cpp
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#include "Fingers.h"
#include <cmath>

namespace ra
{
    Fingers::Fingers() : CombinedShape(sf::Vector2<float>(0, 0),
                                         sf::Vector2<float>(0, -20))
    {
        this->left = new Fingers::Arch(sf::Vector2<float>(0, 0),
                                       sf::Vector2<float>(0, -50));
        this->left->setRadius(50);
        this->left->setOrigin(this->left->getRadius(), 0);
        this->left->Transformable::rotate(180);
        this->right = new Fingers::Arch(sf::Vector2<float>(0, 0),
                                        sf::Vector2<float>(0, -50));
        this->right->setRadius(50);
        this->right->setOrigin(this->right->getRadius(), this->right->getRadius() * 2);
        this->add(0, this->left);
        this->add(1, this->right);
    }
    Fingers::~Fingers()
    {
        delete this->left;
        delete this->right;
    }
    
    
    void Fingers::setPosition(float x, float y)
    {
        this->setPosition(sf::Vector2<float>(x, y));
    }
    
    void Fingers::setPosition(const sf::Vector2<float> &position)
    {
        this->move(position - this->getPosition());
    }
    
    void Fingers::rotate(float angle)
    {
        this->sf::Transformable::rotate(angle);
        this->left->rotate(angle);
        this->right->rotate(angle);
        this->transform(sf::Vector2<float>(0, 0), angle);
    }
    
    void Fingers::move(float offsetX, float offsetY)
    {
        this->move(sf::Vector2<float>(offsetX, offsetY));
    }
    
    void Fingers::move(const sf::Vector2f &offset)
    {
        this->Transformable::move(offset);
        this->left->move(offset);
        this->right->move(offset);
        this->transform(offset, 0);
    }
    
    
    bool Fingers::interacts(const ra::Balloon &balloon)
    {
        float angleArchLeft = atan2f(this->left->O.y - this->getPosition().y,
                                     this->left->O.x - this->getPosition().x);
        float angleArchBalloon = atan2f(balloon.getPosition().y - this->left->O.y,
                                        balloon.getPosition().x - this->left->O.x);
        float angleArchMin = angleArchLeft - M_PI;
        float distanceBalloonToArch = sqrtf(powf(this->left->O.x - balloon.getPosition().x, 2) +
                                            powf(this->left->O.y - balloon.getPosition().y, 2));
        if(angleArchBalloon >= angleArchMin && angleArchBalloon <= angleArchLeft)
            if (distanceBalloonToArch < balloon.getRadius() + this->left->getRadius())
                return true;
        
        float angleArchRight = atan2f(this->right->O.y - this->getPosition().y,
                                      this->right->O.x - this->getPosition().x) + M_PI;
        angleArchBalloon = atan2f(balloon.getPosition().y - this->right->O.y,
                                        balloon.getPosition().x - this->right->O.x);
        angleArchMin = angleArchRight - M_PI;
        distanceBalloonToArch = sqrtf(powf(this->right->O.x - balloon.getPosition().x, 2) +
                                      powf(this->right->O.y - balloon.getPosition().y, 2));
        if(angleArchBalloon >= angleArchMin && angleArchBalloon <= angleArchRight)
            if (distanceBalloonToArch < balloon.getRadius() + this->right->getRadius())
                return true;
        
        Arch* archs[] = {this->left, this->right};
        for(auto* arch : archs)
        {
            sf::Vector2<float> p0 = this->getPosition();
            sf::Vector2<float> pt = arch->O + arch->O - p0;
            float distanceToP0 = sqrtf(powf(balloon.getPosition().x - p0.x, 2) +
                                       powf(balloon.getPosition().y - p0.y, 2));
            float distanceToPt = sqrtf(powf(balloon.getPosition().x - pt.x, 2) +
                                       powf(balloon.getPosition().y - pt.y, 2));
            if(distanceToP0 < balloon.getRadius() || distanceToPt < balloon.getRadius())
                return true;
            
            float angleP0Balloon = atan2f(balloon.getPosition().y - p0.y,
                                          balloon.getPosition().x - p0.x);
            float angleP0Pt = atan2f(pt.y - p0.y, pt.x - p0.x);
            float angleP0 = fabsf(angleP0Balloon - angleP0Pt);
            float anglePtBalloon = atan2f(balloon.getPosition().y - pt.y,
                                          balloon.getPosition().x - pt.x);
            float anglePtP0 = atan2f(p0.y - pt.y, p0.x - pt.x);
            float anglePt = fabsf(anglePtBalloon - anglePtP0);
            if(angleP0 > M_PI / 2 || anglePt > M_PI / 2)
                return false;
            float distance = fabsf(sinf(angleP0) * distanceToP0);
            if(distance < balloon.getRadius())
                return true;
        }
        return false;
    }
    
    // Arch
    
    Fingers::Arch::Arch(const sf::Vector2<float>& C, const sf::Vector2<float>& O)
    : Pendulum(C, O)
    {}
    
    sf::Vector2f Fingers::Arch::getPoint(unsigned int index) const
    {
        if (index > this->getPointCount() / 2) {
            return this->getPoint(index - this->getPointCount() / 2);
        }
        return this->CircleShape::getPoint(index);
    }
    
    void Fingers::Arch::setPosition(float x, float y)
    {
        this->setPosition(sf::Vector2<float>(x, y));
    }
    
    void Fingers::Arch::setPosition(const sf::Vector2<float> &position)
    {
        this->move(position - this->getPosition());
    }
    
    void Fingers::Arch::rotate(float angle)
    {
        this->sf::Transformable::rotate(angle);
        this->transform(sf::Vector2<float>(0, 0), angle);
    }
    
    void Fingers::Arch::move(float offsetX, float offsetY)
    {
        this->move(sf::Vector2<float>(offsetX, offsetY));
    }
    
    void Fingers::Arch::move(const sf::Vector2f &offset)
    {
        this->Transformable::move(offset);
        this->transform(offset, 0);
    }

}