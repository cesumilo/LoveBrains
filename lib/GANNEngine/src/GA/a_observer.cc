//
// iobserver.cc for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Mon Jul 20 18:28:54 2015 Guillaume ROBIN
// Last update Tue Jul 28 16:16:39 2015 Guillaume ROBIN
//

#include "GA/a_observer.h"

namespace GA
{
  unsigned int	AObserver::_iterator = 0;

  void	AObserver::setId(void)
  {
    _id = AObserver::_iterator;
    ++AObserver::_iterator;
  }

  unsigned int	AObserver::id(void) const
  {
    return (_id);
  }

  AObserver::States const&	AObserver::getState(void) const
  {
    return (_state);
  }

  void	AObserver::Update(AObserver::States state)
  {
    _state = state;
  }
}
