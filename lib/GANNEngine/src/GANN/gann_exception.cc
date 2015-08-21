//
// gann_exception.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Mon Jul 13 10:43:04 2015 Guillaume ROBIN
// Last update Mon Jul 13 10:50:05 2015 Guillaume ROBIN
//

#include "GANN/gann_exception.h"

namespace GANN
{
  /*
  ** Constructor.
  */
  GANNException::GANNException(const char *msg)
  {
    _msg = (char *)msg;
  }

  GANNException::~GANNException(void) throw()
  {
  }

  /*
  ** Methods.
  */
  const char	*GANNException::what(void) const throw()
  {
    return (_msg);
  }
}
