//
// ga_engine_exception.cc for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Tue Jul 21 14:20:56 2015 Guillaume ROBIN
// Last update Tue Jul 28 16:16:07 2015 Guillaume ROBIN
//

#include "GA/ga_engine_exception.h"

namespace GA
{
  /*
  ** Constructor & Destructor.
  */
  GAEngineException::GAEngineException(const char *msg) throw()
  {
    _msg = (char *)msg;
  }

  GAEngineException::~GAEngineException(void) throw()
  {
  }

  /*
  ** Methods.
  */
  const char	*GAEngineException::what(void) const throw()
  {
    return (_msg);
  }
}
