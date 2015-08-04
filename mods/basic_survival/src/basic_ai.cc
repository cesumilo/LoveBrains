//
// basic_ai.cc for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sat Aug  1 12:35:21 2015 Guillaume ROBIN
// Last update Tue Aug  4 12:28:44 2015 Guillaume ROBIN
//

#include <cmath>

#include "basic_ia.h"
#include "ANN/tools.h"

/*
** Constructor & Destructor.
*/
BasicAI::BasicAI(void): _dead(false), _fitness(0), _angle(0), _time(0),
			_life(BasicAI::LifeType::HIGH)
{
  _position = sf::Vector2f(GANN::RandomDouble(10, 1270), GANN::RandomDouble(10, 710));
  _shape.setPosition(_position);
  _shape.setRadius(25);
  _shape.setFillColor(sf::Color::Cyan);
}

BasicAI::BasicAI(BasicAI const& brain)
{
  _dead = brain.isDead();
  _fitness = brain.getFitness();
  _position = sf::Vector2f(GANN::RandomDouble(10, 1270), GANN::RandomDouble(10, 710));
  _shape = brain.getShape();
  _brain = brain.getBrain();
}

BasicAI::~BasicAI(void)
{
}

/*
** Getters.
*/
bool	BasicAI::isDead(void) const
{
  return (_dead);
}

bool	BasicAI::hasBrain(void) const
{
  return (true);
}

std::string	BasicAI::getType(void) const
{
  return (std::string("basic_survival_ai"));
}

double	BasicAI::getFitness(void) const
{
  return (_fitness);
}

GANN::ANN const&	BasicAI::getBrain(void) const
{
  return (_brain);
}

sf::CircleShape const&	BasicAI::getShape(void) const
{
  return (_shape);
}

sf::Vector2f const&	BasicAI::getPosition(void) const
{
  return (_position);
}

BasicAI::TypeLife	BasicAI::getLife(void) const
{
  return (_life);
}

/*
** Setters.
*/
void	BasicAI::setPosition(sf::Vector2f const& position)
{
  _position = position;
}

void	BasicAI::setIsDead(bool dead)
{
  _dead = dead;
}

void	BasicAI::setElapsedTime(sf::Time& time)
{
  _elapsed = time;
}

void	BasicAI::setFitness(double fitness)
{
  _fitness = fitness;
}

void	BasicAI::setBrain(GANN::ANN const& brain)
{
  if (brain.getInfos().size() > 0)
    _inputs = GANN::Matrix<double>(brain.getInfos()[0], 1, 0);
  _brain = brain;
}

void	BasicAI::setInput(unsigned int index, double value)
{
  if (index < _brain.getInfos().size())
    _inputs(index, 0) = value;
}

void	BasicAI::increaseLife(void)
{
  switch (_life)
    {
    case BasicAI::LifeType::LOW:
      _life = BasicAI::LifeType::MEDIUM;
      break;
    case BasicAI::LifeType::MEDIUM:
      _life = BasicAI::TypeLife:HIGH;
      break;
    default:
      break;
    }
}

void	BasicAI::decreaseLife(void)
{
  switch (_life)
    {
    case BasicAI::TypeLife::LOW:
      _dead = true;
      break;
    case BasicAI::TypeLife::MEDIUM:
      _life = BasicAI::TypeLife::LOW;
      break;
    case BasicAI::TypeLife::HIGH:
      _life = BasicAI::TypeLife::MEDIUM;
      break;
    }
}


/*
** Methods.
*/
Graphics::IObject	*BasicAI::Clone(void)
{
  return (new BasicAI());
}

// TODO: Move the rotate function somewhere.
static void	RotateVector2f(sf::Vector2f& vect, double angle)
{
  float		x = vect.x;
  float		y = vect.y;

  vect.x = x * cos(angle) - y * sin(angle);
  vect.y = y * cos(angle) + x * sin(angle);
}

void		BasicAI::Update(void)
{
  sf::Vector2f	move(0, 2);

  _time += _elapsed.asSeconds();
  // Update Life.
  if (_time >= 1)
    decreaseLife();
  // TODO: Move the AI.
  if (_time > 0.01)
    {
      // Moving.
      if (GANN::RandomInt(0, 2) == 0)
	_angle += 1;
      else
	_angle -= 1;
      RotateVector2f(move, _angle * 180 / PI);
      _shape.move(move);
      _position = _shape.getPosition();
      _time = 0;
    }
  // TODO: Animate the AI.
}

void	BasicAI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  target.draw(_shape, states);
}
