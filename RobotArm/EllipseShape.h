//
//  EllipseShape.h
//  YCTools
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#ifndef __RobotArm__EllipseShape__
#define __RobotArm__EllipseShape__

#include <SFML/Graphics.hpp>
#include <cmath>

namespace yc
{
    namespace sfml
    {
        class EllipseShape : public sf::Shape
        {
        public :
            explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0, 0));
            void setRadius(const sf::Vector2f& radius);
            const sf::Vector2f& getRadius() const;
            virtual unsigned int getPointCount() const override;
            virtual sf::Vector2f getPoint(unsigned int index) const override;
            
        private :
            sf::Vector2f radius;
        };
    }
}

#endif /* defined(__RobotArm__EllipseShape__) */
