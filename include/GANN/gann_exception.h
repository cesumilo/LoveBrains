/*
** gann_exception.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon Jul 13 10:38:18 2015 Guillaume ROBIN
** Last update Fri Aug 21 23:07:55 2015 Guillaume ROBIN
*/

#ifndef GANN_EXCEPTION_H_
# define GANN_EXCEPTION_H_

#include <exception>
#include <iostream>

namespace GANN
{
  /*!
   * \class GANNException
   * \brief Define the exception that will be used by the GANNEngine class.
   */
  class GANNException : std::exception
  {
  public:
    /*!
     * \brief Constructor.
     * \param msg : Contains the error message.
     */
    GANNException(const char *msg);
    /*!
     * \brief Destructor.
     */
    virtual ~GANNException(void) throw();

    /*!
     * \brief Return the error message.
     * \return const char * : error message.
     */
    virtual const char	*what(void) const throw();

  private:
    char	*_msg; /*!< Contains the error message given by the constructor. */
  };
}

#endif /* !GANN_EXCEPTION_H_ */
