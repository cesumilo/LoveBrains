//
// simuator_exception.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Jul 23 14:11:51 2015 Guillaume ROBIN
// Last update Thu Jul 23 14:13:24 2015 Guillaume ROBIN
//

#include "Simulator/simulator_exception.h"

namespace Simulator
{
  /*
  ** Constructor & Destructor.
  */
  SimulatorException::SimulatorException(const char *message) throw()
  {
    _msg = (char *)message;
  }

  SimulatorException::~SimulatorException(void) throw()
  {
  }

  /*
  ** Methods.
  */
  const char	*SimulatorException::what(void) const throw()
  {
    return (_msg);
  }
}
