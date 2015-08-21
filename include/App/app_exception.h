/*
** app_exception.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri Jul 31 13:29:17 2015 Guillaume ROBIN
** Last update Fri Aug 21 06:49:17 2015 Guillaume ROBIN
*/

#ifndef APP_EXCEPTION_H_
# define APP_EXCEPTION_H_

/*!
 * \file app_exception.h
 * \brief this file define the exception of the "App" class.
 * \author Guillaume ROBIN
 * \date Thursday, 20 August
 * \version 1.0.0
 */

# include <exception>

namespace App
{
  /*!
   * \class AppException
   * \brief Define the exception for the App class.
   */
  class AppException : public std::exception
  {
  public:
    /*!
     * \brief Constructor
     * \param message : Contains the error message.
     */
    AppException(const char *message) throw();
    /*!
     * \brief Destructor
     */
    ~AppException(void) throw();

    /*!
     * \brief Return the error message that has been throw.
     * \return const char *
     */
    const char	*what(void) const throw();

  private:
    char	*_msg; /*!< Contains the error message */
  };
}

#endif /* !APP_EXCEPTION_H_ */
