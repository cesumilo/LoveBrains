/*
** population_exception.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 13:40:21 2015 Guillaume ROBIN
** Last update Fri Aug 21 22:44:33 2015 Guillaume ROBIN
*/

#ifndef POPULATION_EXCEPTION_H_
# define POPULATION_EXCEPTION_H_

# include <exception>

namespace GA
{
  /*!
   * \class PopulationException
   * \brief Define the exception that will be used by the Population class.
   */
  class PopulationException : public std::exception
  {
  public:
    /*!
     * \brief Constructor.
     * \param message : Contains the error message.
     */
    PopulationException(const char *message) throw();
    /*!
     * \brief Destructor.
     */
    ~PopulationException(void) throw();

    /*!
     * \brief Return the error message.
     * \return const char * : error message.
     */
    const char	*what(void) const throw();

  private:
    char	*_msg; /*!< Contains the error message given in the constructor. */
  };
}

#endif /* !POPULATION_EXCEPTION_H_ */
