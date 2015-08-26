//
// ann_exception.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Aug 20 12:11:32 2015 Guillaume ROBIN
// Last update Thu Aug 20 12:43:55 2015 Guillaume ROBIN
//

#include "ANN/ann_exception.h"

namespace GANN
{
  /*
  ** Constructor & Destructor.
  */
  ANNException::ANNException(const char *message) throw()
  {
    _msg = (char *)message;
  }

  ANNException::~ANNException(void) throw()
  {
  }

  /*
  ** Methods.
  */
  const char	*ANNException::what(void) const throw()
  {
    return (_msg);
  }
}
