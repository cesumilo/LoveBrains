//
// a_observable.cc for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Mon Jul 20 18:49:19 2015 Guillaume ROBIN
// Last update Fri Jul 31 17:26:44 2015 Guillaume ROBIN
//

#include "GA/a_observable.h"

namespace GA
{
  AObservable::~AObservable(void)
  {
  }

  void	AObservable::addObserver(AObserver *obs)
  {
    _obs.push_back(obs);
  }

  void	AObservable::delObserver(AObserver *obs)
  {
    std::list<AObserver *>::iterator	it = _obs.begin();

    while (it != _obs.end() && (*it)->id()  != obs->id())
      ++it;
    if (it != _obs.end())
      _obs.erase(it);
  }

  void	AObservable::Notify(AObserver::States state)
  {
    for (std::list<AObserver *>::iterator it = _obs.begin(); it != _obs.end(); it++)
      (*it)->Update(state);
  }
}
