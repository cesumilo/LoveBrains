//
// factory_object.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Wed Jul 22 13:56:26 2015 Guillaume ROBIN
// Last update Thu Jul 30 17:08:34 2015 Guillaume ROBIN
//

#include <cstdlib>
#include <iostream>

#include "Graphics/factory_object.h"
#include "Graphics/graphics_const.h"

namespace Graphics
{
  /*
  ** Static variables.
  */
  std::map<std::string, IObject *>	FactoryObjects::_map = std::map<std::string, IObject *>();

  /*
  ** Constructor & Destructor.
  */
  FactoryObjects::FactoryObjects(void)
  {
  }

  FactoryObjects::~FactoryObjects(void)
  {
  }

  /*
  ** Methods.
  */
  void	FactoryObjects::Register(std::string const& key, IObject *obj)
  {
    if (obj)
      {
	if (_map.find(key) == _map.end())
	  _map[key] = obj;
	else
	  std::cerr << ERR_OFACTORY_REGKEY << std::endl;
      }
    else
      std::cerr << ERR_OFACTORY_REGISTER << std::endl;
  }

  void	FactoryObjects::DeleteAll(void)
  {
    for (std::map<std::string, IObject *>::iterator it = _map.begin(); it != _map.end(); ++it)
      delete (it->second);
  }

  IObject	*FactoryObjects::Create(std::string const& key) const
  {
    IObject	*ptr = NULL;
    std::map<std::string, IObject *>::const_iterator it = _map.find(key);

    if (it != _map.end())
      ptr = it->second->Clone();
    return (ptr);
  }

  bool	FactoryObjects::Contains(std::string const& key) const
  {
    return (_map.find(key) != _map.end());
  }
}
