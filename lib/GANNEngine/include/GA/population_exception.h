/*
** population_exception.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 13:40:21 2015 Guillaume ROBIN
** Last update Tue Jul 21 14:30:50 2015 Guillaume ROBIN
*/

#ifndef POPULATION_EXCEPTION_H_
# define POPULATION_EXCEPTION_H_

# include <exception>

namespace GA
{
  class PopulationException : public std::exception
  {
  public:
    PopulationException(const char *message) throw();
    ~PopulationException(void) throw();

    const char	*what(void) const throw();

  private:
    char	*_msg;
  };
}

#endif /* !POPULATION_EXCEPTION_H_ */
