//
// environment.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Thu Jul 23 11:41:41 2015 Guillaume ROBIN
// Last update Thu Sep  3 15:55:34 2015 Guillaume ROBIN
//

#include <iostream>
#include <string>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#if defined(WIN32) && !defined(UNIX)
# include "compatibility/dirent.h"
# include "compatibility/dlfcn.h"
#elif defined(UNIX) && !defined(WIN32)
# include <dirent.h>
# include <dlfcn.h>
#endif

#include "Graphics/environment.h"
#include "Graphics/factory_object.h"
#include "Graphics/graphics_const.h"

namespace Graphics
{
  /*
  ** Constructor & Destructor.
  */
  Environment2D::Environment2D(std::string const& log): _log_path(log), _display(true),
							_isTournament(false), _num_epochs(0)
  {
    std::string	font_name("CODE Bold.otf");
    std::string	path(DEF_APP_FONTS);

    _font.loadFromFile(path + font_name);
    _best_fitness.setCharacterSize(18);
    _best_fitness.setColor(sf::Color::Black);
    _best_fitness.setStyle(sf::Text::Bold);
    _best_fitness.setPosition(sf::Vector2f(10, 30));
    _best_fitness.setFont(_font);
    _avg_fitness.setCharacterSize(18);
    _avg_fitness.setColor(sf::Color::Black);
    _avg_fitness.setStyle(sf::Text::Bold);
    _avg_fitness.setPosition(sf::Vector2f(10, 50));
    _avg_fitness.setFont(_font);
    _epochs.setCharacterSize(18);
    _epochs.setColor(sf::Color::Black);
    _epochs.setStyle(sf::Text::Bold);
    _epochs.setPosition(sf::Vector2f(10, 10));
    _epochs.setFont(_font);
    _window.setFramerateLimit(DEF_APP_FRAMER);
    if (log.size() > 0)
      {
	try
	  {
	    _log_stream.open(log, std::ofstream::out);
	  }
	catch (std::ofstream::failure e)
	  {
	    std::cerr << e.what() << std::endl;
	  }
      }
  }

  Environment2D::Environment2D(std::string const& log, unsigned int width,
			       unsigned int height): Environment2D(log)
  {
    if (_display)
      _window.create(sf::VideoMode(width, height), DEF_APP_TITLE, sf::Style::Default);
  }

  Environment2D::~Environment2D(void)
  {
    for (std::list<IObject *>::iterator it = _env.begin(); it != _env.end(); ++it)
      delete(*it);
    try
      {
	_log_stream.close();
      }
    catch (std::ofstream::failure e)
      {
	std::cerr << e.what() << std::endl;
      }
  }

  /*
  ** Getters.
  */
  std::list<IObject *> const&	Environment2D::getObjects(void) const
  {
    return (_env);
  }

  std::list<IObject *>&	Environment2D::getObjects(void)
  {
    return (_env);
  }

  Physics const&	Environment2D::getPhysics(void) const
  {
    return (_physics);
  }

  Physics&		Environment2D::getPhysics(void)
  {
    return (_physics);
  }

  sf::RenderWindow&	Environment2D::getWindow(void)
  {
    return (_window);
  }

  /*
  ** Setters.
  */
  static bool		lineIsValid(std::string line)
  {
    unsigned int	i = 0;

    while (i < line.size())
      {
	if ((line[i] < DEF_ENV_MINCHAR || line[i] > DEF_ENV_MAXCHAR)
	    && (line[i] < DEF_ENV_MINNUM || line[i] > DEF_ENV_MAXNUM)
	    && line[i] != DEF_ENV_DELIMCHAR && line[i] != DEF_ENV_SPACECHAR
	    && line[i] != DEF_ENV_UNDERCHAR && line[i] != DEF_ENV_DASHCHAR)
	  return (false);
	i++;
      }
    return (line.size() > 0 && line[0] != '\n');
  }

  static std::string	getTypeFromLine(std::string& line)
  {
    unsigned int	pos = line.find(DEF_ENV_DELIM);
    std::string		token = line.substr(0, pos);

    line.erase(0, pos + 1);
    return (token);
  }

  static unsigned int	getNumObjectsFromLine(std::string& line)
  {
    unsigned int	pos = line.find(DEF_ENV_DELIM);
    std::string		token = line.substr(0, pos);
    unsigned int	num;

    line.erase(0, pos + 1);
    try
      {
	num = std::stoi(token);
      }
    catch (std::invalid_argument const& e)
      {
	num = 0;
	std::cerr << ERR_ENV_INVALIDNUMOFOB << std::endl;
      }
    return (num);
  }

  void			Environment2D::LoadFromFile(const char *path)
  {
    std::ifstream      	file(path);
    std::string		line;
    std::string		type;
    unsigned int	num;
    unsigned int	found;
    bool		generate;
    FactoryObjects	factory;
    IObject		*ptr;

    if (file)
      {
        while (std::getline(file, line))
	  {
	    if (!lineIsValid(line))
	      continue ;
	    type = getTypeFromLine(line);
	    if (factory.Contains(type))
	      {
		num = getNumObjectsFromLine(line);
		found = line.find(DEF_ENV_BOOLEAN);
		if (found < line.size())
		  generate = true;
		else
		  generate = false;
		for (unsigned int i = 0; i < num; ++i)
		  {
		    if ((ptr = factory.Create(type)))
		      _env.push_back(ptr);
		    _physics.addGenerationSetting(type, generate);
		  }
	      }
	    else
	      std::cerr << ERR_ENV_INVALIDTYPE << std::endl;
	  }
	_physics.LoadEnvironmentSettings(_env);
      }
    else
      std::cerr << ERR_ENV_INVALIDFILE << std::endl;
  }

  void	Environment2D::setIsTournament(bool isTournament)
  {
    _isTournament = isTournament;
  }

  void	Environment2D::setDisplay(bool display)
  {
    _display = display;
  }

  /*
  ** Overload.
  */
  Environment2D&	Environment2D::operator=(Environment2D const& env)
  {
    _env = env.getObjects();
    _physics = env.getPhysics();
    return (*this);
  }

  /*
  ** Methods.
  */
  void		Environment2D::UpdateInfos(void)
  {
    IBrain	*brain;
    double	fitness = 0;
    double	avg_fit = 0;
    double	tmp;

    for (std::list<IObject *>::iterator it = _env.begin(); it != _env.end(); ++it)
      {
	if ((*it)->hasBrain() && (brain = dynamic_cast<IBrain *>((*it))))
	  {
	    if ((tmp = brain->getFitness()) > fitness)
	      fitness = tmp;
	    avg_fit += tmp;
	  }
      }
    avg_fit /= _env.size();
    _best_fitness.setString(std::string(DEF_ENV_STRBFITNESS) + std::to_string(fitness));
    _avg_fitness.setString(std::string(DEF_ENV_STRAFITNESS) + std::to_string(avg_fit));
    _epochs.setString(std::string(DEF_ENV_STREPOCHS) + std::to_string(_num_epochs));
  }

  void			Environment2D::Update(sf::Time elapsed)
  {
    _physics.UpdateColliders(_env);
    _physics.UpdateSensors(_env);
    for (std::list<IObject *>::iterator it = _env.begin(); it != _env.end(); ++it)
      {
	if (*it && !((*it)->isDead()))
	  {
	    (*it)->setElapsedTime(elapsed);
	    if (_log_stream.is_open())
	      _log_stream << (*it)->getType() << "," << (*it)->getPosition().x << ","
			  << (*it)->getPosition().y << std::endl;
	    (*it)->Update();
	  }
      }
    _physics.UpdateEnvironment(_env);
  }

  void	Environment2D::Draw(void)
  {
    _window.clear(sf::Color::White);
    for (std::list<IObject *>::iterator it = _env.begin(); it != _env.end(); ++it)
      _window.draw(*(*it));
    _window.draw(_epochs);
    _window.draw(_best_fitness);
    _window.draw(_avg_fitness);
    _window.display();
  }

  static unsigned int	countBrainAlive(std::list<IObject *>& env)
  {
    unsigned int	count = 0;

    for (std::list<IObject *>::iterator it = env.begin(); it != env.end(); ++it)
      {
	if ((*it)->hasBrain() && !(*it)->isDead())
	  ++count;
      }
    return (count);
  }

  static void		passInvalidFile(DIR *dir, struct dirent **info)
  {
    while (*info && ((*info)->d_name)[0] == DEF_ENV_POINTCHAR)
      *info = readdir(dir);
  }

  static void		saveRanking(std::list<IObject *>& env)
  {
    DIR			*dir;
    struct dirent	*info;
    std::string		filename;
    std::ofstream	file(DEF_APP_TOURN);

    if (file && (dir = opendir(DEF_APP_BRAINS)))
      {
	info = readdir(dir);
	passInvalidFile(dir, &info);
        for (std::list<IObject *>::iterator it = env.begin(); it != env.end(); ++it)
	  {
	    if ((*it)->hasBrain() && info)
	      {
		passInvalidFile(dir, &info);
		filename = std::string(info->d_name);
		file << filename + std::string(DEF_ENV_SEP_SCORE)
		  + std::to_string(((IBrain *)(*it))->getFitness()) << std::endl;
		info = readdir(dir);
	      }
	  }
	closedir(dir);
      }
  }

  static void	UpdateBrainsFitness(std::list<GA::IDNA *>& brains, std::list<IObject *>& env)
  {
    std::list<GA::IDNA *>::iterator iter = brains.begin();
    for (std::list<IObject *>::iterator it = env.begin(); it != env.end(); ++it)
      {
	if ((*it)->hasBrain() && dynamic_cast<IBrain *>((*it)) && iter != brains.end())
	  {
	    (*iter)->setFitness(((IBrain *)(*it))->getFitness());
	    ++iter;
	  }
      }
  }

  void		Environment2D::Run(std::list<GA::IDNA *>& brains)
  {
    sf::Clock	clock;
    sf::Event	event;

    if (!_isTournament)
      _physics.GenerateEnvironment(_env, brains);
    else
      _physics.GenerateTournament(_env, brains);
    while ((!_display || _window.isOpen()) && countBrainAlive(_env) > 0)
      {
	while (_window.pollEvent(event))
	  {
	    if (event.type == sf::Event::Closed)
	      _window.close();
	  }
	Update(clock.restart());
	if (_display)
	  Draw();
      }
    UpdateInfos();
    ++_num_epochs;
    UpdateBrainsFitness(brains, _env);
    if ((_display && !_window.isOpen()) || _isTournament)
      Notify(GA::AObserver::States::QUIT);
    if (_isTournament)
      saveRanking(_env);
  }
}
