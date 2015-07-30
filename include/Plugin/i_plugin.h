/*
** i_plugin.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 30 11:04:27 2015 Guillaume ROBIN
** Last update Thu Jul 30 18:42:07 2015 Guillaume ROBIN
*/

#ifndef I_PLUGIN_H_
# define I_PLUGIN_H_

# include <vector>
# include "Graphics/i_object.h"
# include "Graphics/i_collider.h"
# include "Graphics/i_sensor.h"

namespace Plugin
{
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
    typedef IPlugin	*(*PluginCreator)(void);

    virtual ~IPlugin(void) { }

    /*
    ** Methods.
    */
    virtual std::vector<Graphics::IObject *>&	getObjects(void) = 0;
    virtual std::vector<Graphics::ICollider *>&	getColliders(void) = 0;
    virtual std::vector<Graphics::ISensor *>&	getSensors(void) = 0;
  };
}

#endif /* !I_PLUGIN_H_ */
