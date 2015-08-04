//
// ai_food_collider.cc for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sat Aug  1 14:15:54 2015 Guillaume ROBIN
// Last update Tue Aug  4 11:58:57 2015 Guillaume ROBIN
//

#include <cmath>
#include <iostream>

#include "ai_food_collision.h"
#include "ai_food_collider.h"
#include "basic_ia.h"
#include "food.h"

/*
** Constructor & Destructor.
*/
ColliderAIAndFood::ColliderAIAndFood(void)
{
  _action = new AIAndFoodCollision();
}

ColliderAIAndFood::~ColliderAIAndFood(void)
{
  delete(_action);
}

/*
** Methods.
*/
bool	ColliderAIAndFood::isValid(std::string const& obj_1, std::string const& obj_2)
{
  if ((obj_1.compare("basic_survival_ai") && obj_2.compare("basic_food"))
      || (obj_1.compare("basic_food") && obj_2.compare("basic_survival_ai")))
    return (true);
  return (false);
}

static bool	isCollideCircle(sf::Vector2f const& p1, float r1, sf::Vector2f const& p2, float r2)
{
  float		distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));

  return (distance <= (r1 + r2));
}

bool		ColliderAIAndFood::isCollision(Graphics::IObject *obj_1, Graphics::IObject *obj_2)
{
  BasicAI	*ai;
  BasicFood	*food;

  if ((obj_1->getType()).compare("basic_survival_ai") == 0
      && (obj_2->getType()).compare("basic_food") == 0)
    {
      ai = (BasicAI *)(obj_1);
      food = (BasicFood *)(obj_2);
    }
  else if (obj_1->getType().compare("basic_food") == 0
	   && obj_2->getType().compare("basic_survival_ai") == 0)
     {
      ai = (BasicAI *)obj_2;
      food = (BasicFood *)obj_1;
    }
  else
    return (false);
  return (isCollideCircle(ai->getPosition(), 25, food->getPosition(), food->getRadius()));
}

Graphics::IBehavior	*ColliderAIAndFood::getAction(void) const
{
  return (_action);
}
