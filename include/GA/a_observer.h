/*
** iobserver.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon Jul 20 18:23:32 2015 Guillaume ROBIN
** Last update Fri Aug 21 16:26:18 2015 Guillaume ROBIN
*/

#ifndef A_OBSERVER_H_
# define A_OBSERVER_H_

namespace GA
{
  /*!
   * \class AObserver
   * \brief Define the abstract class that allow to be an observer.
   */
  class AObserver
  {
  public:
    enum class States { NONE, QUIT, REPORT };

    /*!
     * \brief Return the ID of the observer.
     * \return unsigned int
     */
    unsigned int	id(void) const;

    /*!
     * \brief Return the state of the observer.
     * \return AObserver::States const&
     */
    States const&	getState(void) const;
    /*!
     * \brief Update the observer.
     * \param state : Contains the new state.
     */
    void		Update(States state);

  protected:
    States		_state; /*!< Contains the current state */

    /*!
     * \brief Set the ID of the observer.
     */
    void		setId(void);

  private:
    unsigned int	_id; /*!< Contains the ID of the observer. */

    static unsigned int	_iterator; /*!< Contains the iterator that defines the ID of each observer. */
  };
}

#endif /* !A_OBSERVER_H_ */
