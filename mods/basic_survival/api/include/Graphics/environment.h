/*
** environment.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 23 11:39:20 2015 Guillaume ROBIN
** Last update Wed Aug 19 12:52:15 2015 Guillaume ROBIN
*/

#ifndef ENVIRONMENT_H_
# define ENVIRONMENT_H_

# include <SFML/Graphics.hpp>

# include "Graphics/i_object.h"
# include "Graphics/i_brain.h"
# include "Graphics/physics.h"
# include "GA/a_observable.h"

namespace Graphics
{
  class Environment : public GA::AObservable
  {
  public:
    Environment(void);
    Environment(unsigned int width, unsigned int height);
    ~Environment(void);

    /*
    ** Getters.
    */
    std::list<IObject *> const&	getObjects(void) const;
    std::list<IObject *>&	getObjects(void);
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
    void	Run(std::list<GA::IDNA *>& brains);

  private:
    unsigned int			_num_epochs;
    std::list<IObject *>		_env;
    sf::Font				_font;
    sf::Text				_best_fitness;
    sf::Text				_avg_fitness;
    sf::Text				_epochs;
    Physics				_physics;
    static sf::RenderWindow		_window;

    void	UpdateInfos(void);
  };
}

#endif /* !ENVIRONMENT_H_ */
