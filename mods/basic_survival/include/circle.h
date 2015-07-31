/*
** trap.h for Basic_Survival in /home/robin_f/Programming/Git/CPP/LoveBrains/test/mod_basic_survival
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 30 16:11:49 2015 Guillaume ROBIN
** Last update Fri Jul 31 16:00:33 2015 Guillaume ROBIN
*/

#ifndef TRAP_H_
# define TRAP_H_

# include "Graphics/i_object.h"

class Circle : public Graphics::IObject
{
public:
  Circle(void);
  Circle(Circle const& circle);
  virtual ~Circle(void);

  /*
  ** Getters.
  */
  bool				isDead(void) const;
  bool				hasBrain(void) const;
  std::string			getType(void) const;
  sf::CircleShape const&	getShape(void) const;
  sf::Vector2f const&		getPosition(void) const;
  float				getAngle(void) const;
  float				getScale(void) const;

  /*
  ** Setters.
  */
  void	setPosition(sf::Vector2f const& position);
  void	setIsDead(bool condition);
  void	setElapsedTime(sf::Time& time);

  /*
  ** Methods.
  */
  Graphics::IObject	*Clone(void);
  void			Update(void);

private:
  bool			_dead;
  double		_angle;
  double		_scale;
  sf::Vector2f		_position;
  sf::Time		_elapsed;
  sf::CircleShape	_shape;

  void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* !TRAP_H_ */
