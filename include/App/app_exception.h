/*
** app_exception.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Fri Jul 31 13:29:17 2015 Guillaume ROBIN
** Last update Fri Jul 31 14:31:47 2015 Guillaume ROBIN
*/

#ifndef APP_EXCEPTION_H_
# define APP_EXCEPTION_H_

# include <exception>

namespace App
{
  class AppException : public std::exception
  {
  public:
    AppException(const char *message) throw();
    ~AppException(void) throw();

    const char	*what(void) const throw();

  private:
    char	*_msg;
  };
}

#endif /* !APP_EXCEPTION_H_ */
