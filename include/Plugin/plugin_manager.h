/*
** plugin_manager.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 30 11:47:22 2015 Guillaume ROBIN
** Last update Fri Aug 21 14:04:47 2015 Guillaume ROBIN
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
  /*!
   * \class PluginManager
   * \brief Manage the plugins loading.
   */
  class PluginManager
  {
  public:
    /*!
     * \brief Constructor.
     */
    PluginManager(void) throw();
    /*!
     * \brief Destructor.
     */
    ~PluginManager(void) throw();

    /*
    ** Methods.
    */

    /*!
     * \brief Load all the plugins contained in the "mods" directory.
     * \return error : PluginException
     */
    void	LoadPlugins(void);
    /*!
     * \brief Load all the objects contained in the plugin.
     * \return error : PluginException
     */
    void	LoadObjects(void);
    /*!
     * \brief Load all the colliders contained in the plugin.
     * \return error : PluginException
     */
    void	LoadColliders(Graphics::Physics& physics);

    /*!
     * \brief Load all the sensors contained in the plugin.
     * \return error : PluginException
     */
    void	LoadSensors(Graphics::Physics& physics);
    /*!
     * \brief Close all the plugins.
     * \return error : PluginException
     */
    void	ClosePlugins(void);

  private:
    std::vector<IPlugin *>	_plugs; /*!< Contains all the plugins. */
    std::vector<void *>		_handlers; /*!< Contains the handlers of dlopen function */
  };
}

#endif /* !PLUGIN_MANAGER_H_ */
