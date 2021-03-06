/*
** food.h for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sat Aug  1 12:03:54 2015 Guillaume ROBIN
** Last update Sat Nov 28 12:36:26 2015 Guillaume ROBIN
*/

#ifndef FOOD_H_
# define FOOD_H_

# include "Graphics/i_object.h"

class BasicFood : public Graphics::IObject
{
 public:
  BasicFood(void);
  ~BasicFood(void);

  /*
  ** Getters.
  */
  bool			isDead(void) const;
  bool			hasBrain(void) const;
  std::string		getType(void) const;
  sf::Vector2f const&	getPosition(void) const;
  float			getRadius(void) const;

  /*
  ** Setters.
  */
  void	setPosition(sf::Vector2f const& position);
  void	setIsDead(bool dead);
  void	setElapsedTime(sf::Time& time);

  /*
  ** Methods.
  */
  Graphics::IObject	*Clone(void);
  void			Update(void);

 private:
  bool			_dead;
  float			_time;
  sf::Time		_elapsed;
  sf::CircleShape	_shape;
  sf::Texture		_texture;

  void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* !FOOD_H_ */
