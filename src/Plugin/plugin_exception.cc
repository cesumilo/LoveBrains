//
// plugin_exception.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Jul 30 12:00:14 2015 Guillaume ROBIN
// Last update Thu Jul 30 12:04:00 2015 Guillaume ROBIN
//

#include "Plugin/plugin_exception.h"

namespace Plugin
{
  /*
  ** Constructor & Destructor.
  */
  PluginException::PluginException(const char *message) throw()
  {
    _msg = (char *)message;
  }

  PluginException::~PluginException(void) throw()
  {
  }

  /*
  ** Methods.
  */
  const char	*PluginException::what(void) const throw()
  {
    return (_msg);
  }
}
