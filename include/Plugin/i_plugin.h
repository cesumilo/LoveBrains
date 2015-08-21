/*
** i_plugin.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 30 11:04:27 2015 Guillaume ROBIN
** Last update Fri Aug 21 13:38:00 2015 Guillaume ROBIN
*/

#ifndef I_PLUGIN_H_
# define I_PLUGIN_H_

# include <vector>
# include "Graphics/i_object.h"
# include "Graphics/i_collider.h"
# include "Graphics/i_sensor.h"

/*!
 * \namespace Plugin
 * \brief Contains all the objects and the interfaces of the plugin management.
 */
namespace Plugin
{
  /*!
   * \class IPlugin
   * \brief Define the plugin interface in order to add some stuff to LoveBrains.
   * Mandatory name for the PluginCreator function : "CreatePlugin" !
   */
  class IPlugin
  {
  public:
    /*
    ** Typedef.
    */
    /*
    ** Madatory name for the PluginCreator function : "CreatePlugin"
    ** Example: IPlugin	*CreatePlugin(void);
    */

    /*!
     * \brief Define the function pointer for the creation method.
     */
    typedef IPlugin	*(*PluginCreator)(void);

    /*!
     * \brief Virtual destructor.
     */
    virtual ~IPlugin(void) { }

    /*
    ** Methods.
    */

    /*!
     * \brief Get all the objects contained by the plugin.
     * \return std::vector<Graphics::IObject *>&
     */
    virtual std::vector<Graphics::IObject *>&	getObjects(void) = 0;
    /*!
     * \brief Get all the colliders contained by the plugin.
     * \return std::vector<Graphics::ICollider *>&
     */
    virtual std::vector<Graphics::ICollider *>&	getColliders(void) = 0;
    /*!
     * \brief Get all the sensors contained by the plugin.
     * \return std::vector<Graphics::ISensor *>&
     */
    virtual std::vector<Graphics::ISensor *>&	getSensors(void) = 0;
  };
}

#endif /* !I_PLUGIN_H_ */
