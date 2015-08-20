/*
** factory_object.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 13:55:29 2015 Guillaume ROBIN
** Last update Thu Jul 30 17:08:52 2015 Guillaume ROBIN
*/

#ifndef FACTORY_OBJECT_H_
# define FACTORY_OBJECT_H_

# include <map>
# include "Graphics/i_object.h"

namespace Graphics
{
  class FactoryObjects
  {
  public:
    FactoryObjects(void);
    ~FactoryObjects(void);

    static void	Register(std::string const& key, IObject* obj);
    static void	DeleteAll(void);
    IObject	*Create(std::string const& key) const;
    bool	Contains(std::string const& key) const;

  private:
    static std::map<std::string, IObject *>	_map;
  };
}

#endif /* !FACTORY_OBJECT_H_ */
