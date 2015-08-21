/*
** ga_engine_exception.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 14:18:49 2015 Guillaume ROBIN
** Last update Fri Aug 21 17:14:31 2015 Guillaume ROBIN
*/

#ifndef GA_ENGINE_EXCEPTION_H_
# define GA_ENGINE_EXCEPTION_H_

# include <exception>

namespace GA
{
  /*!
   * \class GAEngineException
   * \brief Define the exception that will be used by the GAEngine.
   */
  class GAEngineException : public std::exception
  {
  public:
    /*!
     * \brief Constructor.
     * \param msg : Contains the message error.
     */
    GAEngineException(const char *msg) throw();
    /*!
     * \brief Destructor.
     */
    ~GAEngineException(void) throw();

    /*!
     * \brief Return the current error message.
     * \return const char * : error message.
     */
    const char	*what(void) const throw();

  private:
    char	*_msg; /*!< Contains the error message given by the constructor. */
  };
}

#endif /* !GA_ENGINE_EXCEPTION_H_ */
