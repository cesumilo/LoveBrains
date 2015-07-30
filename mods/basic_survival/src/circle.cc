//
// trap.cc for Basic_Survival in /home/robin_f/Programming/Git/CPP/LoveBrains/test/mod_basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Jul 30 16:11:24 2015 Guillaume ROBIN
// Last update Thu Jul 30 18:39:11 2015 Guillaume ROBIN
//

#include "ANN/tools.h"
#include "circle.h"

/*
** Constructor & Destructor.
*/
Circle::Circle(void): _dead(false), _angle(0), _scale(1)
{
  _position = sf::Vector2f(GANN::RandomDouble(0, 1280), GANN::RandomDouble(0, 720));
  _shape.setPosition(_position);
  _shape.setRadius((float)GANN::RandomDouble(10, 51));
  _shape.setFillColor(sf::Color::Black);
}

Circle::Circle(Circle const& circle)
{
  _angle = circle.getAngle();
  _scale = circle.getScale();
  _dead = circle.isDead();
  _position = sf::Vector2f(GANN::RandomDouble(0, 1280), GANN::RandomDouble(0, 720));
  _shape.setPosition(_position);
  _shape.setRadius((float)GANN::RandomDouble(10, 51));
  _shape.setFillColor(sf::Color::Black);
}

Circle::~Circle(void)
{
}

/*
** Getters.
*/
bool	Circle::isDead(void) const
{
  return (_dead);
}

std::string	Circle::getType(void) const
{
  return (std::string("circle"));
}

sf::CircleShape const&	Circle::getShape(void) const
{
  return (_shape);
}

sf::Vector2f const&	Circle::getPosition(void) const
{
  return (_position);
}

float	Circle::getAngle(void) const
{
  return (_angle);
}

float	Circle::getScale(void) const
{
  return (_scale);
}

/*
** Setters.
*/
void	Circle::setPosition(sf::Vector2f const& position)
{
  _position = position;
}

void	Circle::setIsDead(bool condition)
{
  _dead = condition;
}

void	Circle::setElapsedTime(sf::Time& time)
{
  _elapsed = time;
}

/*
** Methods.
*/
Graphics::IObject	*Circle::Clone(void)
{
  return (new Circle(*this));
}

void	Circle::Update(void)
{
}

void	Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(_shape, states);
}
