/*
** ann_generator.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 16:39:03 2015 Guillaume ROBIN
** Last update Thu Jul 23 12:12:26 2015 Guillaume ROBIN
*/

#ifndef ANN_GENERATOR_H_
# define ANN_GENERATOR_H_

# include <vector>

# include "ANN/ann_layer.h"
# include "GA/i_generator.h"
# include "GA/i_dna.h"

namespace GANN
{
  class ANNGenerator : public GA::IGenerator
  {
  public:
    ANNGenerator(void);
    ANNGenerator(std::vector<unsigned int> const& infos, double crossing_rate);
    ~ANNGenerator(void);

    /*
    ** Setters.
    */
    void	init(std::vector<unsigned int> const& infos, double crossing_rate);
    void	setRandomize(double min, double max);
    void	setActivationFunction(ANNLayer::FActivate function);
    void	setOutputsActivation(ANNLayer::FActivate function);

    /*
    ** Getters.
    */
    std::vector<unsigned int> const&	getInfos(void) const;
    double				getCrossingRate(void) const;
    double				getRandomMin(void) const;
    double				getRandomMax(void) const;
    ANNLayer::FActivate			getActivation(void) const;
    ANNLayer::FActivate			getOutputsActivation(void) const;

    /*
    ** Overload.
    */
    ANNGenerator&	operator=(ANNGenerator const& gen);

    /*
    ** Methods.
    */
    GA::IDNA	*Generate(void) const;

  private:
    std::vector<unsigned int>	_infos;
    double			_crossing_rate;
    double			_rand_min;
    double			_rand_max;
    ANNLayer::FActivate		_activation;
    ANNLayer::FActivate		_output_function;
  };
}

#endif /* !ANN_GENERATOR_H_ */
