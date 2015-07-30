//
// a_nanobrain.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Wed Jul 29 17:09:59 2015 Guillaume ROBIN
// Last update Thu Jul 30 10:53:39 2015 Guillaume ROBIN
//

#include "Graphics/a_nanobrain.h"
#include "Graphics/graphics_const.h"

namespace Graphics
{
  /*
  ** Constructor & Destructor.
  */
  ANanoBrain::ANanoBrain(void): AObject(), _fitness(0)
  {
  }

  ANanoBrain::ANanoBrain(GANN::ANN const& brain): ANanoBrain()
  {
    _brain = brain;
    _inputs = GANN::Matrix<double>(brain.getInfos()[0], 1, 0);
  }

  ANanoBrain::ANanoBrain(ANanoBrain const& nbrain): ANanoBrain()
  {
    _fitness = nbrain.getFitness();
    _brain = nbrain.getBrain();
    _inputs = GANN::Matrix<double>(_brain.getInfos()[0], 1, 0);
  }

  ANanoBrain::~ANanoBrain(void)
  {
  }

  /*
  ** Getters.
  */
  std::string	ANanoBrain::getType(void) const
  {
    return (std::string(DEF_IA_TYPE));
  }

  double	ANanoBrain::getFitness(void) const
  {
    return (_fitness);
  }

  GANN::ANN const&	ANanoBrain::getBrain(void) const
  {
    return (_brain);
  }

  GANN::Matrix<double> const&	ANanoBrain::getActions(void)
  {
    _brain.Activate(_inputs);
    return (_brain.getOutputs());
  }

  /*
  ** Setters.
  */
  void	ANanoBrain::setFitness(double fitness)
  {
    _fitness = fitness;
  }

  void	ANanoBrain::setBrain(GANN::ANN const& brain)
  {
    _brain = brain;
    _inputs = GANN::Matrix<double>(brain.getInfos()[0], 1, 0);
  }

  void	ANanoBrain::setInput(unsigned int index, double value)
  {
    _inputs(index, 0) = value;
  }
}
