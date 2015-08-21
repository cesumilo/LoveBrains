/*
** gann_exception.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon Jul 13 10:38:18 2015 Guillaume ROBIN
** Last update Mon Jul 13 10:48:28 2015 Guillaume ROBIN
*/

#ifndef GANN_EXCEPTION_H_
# define GANN_EXCEPTION_H_

#include <exception>
#include <iostream>

namespace GANN
{
  class GANNException : std::exception
  {
  public:
    GANNException(const char *msg);
    virtual ~GANNException(void) throw();

    virtual const char	*what(void) const throw();

  private:
    char	*_msg;
  };
}

#endif /* !GANN_EXCEPTION_H_ */
