//
// gann.cc for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Sun Jul 19 22:02:39 2015 Guillaume ROBIN
// Last update Tue Jul 21 16:59:04 2015 Guillaume ROBIN
//

#include <iostream>

#include "GANN/gann.h"

namespace GANN
{
  /*
  ** Constructor & Destructor.
  */
  GANN::GANN(std::vector<unsigned int> const& infos)
  {
    _brain.Create(infos);
    _fitness = 0;
  }

  GANN::GANN(ANN const& ann)
  {
    _brain = ann;
    _fitness = 0;
  }

  GANN::~GANN(void)
  {
  }

  /*
  ** Getters.
  */
  double	GANN::getFitness(void) const
  {
    return (_fitness);
  }

  ANN const&	GANN::getGenes(void) const
  {
    return (_brain);
  }

  /*
  ** Setters.
  */
  void	GANN::setFitness(double fitness)
  {
    _fitness = fitness;
  }

  void	GANN::setGenes(ANN const& ann)
  {
    _brain = ann;
  }

  /*
  ** Methods.
  */
  void				GANN::Print(void)
  {
    std::vector<ANNLayer *>	layers = _brain.getLayers();

    std::cout << "Brain :" << std::endl;
    for (unsigned int i = 0; i < layers.size() && layers[i]; i++)
      std::cout << layers[i]->getWeights() << std::endl;
    std::cout << std::endl;
  }
}
