/*
** a_observable.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon Jul 20 18:33:16 2015 Guillaume ROBIN
** Last update Tue Jul 28 16:14:12 2015 Guillaume ROBIN
*/

#ifndef A_OBSERVABLE_H_
# define A_OBSERVABLE_H_

# include <list>

# include "GA/a_observer.h"

namespace GA
{
  class AObservable
  {
  public:
    virtual	~AObservable(void);

    void	addObserver(AObserver *obs);
    void	delObserver(AObserver *obs);
  protected:
    std::list<AObserver *>	_obs;

    void	Notify(AObserver::States state);
  };
}

#endif /* !A_OBSERVABLE_H_ */
