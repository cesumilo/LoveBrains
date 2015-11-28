//
// food.cc for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sat Aug  1 12:07:53 2015 Guillaume ROBIN
// Last update Sat Nov 28 22:01:54 2015 Guillaume ROBIN
//

#include <iostream>

#include "food.h"
#include "ANN/tools.h"

/*
** Constructor & Destructor.
*/
BasicFood::BasicFood(void): _dead(false), _time(0)
{
  // TODO: Generate random position.
  _shape.setPosition(sf::Vector2f(GANN::RandomDouble(10, 1270), GANN::RandomDouble(10, 710)));
  _shape.setRadius(GANN::RandomDouble(5, 15));
  if (_texture.loadFromFile("resources/basic_survival/food.png"))
    _shape.setTexture(&_texture);
  else
    _shape.setFillColor(sf::Color::Green);
}

BasicFood::~BasicFood(void)
{
}

/*
** Getters.
*/
bool	BasicFood::isDead(void) const
{
  return (_dead);
}

bool	BasicFood::hasBrain(void) const
{
  return (false);
}

std::string	BasicFood::getType(void) const
{
  return (std::string("basic_food"));
}

sf::Vector2f const&	BasicFood::getPosition(void) const
{
  return (_shape.getPosition());
}

float	BasicFood::getRadius(void) const
{
  return (_shape.getRadius());
}

/*
** Setters.
*/
void	BasicFood::setPosition(sf::Vector2f const& position)
{
  _shape.setPosition(position);
}

void	BasicFood::setIsDead(bool dead)
{
  _dead = dead;
}

void	BasicFood::setElapsedTime(sf::Time& time)
{
  _elapsed = time;
}

/*
** Methods.
*/
Graphics::IObject	*BasicFood::Clone(void)
{
  // For now I will create a new food.
  return (new BasicFood());
}

void	BasicFood::Update(void)
{
}

void	BasicFood::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  if (!_dead)
    target.draw(_shape, states);
}
