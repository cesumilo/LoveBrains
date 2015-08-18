//
// basic_ai.cc for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sat Aug  1 12:35:21 2015 Guillaume ROBIN
// Last update Tue Aug 18 15:05:17 2015 Guillaume ROBIN
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
  _shape.setRadius(25);
  _shape.setFillColor(sf::Color::Cyan);
  _vfield1.setRadius(5);
  _vfield2.setRadius(5);
  _vfield1.setFillColor(sf::Color::Red);
  _vfield2.setFillColor(sf::Color::Red);
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

void			BasicAI::Update(void)
{
  sf::Vector2f		move(0, 0);
  GANN::Matrix<double>	outputs;
  unsigned int		action = 0;

  // DEBUG
  sf::Vector2f			velocity(0, 200);
  sf::Vector2f			visionFieldLeft;
  sf::Vector2f			visionFieldRight;
  sf::Vector2f			p2;
  sf::Vector2f			p3;

  velocity = Math::RotateVector2D(velocity, _angle);
  visionFieldLeft = Math::RotateVector2D(velocity, -20);
  visionFieldRight = Math::RotateVector2D(velocity, 20);
  p2.x = _position.x + visionFieldLeft.x;
  p2.y = _position.y + visionFieldLeft.y;
  p3.x = _position.x + visionFieldRight.x;
  p3.y = _position.y + visionFieldRight.y;

  _vfield1.setPosition(p2);
  _vfield2.setPosition(p3);
  // END DEBUG

  _time += _elapsed.asSeconds();
  _fitness += _time;
  // Update Life.
  if (_time >= 1)
    {
      decreaseLife();
      _time = 0; // Have to be removed for the animation.
    }
  if (_inputs(INPUT_FOOD, 0) >= 0.4)
    _shape.setFillColor(sf::Color::Yellow);
  else
    _shape.setFillColor(sf::Color::Cyan);
  // TODO: Animation.
  _brain.Activate(_inputs); // The sensors will stimulate neurons inside the network.
  outputs = _brain.getOutputs(); // Getting the outputs of the network.
  action = getActivatedNeuron(outputs); // Getting action.
  switch (action)
    {
    case 1:
      --_angle;
      break;
    case 2:
      ++_angle;
      break;
    case 3:
      move.y = 2;
      --_angle;
      break;
    case 4:
      move.y = 2;
      ++_angle;
      break;
    default:
      move.y = 2;
      break;
    }
  move = Math::RotateVector2D(move, _angle);
  _shape.move(move);
  _position = _shape.getPosition();
  _inputs = GANN::Matrix<double>(_brain.getInfos()[0], 1, 0);
}

void	BasicAI::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  if (!_dead)
    {
      target.draw(_shape, states);
      target.draw(_vfield1, states);
      target.draw(_vfield2, states);
    }
}
