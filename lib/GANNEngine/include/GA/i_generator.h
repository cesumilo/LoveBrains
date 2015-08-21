/*
** i_generator.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 16:03:50 2015 Guillaume ROBIN
** Last update Tue Jul 28 16:15:10 2015 Guillaume ROBIN
*/

#ifndef I_GENERATOR_H_
# define I_GENERATOR_H_

# include "GA/i_dna.h"

namespace GA
{
  class IGenerator
  {
  public:
    virtual ~IGenerator(void);

    virtual IDNA	*Generate(void) const = 0;
  };
}

#endif /* !I_GENERATOR_H_ */
