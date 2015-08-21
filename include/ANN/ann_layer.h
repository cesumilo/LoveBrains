/*
** ann_layer.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:16:10 2015 Guillaume ROBIN
** Last update Fri Aug 21 23:34:14 2015 Guillaume ROBIN
*/

#ifndef ANN_LAYER_H_
# define ANN_LAYER_H_

# include "ANN/matrix.h"

namespace GANN
{
  /*!
   * \class ANNLayer
   * \brief Define a layer of a neural network.
   */
  class ANNLayer
  {
  public:
    /*
    ** Typedef.
    */
    /*!
     * \brief Function pointer of an activation function.
     */
    typedef double	(*FActivate)(double);

    /*!
     * \brief Constructor.
     * \param num_inputs : Contains the number of inputs.
     * \param num_neurons : Contains the number of neurons in the layer.
     * \param min : Contains the minimum value of the randomization.
     * \param max : Contains the maximum value of the randomization.
     * \param activation : Contains the function pointer of the activation function.
     */
    ANNLayer(unsigned int num_inputs, unsigned int num_neurons,
	     double min, double max, FActivate activation);
    /*!
     * \brief Constructor.
     * \param copy : Contains a layer that will be used in order to create a new layer.
     */
    ANNLayer(ANNLayer const& copy);
    /*!
     * \brief Constructor.
     */
    ANNLayer(void);
    /*!
     * \brief Destructor.
     */
    ~ANNLayer(void);

    /*
    ** Getters.
    */

    /*!
     * \brief Get the weights matrix of the neural network.
     * \return GANN::Matrix<double> const&
     */
    Matrix<double> const&	getWeights(void) const;
    /*!
     * \brief Get the weights matrix of the neural network.
     * \return GANN::Matrix<double> &
     */
    Matrix<double>&		getWeights(void);
    /*!
     * \brief Get the outputs matrix of the neural network.
     * \retirn GANN::Matrix<double> const&
     */
    Matrix<double> const&	getOutputs(void) const;
    /*!
     * \brief Get the bias matrix of the neural network.
     * \return GANN::Matrix<double> const&
     */
    Matrix<double> const&	getBias(void) const;
    /*!
     * \brief Get the bias matrix of the neural network.
     * \return GANN::Matrix<double> &
     */
    Matrix<double>&		getBias(void);
    /*!
     * \brief Get the activation function of the current layer.
     * \return GANN::ANNLayer::FActivate
     */
    FActivate			getActivationFunction(void) const;

    /*
    ** Setters.
    */

    /*!
     * \brief Set the matrix of weights.
     * \param weights : Contains the matrix of weights.
     */
    void	setWeights(Matrix<double> const& weights);
    /*!
     * \brief Set the matrix of bias.
     * \param bias : Contains the matrix of bias.
     */
    void	setBias(Matrix<double> const& bias);
    /*!
     * \brief Set the outputs matrix.
     * \param outputs : Contains the matrix of outputs.x
     */
    void	setOutputs(Matrix<double> const& outputs);
    /*!
     * \brief Set the activation function of the layer.
     * \param f : Contains the function pointer of the activation function.
     */
    void	setActivationFunction(FActivate f);

    /*
    ** Overlaod.
    */
    ANNLayer&	operator=(ANNLayer const& layer);

    /*
    ** Methods.
    */

    /*!
     * \brief Activate the current layer and set the matrix of outputs.
     * \param inputs : Contains the matrix of inputs of the layer.
     */
    void	Activate(Matrix<double> const& inputs);

  private:
    Matrix<double>	_weights; /*!< Contains the weights of the layer. */
    Matrix<double>	_outputs; /*!< Contains the outputs of the layer. */
    Matrix<double>	_bias; /*!< Contains the bias of the layer. */
    FActivate		_activate; /*!< Contains the activation function pointer of the layer. */
  };
}

#endif /* !ANN_LAYER_H_ */
