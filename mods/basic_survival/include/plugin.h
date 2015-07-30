/*
** plugin.h for Basic_Survival in /home/robin_f/Programming/Git/CPP/LoveBrains/test/mod_basic_survival
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 30 16:16:31 2015 Guillaume ROBIN
** Last update Thu Jul 30 18:41:02 2015 Guillaume ROBIN
*/

#ifndef PLUGIN_H_
# define PLUGIN_H_

# include "circle.h"
# include "Plugin/i_plugin.h"

class MyPlugin : public Plugin::IPlugin
{
 public:
  MyPlugin(void);
  virtual ~MyPlugin(void);

  /*
  ** Methods.
  */
  std::vector<Graphics::IObject *>&	getObjects(void);
  std::vector<Graphics::ICollider *>&	getColliders(void);
  std::vector<Graphics::ISensor *>&	getSensors(void);

 private:
  std::vector<Graphics::IObject *>	_objs;
  std::vector<Graphics::ICollider *>	_colls;
  std::vector<Graphics::ISensor *>	_sensors;
};

#endif /* !PLUGIN_H_ */
