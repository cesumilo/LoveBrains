/*
** plugin_manager.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 30 11:47:22 2015 Guillaume ROBIN
** Last update Thu Jul 30 19:19:09 2015 Guillaume ROBIN
*/

#ifndef PLUGIN_MANAGER_H_
# define PLUGIN_MANAGER_H_

# include <vector>

# include "Plugin/i_plugin.h"
# include "Plugin/plugin_exception.h"
# include "Graphics/physics.h"
# include "Graphics/factory_object.h"

namespace Plugin
{
  class PluginManager
  {
  public:
    PluginManager(void) throw();
    ~PluginManager(void) throw();

    /*
    ** Methods.
    */
    void	LoadPlugins(void);
    void	LoadObjects(void);
    void	LoadColliders(Graphics::Physics& physics);
    void	LoadSensors(Graphics::Physics& physics);
    void	ClosePlugins(void);

  private:
    std::vector<IPlugin *>	_plugs;
    std::vector<void *>		_handlers;
  };
}

#endif /* !PLUGIN_MANAGER_H_ */
