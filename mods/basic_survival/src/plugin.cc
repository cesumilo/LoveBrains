//
// plugin.cc for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sat Aug  1 11:58:27 2015 Guillaume ROBIN
// Last update Sat Aug  1 14:34:26 2015 Guillaume ROBIN
//

#include "plugin.h"
#include "basic_ia.h"
#include "food.h"
#include "ai_food_collider.h"

/*
** Constructor & Destructor.
*/
BasicSurvival::BasicSurvival(void)
{
  Graphics::IObject	*ptr;
  Graphics::ICollider	*coll;

  // TODO: Add objects, colliders and sensors.
  if ((ptr = new BasicFood()))
    _objects.push_back(ptr);
  if ((ptr = new BasicAI()))
    _objects.push_back(ptr);

  if ((coll = new ColliderAIAndFood()))
    _colliders.push_back(coll);
}

BasicSurvival::~BasicSurvival(void)
{
  // TODO: Nothing to do. LoveBrains will do the job.
}

/*
** Methods.
*/
std::vector<Graphics::IObject *>&	BasicSurvival::getObjects(void)
{
  return (_objects);
}

std::vector<Graphics::ICollider *>&	BasicSurvival::getColliders(void)
{
  return (_colliders);
}

std::vector<Graphics::ISensor *>&	BasicSurvival::getSensors(void)
{
  return (_sensors);
}

extern "C"
{
  Plugin::IPlugin	*CreatePlugin(void)
  {
    return (new BasicSurvival());
  }
}
