/*
** const.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul  9 11:32:06 2015 Guillaume ROBIN
** Last update Tue Jul 21 13:58:14 2015 Guillaume ROBIN
*/

#ifndef GA_CONST_H_
# define GA_CONST_H_

# define IF_EPOCHS(epochs, max_epochs)((max_epochs) < 0 ? true : (epochs) < (max_epochs))
# define ABS(x)((x) < 0 ? -(x) : (x))

# define DEF_POOL_SIZE	(unsigned int)4
# define DEF_MUT_RATE	(double)0.1
# define DEF_SEL_RATE	(double)0.9
# define DEF_MAX_EPOCHS	(int)-1
# define DEF_EXPEC_FIT	(double)100
# define DEF_NUM_THREAD	(unsigned int)2
# define DEF_INT_REPORT	(unsigned int)1
# define DEF_MIN_SIZE	(unsigned int)2

# define ERR_POP_SIZE	(const char *)"Error: Population::setSize: invalid size of population."
# define ERR_POP_PSIZE	(const char *)"Error: Population::setPoolSize: invalid pool size."
# define ERR_POP_MUT	(const char *)"Error: Population::setMutationRate: invalid mutation rate."
# define ERR_POP_SELT	(const char *)"Error: Population::setSelectionRate: invalid selection rate."
# define ERR_POP_GEN	(const char *)"Error: Population::Generate: allocation fail."
# define ERR_POP_EVAL	(const char *)"Error: Population::Evaluate: allocation fail."
# define ERR_POP_CROSS	(const char *)"Error: Population::Crossover: allocation fail."

# define ERR_GA_POPSIZE	(const char *)"Error: GAEngine: Invalid population size"
# define ERR_GA_POOSIZE	(const char *)"Error: GAEngine: Invalid pool size"
# define ERR_GA_MUTR	(const char *)"Error: GAEngine: Invalid mutation rate"
# define ERR_GA_SELR	(const char *)"Error: GAEngine: Invalid selection rate"
# define ERR_GA_GENERAT	(const char *)"Error: GAEngine: No DNA Generator defined"
# define ERR_GA_FFIT	(const char *)"Error: GAEngine: No DNA Fitness Function defined"
# define ERR_GA_FCOMP	(const char *)"Error: GAEngine: No DNA Compare Function defined"
# define ERR_GA_FMUT	(const char *)"Error: GAEngine: No DNA Mutation Function defined"
# define ERR_GA_FCROSS	(const char *)"Error: GAEngine: No DNA Crossover Function defined"
# define ERR_GA_NOCONF	(const char *)"Error: GAEngine: No config is provided !"

# define STR_POP_SIZE	(const char *)"Population size: "
# define STR_POP_MUT	(const char *)"Mutation rate: "
# define STR_POP_SELT	(const char *)"Selection rate: "
# define STR_POP_BFIT	(const char *)"Best fitness: "
# define STR_POP_AFIT	(const char *)"Average fitness: "
# define STR_POP_GENES	(const char *)"Best individual: "

# define STR_GA_EPOCHS	(const char *)"Epochs: "

#endif /* !GA_CONST_H_ */
