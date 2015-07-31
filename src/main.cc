//
// main.cc for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
// 
// Made by Guillaume ROBIN
// Login   <robin_f@epitech.eu>
// 
// Started on  Wed Jul 22 14:07:01 2015 Guillaume ROBIN
// Last update Fri Jul 31 14:39:13 2015 Guillaume ROBIN
//

#include <iostream>

#include "App/app.h"
#include "App/app_const.h"

int	       	main(int ac, char **av)
{
  App::App	app;

  if (ac >= 3)
    {
      try
	{
	  app.Run(av[1], av[2]);
	}
      catch (App::AppException const& e)
	{
	  std::cerr << e.what() << std::endl;
	}
    }
  else
    std::cerr << ERR_APP_HELP << std::endl;
  return (0);
}
