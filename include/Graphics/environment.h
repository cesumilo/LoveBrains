/*
** environment.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 23 11:39:20 2015 Guillaume ROBIN
** Last update Thu Jul 30 17:13:23 2015 Guillaume ROBIN
*/

#ifndef ENVIRONMENT_H_
# define ENVIRONMENT_H_

# include <SFML/Graphics.hpp>

# include "Graphics/i_object.h"
# include "Graphics/physics.h"

namespace Graphics
{
  class Environment
  {
  public:
    Environment(void);
    Environment(unsigned int width, unsigned int height);
    ~Environment(void);

    /*
    ** Getters.
    */
    std::list<IObject *> const&	getObjects(void) const;
    Physics const&		getPhysics(void) const;
    Physics&			getPhysics(void);
    sf::RenderWindow&		getWindow(void);

    /*
    ** Setters.
    */
    void	LoadFromFile(const char *path);

    /*
    ** Overload.
    */
    Environment&	operator=(Environment const& env);

    /*
    ** Methods.
    */
    void	Update(sf::Time elapsed);
    void	Draw(void);
    void	Run(void);

  private:
    std::list<IObject *>		_env;
    Physics				_physics;
    static sf::RenderWindow		_window;
  };
}

#endif /* !ENVIRONMENT_H_ */
