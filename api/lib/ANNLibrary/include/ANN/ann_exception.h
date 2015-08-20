/*
** ann_exception.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Aug 20 12:09:58 2015 Guillaume ROBIN
** Last update Thu Aug 20 12:41:25 2015 Guillaume ROBIN
*/

#ifndef ANN_EXCEPTION_H_
# define ANN_EXCEPTION_H_

# include <exception>

namespace GANN
{
  class ANNException : public std::exception
  {
  public:
    ANNException(const char *message) throw();
    ~ANNException(void) throw();

    const char	*what(void) const throw();

  private:
    char	*_msg;
  };
}

#endif /* !ANN_EXCEPTION_H_ */
