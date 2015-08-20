/*
** ann_layer.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:16:10 2015 Guillaume ROBIN
** Last update Thu Aug 20 12:27:25 2015 Guillaume ROBIN
*/

#ifndef ANN_LAYER_H_
# define ANN_LAYER_H_

# include "ANN/matrix.h"

namespace GANN
{
  class ANNLayer
  {
  public:
    /*
    ** Typedef.
    */
    typedef double	(*FActivate)(double);

    ANNLayer(unsigned int num_inputs, unsigned int num_neurons,
	     double min, double max, FActivate activation);
    ANNLayer(ANNLayer const& copy);
    ANNLayer(void);
    ~ANNLayer(void);

    /*
    ** Getters.
    */
    Matrix<double> const&	getWeights(void) const;
    Matrix<double>&		getWeights(void);
    Matrix<double> const&	getOutputs(void) const;
    Matrix<double> const&	getBias(void) const;
    Matrix<double>&		getBias(void);
    FActivate			getActivationFunction(void) const;

    /*
    ** Setters.
    */
    void	setWeights(Matrix<double> const& weights);
    void	setBias(Matrix<double> const& bias);
    void	setOutputs(Matrix<double> const& outputs);
    void	setActivationFunction(FActivate f);

    /*
    ** Overlaod.
    */
    ANNLayer&	operator=(ANNLayer const& layer);

    /*
    ** Methods.
    */
    void	Activate(Matrix<double> const& inputs);

  private:
    Matrix<double>	_weights;
    Matrix<double>	_outputs;
    Matrix<double>	_bias;
    FActivate		_activate;
  };
}

#endif /* !ANN_LAYER_H_ */
