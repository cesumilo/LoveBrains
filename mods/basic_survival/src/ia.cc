//
// ia.cc for basic_survival in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Fri Jul 31 16:15:45 2015 Guillaume ROBIN
// Last update Fri Jul 31 18:43:07 2015 Guillaume ROBIN
//

#include "ia.h"

/*
** Constructor & Destructor.
*/
BasicIA::BasicIA(void): _dead(false), _fitness(0)
{
}

BasicIA::BasicIA(BasicIA const& ia)
{
  _dead = ia.isDead();
  _fitness = ia.getFitness();
}

BasicIA::~BasicIA(void)
{
}

/*
** Getters.
*/
bool	BasicIA::isDead(void) const
{
  return (_dead);
}

bool	BasicIA::hasBrain(void) const
{
  return (true);
}

std::string	BasicIA::getType(void) const
{
  return (std::string("basic_ia"));
}

double	BasicIA::getFitness(void) const
{
  return (_fitness);
}

/*
** Setters.
*/
void	BasicIA::setPosition(sf::Vector2f const& position)
{
  _position = position;
}

void	BasicIA::setIsDead(bool dead)
{
  _dead = dead;
}

void	BasicIA::setElapsedTime(sf::Time& time)
{
  _elapsed = time;
}

void	BasicIA::setFitness(double fitness)
{
  _fitness = fitness;
}

void	BasicIA::setBrain(GANN::ANN const& brain)
{
  if (brain.getInfos().size() > 0)
    _inputs = GANN::Matrix<double>(brain.getInfos()[0], 1, 0);
  _brain = brain;
}

void	BasicIA::setInput(unsigned int index, double value)
{
  _inputs(index, 1) = value;
}

/*
** Methods.
*/
Graphics::IObject	*BasicIA::Clone(void)
{
  return (new BasicIA(*this));
}

void	BasicIA::Update(void)
{
}

void	BasicIA::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
