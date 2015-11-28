/*
** background.h for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sat Nov 28 13:31:01 2015 Guillaume ROBIN
** Last update Sat Nov 28 13:56:36 2015 Guillaume ROBIN
*/

#ifndef BACKGROUND_H_
# define BACKGROUND_H_

# include "Graphics/i_object.h"

class BasicBackground : public Graphics::IObject
{
 public:
  BasicBackground(void);
  ~BasicBackground(void);

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
  void			setPosition(sf::Vector2f const& position);
  void			setIsDead(bool dead);
  void			setElapsedTime(sf::Time& time);

  /*
  ** Methods.
  */
  Graphics::IObject	*Clone(void);
  void			Update(void);

 private:
  bool			_dead;
  float			_time;
  sf::Time		_elapsed;
  sf::RectangleShape	_shape;
  sf::Texture		_texture;

  void	draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* !BACKGROUND_H_ */
