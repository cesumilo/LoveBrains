/*
** i_config.h for GAEngine in /home/robin_f/Programming/Git/CPP/GAEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Tue Jul 21 13:02:43 2015 Guillaume ROBIN
** Last update Tue Jul 28 16:14:27 2015 Guillaume ROBIN
*/

#ifndef GA_CONFIG_H_
# define GA_CONFIG_H_

# include <list>

# include "GA/i_generator.h"

namespace GA
{
  class GAConfig
  {
  public:
    /*
    ** Typedef.
    */
    typedef void	(*FEvaluate)(std::list<IDNA *>&);
    typedef void	(*DNAFitness)(IDNA *, double *);
    typedef bool	(*DNACompare)(const IDNA *, const IDNA *);
    typedef IDNA	*(*DNACrossover)(const IDNA *, const IDNA *);
    typedef void	(*DNAMutate)(IDNA *);

    GAConfig(void);
    ~GAConfig(void);

    GAConfig&	operator=(GAConfig const& config);

    bool	isEvaluated(void) const;
    bool	isValid(void) const;

    void	setEvaluation(FEvaluate function);
    void	setGenerator(IGenerator *generator);
    void	setDNAFitness(DNAFitness function);
    void	setDNACompare(DNACompare function);
    void	setDNACrossover(DNACrossover function);
    void	setDNAMutate(DNAMutate function);

    FEvaluate		getEvaluation(void) const;
    IGenerator		*getGenerator(void) const;
    DNAFitness		getDNAFitness(void) const;
    DNACompare		getDNACompare(void) const;
    DNACrossover	getDNACrossover(void) const;
    DNAMutate		getDNAMutate(void) const;

  private:
    FEvaluate		_evaluate;
    IGenerator		*_generator;
    DNAFitness		_fitness;
    DNACompare		_compare;
    DNACrossover	_crossover;
    DNAMutate		_mutate;
  };
}

#endif /* !GA_CONFIG_H_ */
