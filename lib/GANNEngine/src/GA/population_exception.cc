//
// population_exception.cc for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Tue Jul 21 13:43:40 2015 Guillaume ROBIN
// Last update Tue Jul 28 16:16:32 2015 Guillaume ROBIN
//

#include "GA/population_exception.h"

namespace GA
{
  /*
  ** Constructor & Destructor.
  */
  PopulationException::PopulationException(const char *message) throw()
  {
    _msg = (char *)message;
  }

  PopulationException::~PopulationException(void) throw()
  {
  }

  /*
  ** Methods.
  */
  const char	*PopulationException::what(void) const throw()
  {
    return (_msg);
  }
}
