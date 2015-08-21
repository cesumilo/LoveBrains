//
// tools.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Jul  9 14:01:17 2015 Guillaume ROBIN
// Last update Sun Jul 12 00:31:31 2015 Guillaume ROBIN
//

#include <cmath>
#include <stdlib.h>

#include "ANN/tools.h"

namespace GANN
{
  /*
  ** Maths.
  */
  double	Sigmoid(double x)
  {
    return (1 / (1 + exp(-x)));
  }

  double	Threshold(double x)
  {
    return (x > 0.5 ? 1 : 0);
  }

  double	RandomDouble(double min, double max)
  {
    return (((double)rand() / (double)RAND_MAX) * (max - min) + min);
  }

  int		RandomInt(int min, int max)
  {
    return (rand() % (max - min) + min);
  }
}
