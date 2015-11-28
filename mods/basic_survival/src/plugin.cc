//
// plugin.cc for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sat Aug  1 11:58:27 2015 Guillaume ROBIN
// Last update Sat Nov 28 13:55:04 2015 Guillaume ROBIN
//

#include "plugin.h"
#include "basic_ia.h"
#include "food.h"
#include "background.h"
#include "ai_food_collider.h"
#include "ai_vision_field.h"

/*
** Constructor & Destructor.
*/
BasicSurvival::BasicSurvival(void)
{
  Graphics::IObject	*ptr;
  Graphics::ICollider	*coll;
  Graphics::ISensor	*sensor;

  // TODO: Add objects, colliders and sensors.
  if ((ptr = new BasicFood()))
    _objects.push_back(ptr);
  if ((ptr = new BasicAI()))
    _objects.push_back(ptr);
  if ((ptr = new BasicBackground()))
    _objects.push_back(ptr);

  if ((coll = new ColliderAIAndFood()))
    _colliders.push_back(coll);

  if ((sensor = new AIVisionField()))
    _sensors.push_back(sensor);
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
