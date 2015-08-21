/*
** ann_generator.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 16:39:03 2015 Guillaume ROBIN
** Last update Fri Aug 21 23:23:30 2015 Guillaume ROBIN
*/

#ifndef ANN_GENERATOR_H_
# define ANN_GENERATOR_H_

# include <vector>

#include "ANN/neural_net.h"
# include "ANN/ann_layer.h"
# include "GA/i_generator.h"
# include "GA/i_dna.h"

namespace GANN
{
  /*!
   * \class ANNGenerator
   * \brief Define the generator of a neural network.
   */
  class ANNGenerator : public GA::IGenerator
  {
  public:
    /*!
     * \brief Constructor.
     */
    ANNGenerator(void) throw();
    /*!
     * \brief Constructor.
     * \param infos : Contains the topology of the neural network.
     * \param crossing_rate : Contains the crossing rate of the neural network.
     */
    ANNGenerator(std::vector<unsigned int> const& infos, double crossing_rate) throw();
    /*!
     * \brief Destructor.
     */
    ~ANNGenerator(void) throw();

    /*
    ** Setters.
    */

    /*!
     * \brief Initialize the generator.
     * \param infos : Contains the topology of the neural network.
     * \param crossing_rate : Contains the crossing rate of the neural network.
     */
    void	init(std::vector<unsigned int> const& infos, double crossing_rate) throw();
    /*!
     * \brief Set the range of the randomization.
     * \param min : the minimum value of the range.
     * \param max : the maximum value of the range.
     */
    void	setRandomize(double min, double max) throw();
    /*!
     * \brief Set the activation function of the intern layers.
     * \param function : function pointer of the activation function.
     * \param type : the type of the activation function.
     */
    void	setActivationFunction(ANNLayer::FActivate function,
				      ANN::ActivationType type) throw();
    /*!
     * \brief Set the activation function of the output layer.
     * \param function : function pointer of the activation function.
     * \param type : the type of the activation function.
     */
    void	setOutputsActivation(ANNLayer::FActivate function,
				     ANN::ActivationType type) throw();

    /*
    ** Getters.
    */

    /*!
     * \brief Get the topology of the neural network.
     * \return std::vector<unsigned int> const&
     */
    std::vector<unsigned int> const&	getInfos(void) const throw();
    /*!
     * \brief Get the crossing rate of the neural network.
     * \return double
     */
    double				getCrossingRate(void) const throw();
    /*!
     * \brief Get the minimum value of the randomization range.
     * \return double
     */
    double				getRandomMin(void) const throw();
    /*!
     * \brief Get the maximum value of the randomization range.
     * \return double
     */
    double				getRandomMax(void) const throw();
    /*!
     * \brief Get the activation function pointer of the intern layers.
     * \return ANNLayer::FActivate
     */
    ANNLayer::FActivate			getActivation(void) const throw();
    /*!
     * \brief Get the activation function pointer of the output layer.
     * \return ANNLayer::FActivate
     */
    ANNLayer::FActivate			getOutputsActivation(void) const throw();
    /*!
     * \brief Get the activation function's type of the intern layers.
     * \return ANN::ActivationType
     */
    ANN::ActivationType			getOutputType(void) const throw();
    /*!
     * \brief Get the activaton function's type of the output layer.
     * \return ANN::ActivationType
     */
    ANN::ActivationType			getLayerType(void) const throw();

    /*
    ** Overload.
    */
    ANNGenerator&	operator=(ANNGenerator const& gen) throw();

    /*
    ** Methods.
    */

    /*!
     * \brief Generate a new neural network.
     * \return GA::IDNA *
     */
    GA::IDNA	*Generate(void) const throw();

  private:
    std::vector<unsigned int>	_infos; /*!< Contains the topology of the neural network. */
    double			_crossing_rate; /*!< Contains the crossing rate of the neural network. */
    double			_rand_min; /*!< Contains the minimum value of the randomization range. */
    double			_rand_max; /*!< Contains the maximum value of the randomization range. */
    ANNLayer::FActivate		_activation; /*!< Contains the activation function of the intern layers. */
    ANNLayer::FActivate		_output_function; /*!< Contains the activation function of the output layer. */
    ANN::ActivationType		_out_ftype; /*!< Contains the activation function's type of the intern layers. */
    ANN::ActivationType		_layer_ftype; /*!< Contains the activation function's type of the output layer. */
  };
}

#endif /* !ANN_GENERATOR_H_ */
