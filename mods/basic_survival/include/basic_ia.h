/*
** basic_ia.h for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sat Aug  1 12:30:15 2015 Guillaume ROBIN
** Last update Wed Aug 19 12:11:22 2015 Guillaume ROBIN
*/

#ifndef BASIC_IA_H_
# define BASIC_IA_H_

# include "Graphics/i_brain.h"

/* TODO:  Move the define */
# define MAX_ACTIVATION		(double)1.00
# define FOOD_SCORE		(double)1.00
# define DEATH_SCORE		(double)-1.00
/* Neural net : 2-2-5 */
# define INPUT_FOOD		(unsigned int)0
# define INPUT_LIFE		(unsigned int)1

# define DEF_AI_RADIUS		(float)10
# define DEF_AI_VISION_RADIUS	(float)2

class BasicAI : public Graphics::IBrain
{
 public:
  enum class LifeType { LOW, MEDIUM, HIGH };

  BasicAI(void);
  BasicAI(BasicAI const& brain);
  ~BasicAI(void);

  /*
  ** Getters.
  */
  bool				isDead(void) const;
  bool				hasBrain(void) const;
  std::string			getType(void) const;
  double			getFitness(void) const;
  GANN::ANN const&		getBrain(void) const;
  sf::CircleShape const&	getShape(void) const;
  sf::Vector2f const&		getPosition(void) const;
  BasicAI::LifeType    		getLife(void) const;
  double			getRotation(void) const;

  /*
  ** Setters.
  */
  void	setPosition(sf::Vector2f const& position);
  void	setIsDead(bool dead);
  void	setElapsedTime(sf::Time& time);
  void	setFitness(double fitness);
  void	setBrain(GANN::ANN const& brain);
  void	setInput(unsigned int index, double value);
  void	increaseLife(void);
  void	decreaseLife(void);

  /*
  ** Methods.
  */
  Graphics::IObject	*Clone(void);
  void			Update(void);

 private:
  bool			_dead;
  double		_fitness;
  double		_angle;
  float			_time;
  LifeType		_life;
  sf::Vector2f		_position;
  sf::Time		_elapsed;
  sf::CircleShape	_shape;
  GANN::ANN		_brain;
  GANN::Matrix<double>	_inputs;

  sf::CircleShape	_vfield1;
  sf::CircleShape	_vfield2;

  void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* !BASIC_IA_H_ */
