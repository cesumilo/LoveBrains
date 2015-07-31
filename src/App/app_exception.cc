//
// app_exception.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Fri Jul 31 13:30:55 2015 Guillaume ROBIN
// Last update Fri Jul 31 14:34:49 2015 Guillaume ROBIN
//

#include "App/app_exception.h"

namespace App
{
  /*
  ** Constructor & Destructor.
  */
  AppException::AppException(const char *message) throw()
  {
    _msg = (char *)message;
  }

  AppException::~AppException(void) throw()
  {
  }

  /*
  ** Methods.
  */
  const char	*AppException::what(void) const throw()
  {
    return (_msg);
  }
}
