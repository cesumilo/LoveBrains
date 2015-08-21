/*
** a_nanobrain.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 29 16:51:30 2015 Guillaume ROBIN
** Last update Fri Aug 21 14:51:43 2015 Guillaume ROBIN
*/

#ifndef I_BRAIN_H_
# define I_BRAIN_H_

# include "Graphics/i_object.h"
# include "ANN/neural_net.h"

namespace Graphics
{
  /*!
   * \class IBrain
   * \brief Define the interface of an object that contains a neural network.
   */
  class IBrain : public IObject
  {
  public:
    /*!
     * \brief Destructor.
     */
    virtual ~IBrain(void) { }

    /*
    ** Getters.
    */

    /*!
     * \brief Get the current fitness of the object.
     * \return double
     */
    virtual double	getFitness(void) const = 0;

    /*
    ** Setters.
    */

    /*!
     * \brief Set the current fitness of the object.
     * \param fitness : Contains the new fitness of the object.
     */
    virtual void	setFitness(double fitness) = 0;
    /*!
     * \brief Set the current neural network of the object.
     * \param brain : Contains the new neural network.
     */
    virtual void	setBrain(GANN::ANN const& brain) = 0;
    /*!
     * \brief Set an input for the neural network.
     * \param index : Contains the index of the input.
     * \param value : Contains the input value.
     */
    virtual void	setInput(unsigned int index, double value) = 0;
  };
}

#endif /* !A_NANOBRAIN_H_ */
