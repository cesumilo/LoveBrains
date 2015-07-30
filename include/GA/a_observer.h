/*
** iobserver.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Mon Jul 20 18:23:32 2015 Guillaume ROBIN
** Last update Tue Jul 21 10:04:35 2015 Guillaume ROBIN
*/

#ifndef A_OBSERVER_H_
# define A_OBSERVER_H_

namespace GA
{
  class AObserver
  {
  public:
    enum class States { NONE, QUIT, REPORT };

    unsigned int	id(void) const;

    States const&	getState(void) const;
    void		Update(States state);

  protected:
    States		_state;

    void		setId(void);

  private:
    unsigned int	_id;

    static unsigned int	_iterator;
  };
}

#endif /* !A_OBSERVER_H_ */
