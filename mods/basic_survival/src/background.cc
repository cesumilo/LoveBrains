//
// background.cc for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sat Nov 28 13:39:30 2015 Guillaume ROBIN
// Last update Sat Nov 28 22:02:05 2015 Guillaume ROBIN
//

#include "background.h"

/*
** Constructor & Destructor.
*/
BasicBackground::BasicBackground(void): _dead(false), _time(0)
{
  _shape.setPosition(sf::Vector2f(0, 0));
  _shape.setSize(sf::Vector2f(1280, 720));
  if (_texture.loadFromFile("resources/basic_survival/fond.png"))
    _shape.setTexture(&_texture);
}

BasicBackground::~BasicBackground(void)
{
}

/*
** Getters.
*/
bool	BasicBackground::isDead(void) const
{
  return (_dead);
}

bool	BasicBackground::hasBrain(void) const
{
  return (false);
}

std::string	BasicBackground::getType(void) const
{
  return (std::string("basic_background"));
}

sf::Vector2f const&	BasicBackground::getPosition(void) const
{
  return (_shape.getPosition());
}

float	BasicBackground::getRadius(void) const
{
  return (0);
}

/*
** Setters.
*/
void	BasicBackground::setPosition(sf::Vector2f const& position)
{
  _shape.setPosition(position);
}

void	BasicBackground::setIsDead(bool dead)
{
  _dead = dead;
}

void	BasicBackground::setElapsedTime(sf::Time& time)
{
  _elapsed = time;
}

/*
** Methods.
*/
Graphics::IObject	*BasicBackground::Clone(void)
{
  return (new BasicBackground());
}

void	BasicBackground::Update(void)
{
}

void	BasicBackground::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  if (!_dead)
    target.draw(_shape, states);
}
