//
// physics.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Wed Jul 22 15:14:26 2015 Guillaume ROBIN
// Last update Mon Aug 24 15:19:59 2015 Guillaume ROBIN
//

#include <iostream>
#include <type_traits>

#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "Graphics/physics.h"
#include "Graphics/graphics_const.h"
#include "GANN/gann.h"
#include "Graphics/i_brain.h"

namespace Graphics
{
  /*
  ** Constructor & Destructor.
  */
  Physics::Physics(void)
  {
  }

  Physics::~Physics(void)
  {
    for (unsigned int i = 0; i < _colls.size(); ++i)
      delete(_colls[i]);
    for (unsigned int i = 0; i < _sensors.size(); ++i)
      delete(_sensors[i]);
  }

  /*
  ** Getters.
  */
  std::vector<ICollider *> const&	Physics::getColliders(void) const
  {
    return (_colls);
  }

  std::vector<ISensor *> const&	Physics::getSensors(void) const
  {
    return (_sensors);
  }

  std::map<std::string, int> const&	Physics::getEnvironmentSettings(void) const
  {
    return (_env_settings);
  }

  std::map<std::string, int> const&	Physics::getCurrentEnvironment(void) const
  {
    return (_cur_settings);
  }

  std::map<std::string, bool> const&	Physics::getGenerationSettings(void) const
  {
    return (_gen_settings);
  }

  /*
  ** Setters.
  */
  void	Physics::addCollider(ICollider *collider)
  {
    if (collider)
      _colls.push_back(collider);
  }

  void	Physics::addSensor(ISensor *sensor)
  {
    if (sensor)
      _sensors.push_back(sensor);
  }

  void	Physics::addGenerationSetting(std::string type, bool generate)
  {
    if (_gen_settings.find(type) == _gen_settings.end())
      _gen_settings[type] = generate;
  }

  /*
  ** Overload.
  */
  Physics&	Physics::operator=(Physics const& physics)
  {
    _colls = physics.getColliders();
    _sensors = physics.getSensors();
    _env_settings = physics.getEnvironmentSettings();
    _cur_settings = physics.getCurrentEnvironment();
    _gen_settings = physics.getGenerationSettings();
    return (*this);
  }

  /*
  ** Methods.
  */
  void		Physics::LoadEnvironmentSettings(std::list<IObject *>& env)
  {
    std::string	key;

    for (std::list<IObject *>::iterator it = env.begin(); it != env.end(); ++it)
      {
	if (*it)
	  {
	    key = (*it)->getType();
	    if (_env_settings.find(key) == _env_settings.end())
	      {
		_env_settings[key] = 1;
		_cur_settings[key] = 1;
	      }
	    else
	      {
		++_env_settings[key];
		++_cur_settings[key];
	      }
	  }
      }
  }

  void		Physics::UpdateEnvironment(std::list<IObject *>& env)
  {
    IObject	*ptr;
    std::string	key;

    for (std::list<IObject *>::iterator it = env.begin(); it != env.end(); ++it)
      {
	if (*it)
	  {
	    key = (*it)->getType();
	    if ((*it)->isDead())
	      _cur_settings[key]--;
	  }
      }
    for (std::list<IObject *>::iterator it = env.begin(); it != env.end(); ++it)
      {
	if (*it)
	  {
	    key = (*it)->getType();
	    if (!(*it)->hasBrain() && (*it)->isDead() && _cur_settings[key] < _env_settings[key])
	      {
		it = env.erase(it);
		if (_gen_settings[key])
		  {
		    ++it;
		    if (!(ptr = _factory.Create(key)))
		      std::cerr << ERR_PHYSICS_CREATE << std::endl;
		    else
		      {
			env.insert(it, ptr);
			++_cur_settings[key];
		      }
		    --it;
		  }
	      }
	  }
      }
  }

  void		Physics::UpdateColliders(std::list<IObject *>& env) const
  {
    IBehavior	*action;

    for (std::list<IObject *>::iterator it1 = env.begin(); it1 != env.end(); ++it1)
      {
	for (std::list<IObject *>::iterator it2 = env.begin(); it2 != env.end(); ++it2)
	  {
	    for (unsigned int i = 0; i < _colls.size(); ++i)
	      {
		if (_colls[i] && _colls[i]->isValid((*it1)->getType(), (*it2)->getType())
		    && _colls[i]->isCollision(*it1, *it2) && (action = _colls[i]->getAction()))
		  {
		    action->Update(*it1);
		    action->Update(*it2);
		  }
	      }
	  }
      }
  }

  void	Physics::UpdateSensors(std::list<IObject *>& env) const
  {
    for (unsigned int i = 0; i < _sensors.size(); ++i)
      {
	for (std::list<IObject *>::iterator it = env.begin(); it != env.end(); ++it)
	  {
	    if (*it && _sensors[i] && _sensors[i]->isValid(*it))
	      _sensors[i]->Update(*it, env);
	  }
      }
  }

  void	       	Physics::GenerateEnvironment(std::list<IObject *>& env,
					     std::list<GA::IDNA *>& brains)
  {
    IObject    	*ptr;
    std::list<GA::IDNA *>::iterator	br = brains.begin();

    for (std::list<IObject *>::iterator it = env.begin(); it != env.end(); ++it)
      delete(*it);
    env.clear();
    for (std::map<std::string, int>::iterator it = _env_settings.begin();
	 it != _env_settings.end(); ++it)
      {
	for (int i = 0; i < it->second; ++i)
	  {
	    if ((ptr = _factory.Create(it->first)))
	      {
		if (ptr->hasBrain() && dynamic_cast<IBrain *>(ptr) && br != brains.end())
		  {
		    ((IBrain *)ptr)->setBrain(((GANN::GANN *)(*br))->getGenes());
		    ++br;
		  }
		env.push_back(ptr);
	      }
	  }
      }
  }

  static void		passInvalidFile(DIR *dir, struct dirent **info)
  {
    while (*info && ((*info)->d_name)[0] == DEF_ENV_POINTCHAR)
      *info = readdir(dir);
  }

  void		Physics::GenerateTournament(std::list<IObject *>& env,
					    std::list<GA::IDNA *>& brains)
  {
    DIR *dir;
    struct dirent *info;
    std::string path;
    IObject *ptr;
    std::list<GA::IDNA *>::iterator br = brains.begin();
    GANN::ANN brain;

    if ((dir = opendir(DEF_APP_BRAINS)))
      {
	for (std::list<IObject *>::iterator it = env.begin(); it != env.end(); ++it)
	  delete(*it);
	env.clear();
	for (std::map<std::string, int>::iterator it = _env_settings.begin();
	     it != _env_settings.end(); ++it)
	  {
	    for (int i = 0; i < it->second; ++i)
	      {
		if ((ptr = _factory.Create(it->first)))
		  {
		    if (ptr->hasBrain() && dynamic_cast<IBrain *>(ptr) && br != brains.end())
		      {
			brain = ((GANN::GANN *)(*br))->getGenes();
			if ((info = readdir(dir)))
			  {
			    passInvalidFile(dir, &info);
			    path = std::string(DEF_APP_BRAINS) + std::string(info->d_name);
			    try
			      {
				brain.Load(path.c_str());
			      }
			    catch (GANN::ANNException const& e)
			      {
				std::cerr << e.what() << std::endl;
			      }
			  }
			((IBrain *)ptr)->setBrain(brain);
			++br;
		      }
		    env.push_back(ptr);
		  }
	      }
	  }
	closedir(dir);
      }
  }
}
