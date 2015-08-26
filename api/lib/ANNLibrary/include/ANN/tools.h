/*
** tools.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul  9 14:00:18 2015 Guillaume ROBIN
** Last update Sun Jul 12 00:32:20 2015 Guillaume ROBIN
*/

#ifndef TOOLS_H_
# define TOOLS_H_

namespace GANN
{
  /*
  ** Maths.
  */
  double	Sigmoid(double x);
  double	Threshold(double x);
  double	RandomDouble(double min, double max);
  int		RandomInt(int min, int max);
}

#endif /* !TOOLS_H_ */
