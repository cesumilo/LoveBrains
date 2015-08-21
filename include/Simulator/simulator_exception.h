/*
** simulator_exception.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 23 14:09:05 2015 Guillaume ROBIN
** Last update Fri Aug 21 06:49:33 2015 Guillaume ROBIN
*/

#ifndef SIMULATOR_EXCEPTION_H_
# define SIMULATOR_EXCEPTION_H_

# include <exception>

namespace Simulator
{
  /*!
   * \class SimulatorException
   * \brief Define the exception used by the Simulator class.
   */
  class SimulatorException : public std::exception
  {
  public:
    /*!
     * \brief Constructor.
     * \param message : Contains the error message.
     */
    SimulatorException(const char *message) throw();
    /*!
     * \brief Destructor.
     */
    ~SimulatorException(void) throw();

    /*!
     * \brief Return the error message.
     * \return const char *
     */
    const char	*what(void) const throw();

  private:
    char	*_msg; /*!< Contains the error message given by the constructor. */
  };
}

#endif /* !SIMULATOR_EXCEPTION_H_ */
