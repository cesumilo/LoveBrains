/*
** ann_layer.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:16:10 2015 Guillaume ROBIN
** Last update Mon Jul 13 10:21:19 2015 Guillaume ROBIN
*/

#ifndef ANN_LAYER_H_
# define ANN_LAYER_H_

# include "ANN/matrix.h"

# define ERR_ANN_NLAYER		(char *)"Error: allocation of an ANNLayer failed."
# define ERR_ANN_INVLAYERS	(char *)"Error: invalid size of layers."
# define ERR_ANN_INVCROSSRATE	(char *)"Error: invalid crossing rate."
# define ERR_ANN_NULLACTIVATION	(char *)"Error: activation function is null."
# define ERR_ANN_ERRACTIVATE	(char *)"Error: impossible to activate a null layer."

# define DEF_CROSS_RATE		(double)0.7

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
