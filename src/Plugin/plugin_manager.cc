//
// plugin_manager.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Jul 30 11:52:48 2015 Guillaume ROBIN
// Last update Thu Jul 30 19:23:59 2015 Guillaume ROBIN
//

#include <iostream>

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#if defined(WIN32) && !defined(UNIX)
# include "compatibility/dirent.h"
# include "compatibility/dlfcn.h"
#else
# include <dirent.h>
# include <dlfcn.h>
#endif

#include "Plugin/plugin_manager.h"
#include "Plugin/plugin_const.h"

namespace Plugin
{
  /*
  ** Constructor & Destructor.
  */
  PluginManager::PluginManager(void) throw()
  {
  }

  PluginManager::~PluginManager(void) throw()
  {
  }

  /*
  ** Methods.
  */
  static bool		isPlugin(const char *filename)
  {
    unsigned int	size;

    if ((size = strlen(filename)) <= 3)
      return (false);
    if (filename[size - 1] == (DEF_NAME_EXT)[2]
	&& filename[size - 2] == (DEF_NAME_EXT)[1]
	&& filename[size - 3] == (DEF_NAME_EXT)[0])
      return (true);
    return (false);
  }

  void		       		PluginManager::LoadPlugins(void)
  {
    DIR		       		*dir;
    struct dirent      		*info;
    void	       		*handler;
    char			*error;
    IPlugin::PluginCreator	create;
    IPlugin			*ptr;
    std::string			path;

    if ((dir = opendir(DEF_PATH_DIRECTORY)))
      {
	while ((info = readdir(dir)))
	  {
	    if (isPlugin(info->d_name))
	      {
		path = std::string(DEF_PATH_DIRECTORY) + std::string(info->d_name);
		if (!(handler = dlopen(path.c_str(), RTLD_LAZY)))
		  {
		    closedir(dir);
		    throw (PluginException(dlerror()));
		  }
		dlerror();
		*(void **)(&create) = dlsym(handler, DEF_PLUGIN_STARTFUNC);
		if ((error = dlerror()))
		  {
		    closedir(dir);
		    throw (PluginException(error));
		  }
		if (!(ptr = (*create)()))
		  throw (PluginException(ERR_PLUGIN_INVALID));
		std::cerr << "Found one plugin!" << std::endl;
		_plugs.push_back(ptr);
		_handlers.push_back(handler);
	      }
	  }
	if (closedir(dir) == -1)
	  throw (PluginException(ERR_PLUGIN_CLOSEDIR));
      }
    else
      throw (PluginException(ERR_PLUGIN_DIR));
  }

  void					PluginManager::LoadObjects(void)
  {
    std::vector<Graphics::IObject *>	objs;

    for (unsigned int i = 0; i < _plugs.size(); ++i)
      {
	if (_plugs[i])
	  {
	    objs = _plugs[i]->getObjects();
	    std::cerr << "Number of objects: " << objs.size() << std::endl;
	    for (unsigned int j = 0; j < objs.size(); ++j)
	      {
		std::cerr << "Object[" << j << "] type: " << objs[j]->getType() << std::endl;
		std::cerr << "Object[" << j << "] hasBrain: " << (objs[j]->hasBrain() ? "true" : "false") << std::endl;
		if (objs[j])
		  Graphics::FactoryObjects::Register(objs[j]->getType(), objs[j]);
	      }
	  }
      }
  }

  void	PluginManager::LoadColliders(Graphics::Physics& physics)
  {
    std::vector<Graphics::ICollider *>	colls;

    for (unsigned int i = 0; i < _plugs.size(); ++i)
      {
	colls = _plugs[i]->getColliders();
	for (unsigned int j = 0; j < colls.size(); ++j)
	  {
	    if (colls[j])
	      physics.addCollider(colls[j]);
	  }
      }
  }

  void	PluginManager::LoadSensors(Graphics::Physics& physics)
  {
    std::vector<Graphics::ISensor *>	sensors;

    for (unsigned int i = 0; i < _plugs.size(); ++i)
      {
	sensors = _plugs[i]->getSensors();
	for (unsigned int j = 0; j < sensors.size(); ++j)
	  {
	    if (sensors[j])
	      physics.addSensor(sensors[j]);
	  }
      }
  }

  void	PluginManager::ClosePlugins(void)
  {
    for (unsigned int i = 0; i < _plugs.size(); ++i)
      delete(_plugs[i]);
    for (unsigned int i = 0; i < _handlers.size(); ++i)
      {
	if (dlclose(_handlers[i]) != 0)
	  throw (PluginException(ERR_PLUGIN_DLCLOSE));
      }
  }
}
