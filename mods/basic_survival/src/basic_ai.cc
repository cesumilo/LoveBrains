//
// basic_ai.cc for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sat Aug  1 12:35:21 2015 Guillaume ROBIN
// Last update Sat Nov 28 22:01:44 2015 Guillaume ROBIN
//

#include <cmath>

#include "basic_ia.h"
#include "ANN/tools.h"
#include "math_plugin.h"

/*
** Constructor & Destructor.
*/
BasicAI::BasicAI(void): _dead(false), _fitness(0), _angle(0), _time(0),
			_life(BasicAI::LifeType::HIGH)
{
  _position = sf::Vector2f(GANN::RandomDouble(10, 1270), GANN::RandomDouble(10, 710));
  _shape.setPosition(_position);
  _shape.setRadius(DEF_AI_RADIUS);
  if (_texture.loadFromFile("resources/basic_survival/character.png"))
    _shape.setTexture(&_texture);
  else
    _shape.setFillColor(sf::Color::Cyan);
  _field1.setSize(sf::Vector2f(1, 200));
  _field1.setFillColor(sf::Color::Red);
  _field1.rotate(-20);
  _field2.setSize(sf::Vector2f(1, 200));
  _field2.setFillColor(sf::Color::Red);
  _field2.rotate(20);
  _inputs = GANN::Matrix<double>(1, 1, 0);
}

BasicAI::BasicAI(BasicAI const& brain)
{
  _dead = brain.isDead();
  _fitness = brain.getFitness();
  _life = BasicAI::LifeType::HIGH;
  _angle = 0;
  _time = 0;
  _position = sf::Vector2f(GANN::RandomDouble(10, 1270), GANN::RandomDouble(10, 710));
  _shape = brain.getShape();
  _shape.setPosition(_position);
  _brain = brain.getBrain();
  _inputs = GANN::Matrix<double>(_brain.getInfos()[0], 1, 0);
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

BasicAI::LifeType	BasicAI::getLife(void) const
{
  return (_life);
}

double	BasicAI::getRotation(void) const
{
  return (_angle);
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
  if (_brain.getInfos().size() > 0 && index < _brain.getInfos()[0])
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
      _life = BasicAI::LifeType::HIGH;
      break;
    default:
      break;
    }
}

void	BasicAI::decreaseLife(void)
{
  switch (_life)
    {
    case BasicAI::LifeType::LOW:
      _dead = true;
      if (_fitness >= DEATH_SCORE)
	_fitness -= DEATH_SCORE;
      break;
    case BasicAI::LifeType::MEDIUM:
      _life = BasicAI::LifeType::LOW;
      break;
    case BasicAI::LifeType::HIGH:
      _life = BasicAI::LifeType::MEDIUM;
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

static unsigned int	getActivatedNeuron(GANN::Matrix<double> const& outputs)
{
  unsigned int		index = 0;
  double		tmp = 0;

  for (unsigned int i = 0; i < outputs.rows(); ++i)
    {
      if (tmp < outputs(i, 0))
	{
	  tmp = outputs(i, 0);
	  index = i;
	}
    }
  return (index);
}

static void	getStateLife(GANN::Matrix<double>& inputs, BasicAI::LifeType life)
{
  switch (life)
    {
    case BasicAI::LifeType::LOW:
      inputs(INPUT_LIFE, 0) = 1.00;
      break;
    case BasicAI::LifeType::MEDIUM:
      inputs(INPUT_LIFE, 0) = 0.50;
      break;
    case BasicAI::LifeType::HIGH:
      inputs(INPUT_LIFE, 0) = 0.00;
      break;
    }
}

#include <iostream>

void			BasicAI::Update(void)
{
  sf::Vector2f		move(0, 0);
  GANN::Matrix<double>	outputs;
  unsigned int		action = 0;

  _time += _elapsed.asSeconds();
  _fitness += _time;
  // Update Life.
  if (_time >= 2)
    {
      decreaseLife();
      _time = 0; // Have to be removed for the animation.
    }
  if (INPUT_FOOD < _inputs.rows() && _inputs(INPUT_FOOD, 0) >= 0.4)
    _shape.setFillColor(sf::Color::Yellow);
  else
    _shape.setFillColor(sf::Color::Cyan);

  getStateLife(_inputs, _life); // Get life state and put it into neural net.
  // TODO: Animation.
  _brain.Activate(_inputs); // The sensors will stimulate neurons inside the network.
  outputs = _brain.getOutputs(); // Getting the outputs of the network.
  action = getActivatedNeuron(outputs); // Getting action.
  switch (action)
    {
    case 1:
      --_angle;
      _field1.rotate(-1);
      _field2.rotate(-1);
      break;
    case 2:
      ++_angle;
      _field1.rotate(1);
      _field2.rotate(1);
      break;
    case 3:
      move.y = 2;
      _field1.rotate(-1);
      _field2.rotate(-1);
      --_angle;
      break;
    case 4:
      move.y = 2;
      _field1.rotate(1);
      _field2.rotate(1);
      ++_angle;
      break;
    default:
      move.y = 2;
      break;
    }
  move = Math::RotateVector2D(move, _angle) * (_elapsed.asSeconds() * 1);
  _shape.move(move);
  _position = _shape.getPosition();
  if (_position.x < 0)
    _position = sf::Vector2f(1279, _position.y);
  else if (_position.x > 1280)
    _position = sf::Vector2f(1, _position.y);
  if (_position.y < 0)
    _position = sf::Vector2f(_position.x, 719);
  else if (_position.y > 720)
    _position = sf::Vector2f(_position.x, 1);
  _shape.setPosition(_position);
  _inputs = GANN::Matrix<double>(_brain.getInfos()[0], 1, 0);
  _field1.setPosition(sf::Vector2f(_position.x + this->getShape().getRadius(),
				   _position.y + this->getShape().getRadius()));
  _field2.setPosition(sf::Vector2f(_position.x + this->getShape().getRadius(),
				   _position.y + this->getShape().getRadius()));

}

void	BasicAI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  if (!_dead)
    {
      target.draw(_shape, states);
      target.draw(_field1, states);
      target.draw(_field2, states);
    }
}
