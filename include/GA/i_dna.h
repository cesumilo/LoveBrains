/*
** dna.h for GAEngine in /home/robin_f/Programming/Git/CPP/GANNEngine/include/GA
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:01:55 2015 Guillaume ROBIN
** Last update Fri Aug 21 17:17:06 2015 Guillaume ROBIN
*/

#ifndef IDNA_H_
# define IDNA_H_

# include <iostream>

namespace GA
{
  /*!
   * \class IDNA
   * \brief Define the interface that will be used to create an supported individual for the GAEngine.
   */
  class IDNA
  {
  public:
    /*!
     * \brief Destructor.
     */
    virtual ~IDNA(void);

    /*!
     * \brief Get the fitness of the individual.
     * \return double : fitness
     */
    virtual double     	getFitness(void) const = 0;
    /*!
     * \brief Set the fitness of the individual.
     * \param fitness : Contains the new fitness.
     */
    virtual void       	setFitness(double fitness) = 0;
    /*!
     * \brief Allow to draw the individual on the shell.
     */
    virtual void	Print(void) = 0;
  };
}

#endif /* !IDNA_H_ */
