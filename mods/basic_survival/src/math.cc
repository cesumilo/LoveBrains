//
// math.cc<2> for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
// 
// Made by ROBIN Guillaume
// Login   <robin_f@epitech.eu>
// 
// Started on  Mon Aug 17 14:25:09 2015 ROBIN Guillaume
// Last update Tue Aug 18 13:38:31 2015 Guillaume ROBIN
//

#include <cmath>
#include "math_plugin.h"

/*
** Constructor & Destructor.
*/

Math::Math(void)
{
}

Math::~Math(void)
{
}

/*
** Static methods.
*/
sf::Vector2f	Math::RotateVector2D(sf::Vector2f const& vect, double angle)
{
  float		rad = angle * PI / 180;
  sf::Vector2f	vector;

  vector.x = vect.x * cos(rad) - vect.y * sin(rad);
  vector.y = vect.y * cos(rad) + vect.x * sin(rad);
  return (vector);
}

double	Math::CrossProduct2D(sf::Vector2f const& v1, sf::Vector2f const& v2)
{
  return (v1.x * v2.y - v1.y * v2.x);
}

double	Math::EuclideanDistance(sf::Vector2f const& v1, sf::Vector2f const& v2)
{
  return (sqrt(pow((v2.x - v1.x), 2) + pow(v2.y - v1.y, 2)));
}

static bool    	isOnSameSide(sf::Vector2f const& p1, sf::Vector2f const& p2,
			     sf::Vector2f const& a, sf::Vector2f const& b)
{
  sf::Vector2f	a_b(b.x - a.x, b.y - a.y);
  sf::Vector2f	a_p1(p1.x - a.x, p1.y - a.y);
  sf::Vector2f	a_p2(p2.x - a.x, p2.y - a.y);
  double       	cp1 = Math::CrossProduct2D(a_b, a_p1);
  double       	cp2 = Math::CrossProduct2D(a_b, a_p2);

  return (cp1 * cp2 >= 0);
}

bool			Math::TriangleContains(sf::Vector2f const& a, sf::Vector2f const& b,
					       sf::Vector2f const& c, sf::Vector2f const& p)
{
  return (isOnSameSide(p, a, b ,c) && isOnSameSide(p, c, a, b) && isOnSameSide(p, b, a, c));
}

double	Math::NormalizeData(double value, double min, double max)
{
  if (max - min != 0)
    return ((value - min) / (max - min));
  return (0);
}

std::vector<sf::Vector2f *>	Math::GenerateCirclePoints(sf::Vector2f const& center, float radius)
{
  unsigned int			pointCount = radius / 10;
  float				step = (float)360 / (float)pointCount;
  float				angle = 0;
  sf::Vector2f			dir((center.x - radius) - center.x, 0);
  sf::Vector2f			tmp;
  sf::Vector2f			*ptr;
  std::vector<sf::Vector2f *>	array;

  for (unsigned int i = 0; i < pointCount; i++)
    {
      if ((ptr = new sf::Vector2f()))
	{
	  tmp = Math::RotateVector2D(dir, angle);
	  ptr->x = center.x + tmp.x;
	  ptr->y = center.y + tmp.y;
	  array.push_back(ptr);
	}
      angle += step;
    }
  return (array);
}
