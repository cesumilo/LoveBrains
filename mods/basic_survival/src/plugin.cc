//
// start_plugin.cc for Basic_Survival in /home/robin_f/Programming/Git/CPP/LoveBrains/test/mod_basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Jul 30 16:15:34 2015 Guillaume ROBIN
// Last update Fri Jul 31 16:36:46 2015 Guillaume ROBIN
//

#include "plugin.h"

MyPlugin::MyPlugin(void)
{
  Graphics::IObject	*obj;

  if ((obj = new Circle()))
    _objs.push_back(obj);
  if ((obj = new BasicIA()))
    _objs.push_back(obj);
}

/* Don't need to free memory. The physics engine will do it. */
MyPlugin::~MyPlugin(void)
{
}

std::vector<Graphics::IObject *>&	MyPlugin::getObjects(void)
{
  return (_objs);
}

std::vector<Graphics::ICollider *>&	MyPlugin::getColliders(void)
{
  return (_colls);
}

std::vector<Graphics::ISensor *>&	MyPlugin::getSensors(void)
{
  return (_sensors);
}

extern "C"
{
  Plugin::IPlugin	*CreatePlugin(void)
  {
    return (new MyPlugin());
  }
}
