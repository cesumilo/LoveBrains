/*
** math.h for Basic survival plugin in /home/robin_f/Programming/Git/CPP/LoveBrains/mods/basic_survival
** 
** Made by ROBIN Guillaume
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon Aug 17 14:25:40 2015 ROBIN Guillaume
** Last update Tue Aug 18 13:39:25 2015 Guillaume ROBIN
*/

#ifndef MATH_PLUGIN_H_
# define MATH_PLUGIN_H_

# include <SFML/Graphics.hpp>
# include <vector>

# define PI (double)3.141592

class Math
{
 public:
  Math(void);
  ~Math(void);

  static sf::Vector2f  		       	RotateVector2D(sf::Vector2f const& vect, double angle);
  static double				CrossProduct2D(sf::Vector2f const& v1,
  						       sf::Vector2f const& v2);
  static double				EuclideanDistance(sf::Vector2f const& v1,
							  sf::Vector2f const& v2);
  static bool				TriangleContains(sf::Vector2f const& a,
  							 sf::Vector2f const& b,
  							 sf::Vector2f const& c,
  							 sf::Vector2f const& p);
  static std::vector<sf::Vector2f *>	GenerateCirclePoints(sf::Vector2f const& center,
  							     float radius);
  static double				NormalizeData(double value, double min, double max);
};

#endif /* !MATH_PLUGIN_H_ */
