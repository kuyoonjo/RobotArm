//
//  EllipseShape.cpp
//  YCTools
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#include "EllipseShape.h"

namespace yc
{
    namespace sfml
    {
        EllipseShape::EllipseShape(const sf::Vector2f& radius) :
        radius(radius)
        {
            update();
        }
        
        void EllipseShape::setRadius(const sf::Vector2f& radius)
        {
            this->radius = radius;
            update();
        }
        
        const sf::Vector2f& EllipseShape::getRadius() const
        {
            return this->radius;
        }
        
        unsigned int EllipseShape::getPointCount() const
        {
            return 300; // fixed, but could be an attribute of the class if needed
        }
        sf::Vector2f EllipseShape::getPoint(unsigned int index) const
        {
            float angle = index * 2 * M_PI / getPointCount() - M_PI / 2;
            float x = std::cos(angle) * this->radius.x;
            float y = std::sin(angle) * this->radius.y;
            
            return sf::Vector2f(this->radius.x + x, this->radius.y + y);
        }
    }
}