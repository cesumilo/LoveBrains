/*
** i_generator.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 16:03:50 2015 Guillaume ROBIN
** Last update Fri Aug 21 17:18:15 2015 Guillaume ROBIN
*/

#ifndef I_GENERATOR_H_
# define I_GENERATOR_H_

# include "GA/i_dna.h"

namespace GA
{
  /*!
   * \class IGenerator
   * \brief Define the interface that allow to define a new generator of individual for the GAEngine.
   */
  class IGenerator
  {
  public:
    /*!
     * \brief Destructor.
     */
    virtual ~IGenerator(void);

    /*!
     * \brief Generate a new individual.
     * \return IDNA *
     */
    virtual IDNA	*Generate(void) const = 0;
  };
}

#endif /* !I_GENERATOR_H_ */
