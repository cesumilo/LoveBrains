/*
** simulator_exception.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 23 14:09:05 2015 Guillaume ROBIN
** Last update Tue Jul 28 12:12:34 2015 Guillaume ROBIN
*/

#ifndef SIMULATOR_EXCEPTION_H_
# define SIMULATOR_EXCEPTION_H_

# include <exception>

namespace Simulator
{
  class SimulatorException : public std::exception
  {
  public:
    SimulatorException(const char *message) throw();
    ~SimulatorException(void) throw();

    const char	*what(void) const throw();

  private:
    char	*_msg;
  };
}

#endif /* !SIMULATOR_EXCEPTION_H_ */
