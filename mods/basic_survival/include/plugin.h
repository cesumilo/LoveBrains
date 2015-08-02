/*
** plugin.h for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sat Aug  1 11:53:28 2015 Guillaume ROBIN
** Last update Sat Aug  1 13:15:01 2015 Guillaume ROBIN
*/

#ifndef PLUGIN_H_
# define PLUGIN_H_

# include "Plugin/i_plugin.h"

class BasicSurvival : public Plugin::IPlugin
{
 public:
  BasicSurvival(void);
  ~BasicSurvival(void);

  /*
  ** Methods.
  */
  std::vector<Graphics::IObject *>&	getObjects(void);
  std::vector<Graphics::ICollider *>&	getColliders(void);
  std::vector<Graphics::ISensor *>&	getSensors(void);

 private:
  std::vector<Graphics::IObject *>	_objects;
  std::vector<Graphics::ICollider *>	_colliders;
  std::vector<Graphics::ISensor *>	_sensors;
};

#endif /* !PLUGIN_H_ */
