/*
** ann_exception.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Aug 20 12:09:58 2015 Guillaume ROBIN
** Last update Fri Aug 21 23:10:52 2015 Guillaume ROBIN
*/

#ifndef ANN_EXCEPTION_H_
# define ANN_EXCEPTION_H_

# include <exception>

namespace GANN
{
  /*!
   * \class ANNException
   * \brief Define the exception that will be used by the GANN::ANN class.
   */
  class ANNException : public std::exception
  {
  public:
    /*!
     * \brief Constructor.
     * \param message : Contains the error message.
     */
    ANNException(const char *message) throw();
    /*!
     * \brief Destructor.
     */
    ~ANNException(void) throw();

    /*!
     * \brief Return the error message.
     * \return const char * : error message.
     */
    const char	*what(void) const throw();

  private:
    char	*_msg; /*!< Contains the error message given by the constructor. */
  };
}

#endif /* !ANN_EXCEPTION_H_ */
