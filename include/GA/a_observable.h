/*
** a_observable.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon Jul 20 18:33:16 2015 Guillaume ROBIN
** Last update Fri Aug 21 16:09:47 2015 Guillaume ROBIN
*/

#ifndef A_OBSERVABLE_H_
# define A_OBSERVABLE_H_

# include <list>

# include "GA/a_observer.h"

/*!
 * \namespace GA
 * \brief Contains the objects that define the GAEngine.
 */
namespace GA
{
  /*!
   * \class AObservable
   * \brief Define the abstract class that allow to be observable.
   */
  class AObservable
  {
  public:
    /*!
     * \brief Destructor.
     */
    virtual	~AObservable(void);

    /*!
     * \brief Add a new observer to the list.
     * \param obs : Contains the new AObserver.
     */
    void	addObserver(AObserver *obs);
    /*!
     * \brief Delete an observer.
     * \param obs : Contains the observer that will be deleted.
     */
    void	delObserver(AObserver *obs);
  protected:
    std::list<AObserver *>	_obs; /*!< Contains all the observers */

    /*!
     * \brief Notify to the observers that something has changed.
     * \param state : Contains the new state of the object.
     */
    void	Notify(AObserver::States state);
  };
}

#endif /* !A_OBSERVABLE_H_ */
