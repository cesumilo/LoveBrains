/*
** a_nanobrain.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 29 16:51:30 2015 Guillaume ROBIN
** Last update Sat Aug  1 12:33:03 2015 Guillaume ROBIN
*/

#ifndef I_BRAIN_H_
# define I_BRAIN_H_

# include "Graphics/i_object.h"
# include "ANN/neural_net.h"

namespace Graphics
{
  class IBrain : public IObject
  {
  public:
    virtual ~IBrain(void) { }

    /*
    ** Getters.
    */
    virtual double	getFitness(void) const = 0;

    /*
    ** Setters.
    */
    virtual void	setFitness(double fitness) = 0;
    virtual void	setBrain(GANN::ANN const& brain) = 0;
    virtual void	setInput(unsigned int index, double value) = 0;
  };
}

#endif /* !A_NANOBRAIN_H_ */
