//
//  Pendulum.cpp
//  SolarSystem
//
//  Created by Yu Chen on 10/28/14.
//  Copyright (c) 2014 Yu Chen. All rights reserved.
//

#include "Pendulum.h"

namespace ss
{
    Pendulum::Pendulum(const sf::Vector2<float>& C, const sf::Vector2<float>& O)
    {
        this->C = C;
        this->_O_ = O;
        this->_R_ = 0;
        this->transform(sf::Vector2<float>(0, 0), 0);
    }
    
    void Pendulum::transform(const sf::Vector2<float> &vel, float rot)
    {
        sf::Transform T;
        sf::Transform R;
        sf::Transform M;
        
        this->C += vel;
        T.translate(this->C);
        this->_R_ += rot;
        R.rotate(this->_R_);
        
        M = T * R;
        
        this->O = M.transformPoint(this->_O_);
    }
}