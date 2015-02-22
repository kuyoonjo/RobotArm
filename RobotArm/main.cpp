
//
// Disclamer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "RobotBody.h"
#include "UpperArm.h"
#include "LowerArm.h"
#include "Fingers.h"
#include "ResourcePath.hpp"
#include "Config.h"
#include "Balloon.h"


bool moveBody(float, float=0);
bool rotateUpperArm(float);
bool rotateLowerArm(float);
bool rotateFinger(float);


sf::RenderWindow window(ra::Config::videoMode, ra::Config::title);
sf::Font font;
sf::Text help;
ra::RobotBody body;
ra::UpperArm upperArm;
ra::LowerArm lowerArm;
ra::Fingers fingers;
std::vector<ra::Balloon> balloons;

int main(int, char const**)
{
    sf::Clock clock;
    
    // Timer
    sf::Time time = clock.getElapsedTime();
    std::stringstream ssTime;
    sf::String sTime;
    sf::Text timer;
    timer.setFont(font);
    timer.setColor(sf::Color::Black);
    
    // Window
    window.setFramerateLimit(ra::Config::framerateLimit);
    
    // Help text
    font.loadFromFile(resourcePath() + ra::Config::font);
    help.setFont(font);
    help.setCharacterSize(ra::Config::fontSize);
    help.setColor(sf::Color::Black);
    help.setPosition(ra::Config::msgPosition);
    
    // Robot Arm
    
    body.setFillColor(sf::Color::Black);
    moveBody(ra::Config::bodyStartPosition.x, ra::Config::bodyStartPosition.y);
    upperArm.setFillColor(sf::Color::Black);
    lowerArm.setFillColor(sf::Color::Black);
    fingers.setFillColor(sf::Color::Black);
    
    //Balloons
    balloons = ra::Balloon::getRandomBalloons(5, 20,
                                              sf::Vector2<int>(400, 150),
                                              sf::Vector2<int>(300, 300));
    for(auto& balloon : balloons)
        balloon.setFillColor(sf::Color::Blue);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            // Escape pressed : exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
        
        // Timer
        if(!balloons.empty())
        {
            time = clock.getElapsedTime();
            ssTime.str(std::string());
            ssTime << "Time: " << time.asSeconds();
            sTime = ssTime.str();
            timer.setString(sTime);
        }
        
        // Body movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(moveBody(-ra::Config::moveSpeed))
                while(fingers.left->O.x - fingers.left->getRadius() < 0)
                    if(!rotateUpperArm(ra::Config::rotateSpeed))
                        break;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            if(moveBody(ra::Config::moveSpeed))
                while(fingers.right->O.x + fingers.right->getRadius() > window.getSize().x
                      || fingers.left->O.x + fingers.left->getRadius() > window.getSize().x)
                    if(!moveBody(-ra::Config::moveSpeed))
                        break;
        
        // Upper arm rotation
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(rotateUpperArm(-ra::Config::rotateSpeed))
            {
                while(fingers.left->O.x - fingers.left->getRadius() < 0)
                    if(!rotateLowerArm(ra::Config::rotateSpeed))
                        break;
                while(fingers.right->O.y + fingers.right->getRadius() > ra::Config::bodyStartPosition.y
                   || fingers.left->O.x + fingers.left->getRadius() > window.getSize().x)
                    if(!rotateUpperArm(ra::Config::rotateSpeed))
                        break;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(rotateUpperArm(ra::Config::rotateSpeed))
            {
                while(fingers.right->O.y + fingers.right->getRadius() > ra::Config::bodyStartPosition.y
                   || fingers.right->O.x + fingers.right->getRadius() > window.getSize().x)
                    if(!rotateUpperArm(-ra::Config::rotateSpeed))
                        break;
            }
        }
        
        // Lower arm rotation
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(rotateLowerArm(-ra::Config::rotateSpeed))
            {
                while(fingers.left->O.x - fingers.left->getRadius() < 0)
                    rotateUpperArm(ra::Config::rotateSpeed);
                while(fingers.right->O.y + fingers.right->getRadius() > ra::Config::bodyStartPosition.y
                   || fingers.left->O.x + fingers.left->getRadius() > window.getSize().x)
                    if(!rotateLowerArm(ra::Config::rotateSpeed))
                        break;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            if(rotateLowerArm(ra::Config::rotateSpeed))
                while(fingers.right->O.y + fingers.right->getRadius() > ra::Config::bodyStartPosition.y
                   || fingers.right->O.x + fingers.right->getRadius() > window.getSize().x)
                    if(!rotateLowerArm(-ra::Config::rotateSpeed))
                        break;
        
        // Finger rotation
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {}
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            rotateFinger(ra::Config::rotateSpeed);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            rotateFinger(-ra::Config::rotateSpeed);
            while(fingers.left->O.x - fingers.left->getRadius() < 0)
                rotateLowerArm(ra::Config::rotateSpeed);
            while(fingers.right->O.y + fingers.right->getRadius() > ra::Config::bodyStartPosition.y
                  || fingers.right->O.x + fingers.right->getRadius() > window.getSize().x
                  || fingers.left->O.x + fingers.left->getRadius() > window.getSize().x)
                if(!rotateFinger(ra::Config::rotateSpeed))
                    break;
        }
        
        // Update position
        upperArm.setPosition(body.O);
        lowerArm.setPosition(upperArm.O);
        fingers.setPosition(lowerArm.O);
        
        
        // Status
        std::stringstream ss;
        ss.precision(3);
        ss << "Body x=" << body.getPosition().x << " y=" << body.getPosition().y << "\t";
        ss << "Upper x=" << upperArm.getPosition().x << " y=" << upperArm.getPosition().y << " ";
        ss << "rotation=" << upperArm.getRotation() << "\t";
        ss << "Lower x=" << lowerArm.getPosition().x << " y=" << lowerArm.getPosition().y << " ";
        ss << "rotation=" << lowerArm.getRotation() << "\n";
        ss << "Finger x=" << fingers.getPosition().x << " y=" << fingers.getPosition().y << " ";
        ss << "rotation=" << fingers.getRotation() << "\n";
        ss << "Left x=" << fingers.left->O.x << " y=" << fingers.left->O.y << " ";
        ss << "rotation=" << fingers.left->getRotation() << " ";
        ss << "Right x=" << fingers.right->O.x << " y=" << fingers.right->O.y << " ";
        ss << "rotation=" << fingers.right->getRotation();
        help.setString(ss.str());
        
        //Pop balloon
        
        balloons.erase(std::remove_if(balloons.begin(), balloons.end(), [&](const ra::Balloon& balloon)
                                      {
                                          return fingers.interacts(balloon);
                                      }), balloons.end());
        
        // Clear screen
        window.clear(sf::Color::White);
        window.draw(timer);
        window.draw(help);
        window.draw(body);
        window.draw(upperArm);
        window.draw(fingers);
        window.draw(lowerArm);
        for(auto& balloon : balloons)
            window.draw(balloon);
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}

bool moveBody(float x, float y)
{
    float m = body.getPosition().x + x;
    if (m >= ra::Config::bodyLimit.x && m <= ra::Config::bodyLimit.y)
    {
        body.move(x, y);
        upperArm.setPosition(body.O);
        lowerArm.setPosition(upperArm.O);
        fingers.setPosition(lowerArm.O);
        return true;
    }
    return false;
}

bool rotateUpperArm(float rotate)
{
    
    float r = upperArm.getRotation() + rotate;
    r = r > ra::Config::halfPI ? r - ra::Config::PI : r;
    if (r >= ra::Config::upperArmLimit.x && r <= ra::Config::upperArmLimit.y)
    {
        upperArm.rotate(rotate);
        lowerArm.rotate(rotate);
        fingers.rotate(rotate);
        return true;
    }
    return false;
}

bool rotateLowerArm(float rotate)
{
    float ru = upperArm.getRotation();
    float rl = lowerArm.getRotation() + rotate;
    float r = rl - ru;
    if (r > ra::Config::halfPI) {
        r -= ra::Config::PI;
    }
    else if(r < -ra::Config::halfPI)
    {
        r += ra::Config::PI;
    }
    if (r >= ra::Config::lowerArmLimit.x && r <= ra::Config::lowerArmLimit.y)
    {
        lowerArm.rotate(rotate);
        fingers.rotate(rotate);
        return true;
    }
    return false;
}

bool rotateFinger(float rotate)
{
    float r = fingers.left->getRotation() - fingers.right->getRotation();
    r += rotate * 2;
    if(r < 0)
        r += ra::Config::PI;
    if (r >= ra::Config::fingerLimit.x && r <= ra::Config::fingerLimit.y)
    {
        fingers.left->rotate(rotate);
        fingers.right->rotate(-rotate);
        return true;
    }
    return false;
}
