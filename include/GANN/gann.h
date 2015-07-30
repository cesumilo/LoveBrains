/*
** gann.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Sun Jul 19 22:00:11 2015 Guillaume ROBIN
** Last update Tue Jul 21 16:58:11 2015 Guillaume ROBIN
*/

#ifndef GANN_H_
# define GANN_H_

# include <vector>

# include "GA/i_dna.h"
# include "ANN/neural_net.h"

namespace GANN
{
  class GANN : public GA::IDNA
  {
  public:
    GANN(std::vector<unsigned int> const& infos);
    GANN(ANN const& ann);
    ~GANN(void);

    /*
    ** Getters.
    */
    double	getFitness(void) const;
    ANN const&	getGenes(void) const;

    /*
    ** Setters.
    */
    void	setFitness(double fitness);
    void	setGenes(ANN const& ann);

    /*
    ** Methods.
    */
    void	Print(void);

  private:
    ANN		_brain;
    double	_fitness;
  };
}

#endif /* !GANN_H_ */
