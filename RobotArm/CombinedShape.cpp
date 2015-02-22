//
//  CombinedShape.cpp
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#include "CombinedShape.h"

namespace ra
{
    void CombinedShape::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        for (auto i = this->shapes.begin(); i != this->shapes.end(); i ++)
        {
            target.draw(*(i->second), states);
        }
    }
    
    CombinedShape::CombinedShape(const sf::Vector2<float>& C,
                                 const sf::Vector2<float>& O)
    :
    Pendulum(C, O)
    {
    }
    
    void CombinedShape::add(int index, sf::Shape* shape)
    {
        this->shapes[index] = shape;
    }
    
    void CombinedShape::setFillColor(const sf::Color &color)
    {
        for (auto i = this->shapes.begin(); i != this->shapes.end(); i ++)
        {
            i->second->setFillColor(color);
        }
    }
    
    void CombinedShape::setPosition(float x, float y)
    {
        this->setPosition(sf::Vector2<float>(x, y));
    }
    
    void CombinedShape::setPosition(const sf::Vector2<float> &position)
    {
        this->move(position - this->getPosition());
    }
    
    void CombinedShape::rotate(float angle)
    {
        this->sf::Transformable::rotate(angle);
        for (auto i = this->shapes.begin(); i != this->shapes.end(); i ++)
        {
            i->second->rotate(angle);
        }
        this->transform(sf::Vector2<float>(0, 0), angle);
    }
    
    void CombinedShape::move(float offsetX, float offsetY)
    {
        this->move(sf::Vector2<float>(offsetX, offsetY));
    }
    
    void CombinedShape::move(const sf::Vector2f &offset)
    {
        this->Transformable::move(offset);
        for (auto i = this->shapes.begin(); i != this->shapes.end(); i ++)
        {
            i->second->move(offset);
        }
        this->transform(offset, 0);
    }
    
}