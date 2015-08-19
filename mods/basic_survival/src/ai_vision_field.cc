//
// ai_vision_field.cc for Basic Survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by ROBIN Guillaume
// Login   <robin_f@epitech.eu>
// 
// Started on  Mon Aug 17 14:11:34 2015 ROBIN Guillaume
// Last update Wed Aug 19 11:36:32 2015 Guillaume ROBIN
//

#include "ai_vision_field.h"
#include "basic_ia.h"
#include "food.h"
#include "math_plugin.h"

/*
** Constructor & Destructor.
*/
AIVisionField::AIVisionField(void)
{
}

AIVisionField::~AIVisionField(void)
{
}

/*
** Getters.
*/
bool	AIVisionField::isValid(Graphics::IObject *obj)
{
  return (obj && obj->getType().compare("basic_survival_ai") == 0);
}

/*
** Methods.
*/
static bool			IsDetected(sf::Vector2f const& position, sf::Vector2f const& p,
					   float radius, double angle)
{
  sf::Vector2f			velocity(0, DEF_NB_VFDIST);
  sf::Vector2f			visionFieldLeft;
  sf::Vector2f			visionFieldRight;
  sf::Vector2f			p2;
  sf::Vector2f			p3;
  std::vector<sf::Vector2f *>	array = Math::GenerateCirclePoints(p, radius);

  velocity = Math::RotateVector2D(velocity, angle);
  visionFieldLeft = Math::RotateVector2D(velocity, -DEF_NB_VFANGLE);
  visionFieldRight = Math::RotateVector2D(velocity, DEF_NB_VFANGLE);
  p2.x = position.x + visionFieldLeft.x;
  p2.y = position.y + visionFieldLeft.y;
  p3.x = position.x + visionFieldRight.x;
  p3.y = position.y + visionFieldRight.y;
  if (Math::TriangleContains(position, p2, p3, p))
    {
      for (unsigned int i = 0; i < array.size(); i++)
	delete(array[i]);
      return (true);
    }
  for (unsigned int i = 0; i < array.size(); i++)
    {
      if (Math::TriangleContains(position, p2, p3, *(array[i])))
	{
	  for (unsigned int j = 0; j < array.size(); j++)
	    delete(array[j]);
	  return (true);
	}
    }
  for (unsigned int i = 0; i < array.size(); i++)
    delete(array[i]);
  return (false);
}

void	AIVisionField::Update(Graphics::IObject *obj, std::list<Graphics::IObject *>& env)
{
  sf::Vector2f	position = ((BasicAI *)obj)->getPosition();
  sf::Vector2f	target;

  for (std::list<Graphics::IObject *>::iterator it = env.begin(); it != env.end(); ++it)
    {
      if (*it && (*it)->getType().compare("basic_food") == 0)
	{
	  target = ((BasicFood *)(*it))->getPosition();
	  if (IsDetected(position, target, ((BasicFood *)(*it))->getRadius(),
			 ((BasicAI *)obj)->getRotation()))
	    {
	      ((BasicAI *)obj)->setInput(INPUT_FOOD,
					 Math::NormalizeData(Math::EuclideanDistance(position,
										     target),
							     DEF_MIN_DIST,
							     DEF_MAX_DIST));
	    }
	}
    }
}
