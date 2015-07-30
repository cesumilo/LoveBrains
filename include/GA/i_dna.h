/*
** dna.h for GAEngine in /home/robin_f/Programming/Git/CPP/GANNEngine/include/GA
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:01:55 2015 Guillaume ROBIN
** Last update Sat Jul 18 22:38:15 2015 Guillaume ROBIN
*/

#ifndef IDNA_H_
# define IDNA_H_

# include <iostream>

namespace GA
{
  class IDNA
  {
  public:
    virtual ~IDNA(void);

    virtual double     	getFitness(void) const = 0;
    virtual void       	setFitness(double fitness) = 0;
    virtual void	Print(void) = 0;
  };
}

#endif /* !IDNA_H_ */
