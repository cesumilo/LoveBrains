/*
** plugin_exception.h for LoveBrains= in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 30 11:57:56 2015 Guillaume ROBIN
** Last update Fri Aug 21 13:59:46 2015 Guillaume ROBIN
*/

#ifndef PLUGIN_EXCEPTION_H_
# define PLUGIN_EXCEPTION_H_

# include <exception>

namespace Plugin
{
  /*!
   * \class PluginException
   * \brief Define the exception used by the PluginManager class.
   */
  class PluginException : public std::exception
  {
  public:
    /*!
     * \brief Constructor.
     * \param message : Contains the error message.
     */
    PluginException(const char *message) throw();
    /*!
     * \brief Destructor.
     */
    virtual ~PluginException(void) throw();

    /*
    ** Methods.
    */

    /*!
     * \brief Return the error message.
     * \return const char *
     */
    const char	*what(void) const throw();

  private:
    char	*_msg; /*!< Contains the error message given by the constructor. */
  };
}

#endif /* !PLUGIN_EXCEPTION_H_ */
