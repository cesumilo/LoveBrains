/*
** ann_generator.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 16:39:03 2015 Guillaume ROBIN
** Last update Thu Aug 20 12:52:14 2015 Guillaume ROBIN
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
  class ANNGenerator : public GA::IGenerator
  {
  public:
    ANNGenerator(void) throw();
    ANNGenerator(std::vector<unsigned int> const& infos, double crossing_rate) throw();
    ~ANNGenerator(void) throw();

    /*
    ** Setters.
    */
    void	init(std::vector<unsigned int> const& infos, double crossing_rate) throw();
    void	setRandomize(double min, double max) throw();
    void	setActivationFunction(ANNLayer::FActivate function,
				      ANN::ActivationType type) throw();
    void	setOutputsActivation(ANNLayer::FActivate function,
				     ANN::ActivationType type) throw();

    /*
    ** Getters.
    */
    std::vector<unsigned int> const&	getInfos(void) const throw();
    double				getCrossingRate(void) const throw();
    double				getRandomMin(void) const throw();
    double				getRandomMax(void) const throw();
    ANNLayer::FActivate			getActivation(void) const throw();
    ANNLayer::FActivate			getOutputsActivation(void) const throw();
    ANN::ActivationType			getOutputType(void) const throw();
    ANN::ActivationType			getLayerType(void) const throw();

    /*
    ** Overload.
    */
    ANNGenerator&	operator=(ANNGenerator const& gen) throw();

    /*
    ** Methods.
    */
    GA::IDNA	*Generate(void) const throw();

  private:
    std::vector<unsigned int>	_infos;
    double			_crossing_rate;
    double			_rand_min;
    double			_rand_max;
    ANNLayer::FActivate		_activation;
    ANNLayer::FActivate		_output_function;
    ANN::ActivationType		_out_ftype;
    ANN::ActivationType		_layer_ftype;
  };
}

#endif /* !ANN_GENERATOR_H_ */
