/*
** ia.h for basic_survival in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri Jul 31 16:16:10 2015 Guillaume ROBIN
** Last update Fri Jul 31 16:34:42 2015 Guillaume ROBIN
*/

#ifndef IA_H_
# define IA_H_

# include "Graphics/i_brain.h"
# include "ANN/matrix.h"

class BasicIA : public Graphics::IBrain
{
 public:
  BasicIA(void);
  BasicIA(BasicIA const& ia);
  ~BasicIA(void);

  /*
  ** Getters.
  */
  bool		isDead(void) const;
  bool		hasBrain(void) const;
  std::string	getType(void) const;
  double	getFitness(void) const;

  /*
  ** Setters.
  */
  void	setPosition(sf::Vector2f const& position);
  void	setIsDead(bool is_dead);
  void	setElapsedTime(sf::Time& time);
  void	setFitness(double fitness);
  void	setBrain(GANN::ANN const& brain);
  void	setInput(unsigned int index, double value);

  /*
  ** Methods.
  */
  IObject	*Clone(void);
  void		Update(void);

 private:
  bool			_dead;
  double		_fitness;
  GANN::Matrix<double>	_inputs;
  GANN::ANN		_brain;
  sf::Time		_elapsed;
  sf::Vector2f		_position;

  void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* !IA_H_ */
