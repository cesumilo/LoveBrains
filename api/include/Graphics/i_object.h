/*
** a_object.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 12:05:50 2015 Guillaume ROBIN
** Last update Thu Jul 30 18:30:10 2015 Guillaume ROBIN
*/

#ifndef I_OBJECT_H_
# define I_OBJECT_H_

# include <vector>
# include <string>
# include <SFML/Graphics.hpp>

namespace Graphics
{
  class IObject : public sf::Drawable
  {
  public:
    virtual ~IObject(void) { }

    /*
    ** Getters.
    */
    virtual bool	       	isDead(void) const = 0;
    virtual std::string		getType(void) const = 0;

    /*
    ** Setters.
    */
    virtual void	setPosition(sf::Vector2f const& position) = 0;
    virtual void	setIsDead(bool condition) = 0;
    virtual void	setElapsedTime(sf::Time& time) = 0;

    /*
    ** Methods.
    */
    virtual IObject	*Clone(void) = 0;
    virtual void	Update(void) = 0;

  protected:
    virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
  };
}

#endif /* !A_OBJECT_H_ */
