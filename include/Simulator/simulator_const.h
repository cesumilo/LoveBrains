/*
** simulator_const.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 23 14:16:46 2015 Guillaume ROBIN
** Last update Thu Jul 30 19:36:57 2015 Guillaume ROBIN
*/

#ifndef SIMULATOR_CONST_H_
# define SIMULATOR_CONST_H_

/*
** Errors.
*/
# define ERR_SCONFIG_CROSSRATE	(const char *)"Error: Simulator: invalid crossing rate"
# define ERR_SCONFIG_MUTERATE	(const char *)"Error: Simulator: invalid mutation rate"
# define ERR_SCONFIG_SELECTRATE	(const char *)"Error: Simulator: invalid selection rate"
# define ERR_SCONFIG_POOLSIZE	(const char *)"Error: Simulator: invalid pool size"
# define ERR_SCONFIG_POPSIZE	(const char *)"Error: Simulator: invalid population size"
# define ERR_SCONFIG_INFOS	(const char *)"Error: Simulator: invalid neural net infos"
# define ERR_SCONFIG_FUNCTION	(const char *)"Error: Simulator: invalid function pointer (null)"
# define ERR_SCONFIG_ENVSIZE	(const char *)"Error: Simulator: invalid environment size"
# define ERR_SIMULATOR_ENV	(const char *)"Error: Simulator: environment is null"

/*
** Default values.
*/
# define DEF_MIN_RATE		(double)0.00
# define DEF_MAX_RATE		(double)1.00
# define DEF_CROSSING_RATE	(double)0.7
# define DEF_MUTATION_RATE	(double)0.1
# define DEF_SELECTION_RATE	(double)0.9
# define DEF_POOL_SIZE		(double)5
# define DEF_MAX_EPOCHS		(int)-1
# define DEF_REPORT_INTERVAL	(unsigned int)1
# define DEF_POPULATION_SIZE	(unsigned int)100
# define DEF_EXPECTED_FITNESS	(double)1

# define DEF_SIM_DELIM		(const char *)"-"
# define DEF_SIM_MINNUM		(char)'0'
# define DEF_SIM_MAXNUM		(char)'9'
# define DEF_SIM_DELIMCHAR	(char)'-'

#endif /* !SIMULATOR_CONST_H_ */
