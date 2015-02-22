//
//  CombinedShape.h
//  RobotArm
//
//  Created by Yu Chen on 11/22/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#ifndef __RobotArm__CombinedShape__
#define __RobotArm__CombinedShape__

#include <map>
#include <SFML/Graphics.hpp>
#include "Pendulum.h"

namespace ra
{
    class CombinedShape : public sf::Drawable, public sf::Transformable, public ss::Pendulum
    {
    private:
        std::map<int, sf::Shape*> shapes;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    public:
        explicit CombinedShape(const sf::Vector2<float>& C = sf::Vector2<float>(0,0),
                      const sf::Vector2<float>& O = sf::Vector2<float>(0,0));
        void add(int index, sf::Shape*);
        void setFillColor(const sf::Color& color);
        void setPosition(float x, float y);
        void setPosition(const sf::Vector2<float>& position);
        void rotate(float angle);
        void move(float offsetX, float offsetY);
        void move(const sf::Vector2f& offset);
    };
}

#endif /* defined(__RobotArm__CombinedShape__) */
