/*
** plugin_const.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Thu Jul 30 11:51:25 2015 Guillaume ROBIN
** Last update Thu Jul 30 14:04:28 2015 Guillaume ROBIN
*/

#ifndef PLUGIN_CONST_H_
# define PLUGIN_CONST_H_

/*
** String Errors.
*/
# define ERR_PLUGIN_DIR		(const char *)"Error: PluginManager: directory not found"
# define ERR_PLUGIN_CLOSEDIR	(const char *)"Error: PluginManager: cannot close the directory"
# define ERR_PLUGIN_DLOPEN	(const char *)"Error: PluginManager: cannot open a plugin"
# define ERR_PLUGIN_INVALID	(const char *)"Error: PluginManager: invalid plugin"
# define ERR_PLUGIN_DLCLOSE	(const char *)"Error: PluginManager: cannot close a plugin"

/*
** Default values.
*/
# define DEF_PATH_DIRECTORY	(const char *)"./mods/"
# define DEF_NAME_EXT		(const char *)".so"
# define DEF_PLUGIN_STARTFUNC	(const char *)"CreatePlugin"

#endif /* !PLUGIN_CONST_H_ */
