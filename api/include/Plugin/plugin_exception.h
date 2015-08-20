/*
** plugin_exception.h for LoveBrains= in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 30 11:57:56 2015 Guillaume ROBIN
** Last update Thu Jul 30 12:04:11 2015 Guillaume ROBIN
*/

#ifndef PLUGIN_EXCEPTION_H_
# define PLUGIN_EXCEPTION_H_

# include <exception>

namespace Plugin
{
  class PluginException : public std::exception
  {
  public:
    PluginException(const char *message) throw();
    virtual ~PluginException(void) throw();

    /*
    ** Methods.
    */
    const char	*what(void) const throw();

  private:
    char	*_msg;
  };
}

#endif /* !PLUGIN_EXCEPTION_H_ */
