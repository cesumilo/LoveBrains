/*
** gann.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sun Jul 19 22:00:11 2015 Guillaume ROBIN
** Last update Fri Aug 21 23:52:56 2015 Guillaume ROBIN
*/

#ifndef GANN_H_
# define GANN_H_

# include <vector>

# include "GA/i_dna.h"
# include "ANN/neural_net.h"

/*!
 * \namespace GANN
 * \brief Contains all the objects that provide the management for the genetic algorithm with neural networks.
 */
namespace GANN
{
  /*!
   * \brief Define a new object called "GANN" for Genetic Artificial Neural Network that inherit of the interface IDNA.
   */
  class GANN : public GA::IDNA
  {
  public:
    /*!
     * \brief Constructor.
     * \param infos : Contains the topology of the neural network.
     */
    GANN(std::vector<unsigned int> const& infos);
    /*!
     * \brief Constructor.
     */
    GANN(ANN const& ann);
    /*!
     * \brief Destructor.
     */
    ~GANN(void);

    /*
    ** Getters.
    */

    /*!
     * \brief Get the fitness of the GANN.
     * \return double
     */
    double	getFitness(void) const;
    /*!
     * \brief Get the neural network of the GANN.
     * \return ANN const&
     */
    ANN const&	getGenes(void) const;

    /*
    ** Setters.
    */

    /*!
     * \brief Set the fitness of the GANN.
     * \param fitness : Contains the new fitness of the GANN.
     */
    void	setFitness(double fitness);
    /*!
     * \brief Set the neural network of the GANN.
     * \param ann : Contains the new neural network of the GANN.
     */
    void	setGenes(ANN const& ann);

    /*
    ** Methods.
    */
    /*!
     * \brief Print the neural network in the shell.
     */
    void	Print(void);

  private:
    ANN		_brain; /*!< Contains the neural network. */
    double	_fitness; /*!< Contains the fitness. */
  };
}

#endif /* !GANN_H_ */
