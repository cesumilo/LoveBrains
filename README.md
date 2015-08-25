# LoveBrains

# Description
LoveBrains is a simulator of artificial intelligence based on a plugin system. It provides an 2D environment that allows you to create any kind of simulation. The engine uses Artificial Neural Network and Genetic Algorithm with the aim of learning how to get the best score.

# Documentation
<a href="http://cesumilo.github.io/LoveBrains">LoveBrains documentation (doxygen)</a>

# How to use LoveBrains ?

## Requirements

Programming :

- C++

- Oriented Object Programming

-  <a href="http://www.sfml-dev.org/learn-fr.php">SFML Library</a>

- <a href="https://github.com/cesumilo/LoveBrains/tree/master/api">LoveBrains API</a>

Concept :

- <a href="https://en.wikipedia.org/wiki/Artificial_neural_network">Artificial Neural Network</a>

- <a href="https://en.wikipedia.org/wiki/Genetic_algorithm">Genetic Algorithm</a>

## How to create a simulation ?

In order to create a simulation, you have to code a plugin. Each plugin must be stored at the root of the directory called "mods". There is an API that allows you to create your own objects, colliders, behaviors and sensors. In fact, each simulation needs some objects. The objects can interact with the environment with the help of the colliders. Each collider has to have a behavior which will modify the object. If you create an object which has an artificial neural network you will need to create sensors. They will give informations about the environment to the neural network and help it to take a decision. A plugin is not simple, you have to think about it before coding it !

## Compile a plugin

This is an example of Makefile that compile the basic survival plugin :

```make
CC	= g++

RM	= rm -f

NAME	= plugin_name.so # Replace by your plugin name, ".so" is MANDATORY !

CXXFLAGS	+= -std=c++11

CXXFLAGS	+= -I ./include/ -I ./api/include/ -I ./api/lib/ANNLibrary/include/

LDFLAGS	= -lsfml-graphics -lsfml-window -lsfml-system -lm -lANN -L./api/lib/ANNLibrary/

SRCS	+= # Add sources here !

OBJS	= $(SRCS:.cc=.o)


all: lib $(NAME)

lib:
	make -C ./api/lib/ANNLibrary/

clib:
	make clean -C ./api/lib/ANNLibrary/

flib:
	make fclean -C ./api/lib/ANNLibrary/

%.o: %.cc
	$(CC) -fPIC $(CXXFLAGS) -c $< $(LDFLAGS) -o $@

$(NAME): $(OBJS)
	$(CC) -shared $(CXXFLAGS) $(OBJS) -o $(NAME) -Wl,--whole-archive -lANN -L./api/lib/ANNLibrary -Wl,--no-whole-archive

clean: clib
	$(RM) $(OBJS)

fclean: clean flib
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean lib clib flib
```

**You can compile your own plugin with the same Makefile.**

## Create an object

When you want to code a plugin, you have to add some objects to the simulator. In order to create an object that will be compatible with LoveBrains, it has to inherit from the interface called **"IObject"** (<a href="http://cesumilo.github.io/LoveBrains/class_graphics_1_1_i_object.html">What is the IObject interface ?</a>).

If you want to create an artificial intelligence, the class has to inherit from the interface called **"IBrain"** (<a href="http://cesumilo.github.io/LoveBrains/class_graphics_1_1_i_brain.html">What is the IBrain interface ?</a>).

```c++
// IObject example.
class Food : public Graphics::IObject
{
	public:
		Food();
		~Food();

		bool isDead() const;
		bool hasBrain() const;
		std::string getType() const;

		void setPosition(sf::Vector2f const& position);
		void setIsDead(bool isDead);
		void setElapsedTime(sf::Time& time);

		Graphics::IObject *Clone(void);
		void Update(void);
	private:
		bool _dead;
		sf::Vector2f _position;
};

// IBrain example.
class AIObject : public Graphics::IBrain
{
	public:
		AIObject();
		~AIObject();

		// Graphics::IObject.
		bool isDead() const;
		bool hasBrain() const;
		std::string getType() const;
		
		// Graphics::IBrain.
		double getFitness() const;
		
		// Graphics::IObject.
		void setPosition(sf::Vector2f const& position);
		void setIsDead(bool isDead);
		void setElapsedTime(sf::Time& time);
		
		// Graphics::IBrain.
		void setFitness(double fitness);
		void setBrain(GANN::ANN const& brain);
		void setInput(unsigned int index, double value);

		Graphics::IObject *Clone(void);
		void Update(void);
	private:
		bool _dead;
		double _fitness;
		sf::Vector2f _position;
		GANN::ANN _brain;
};
```

## Create a plugin

The way to create a plugin is very simple. First you have to define a class that inherit from the interface called **"IPlugin"** (<a href="http://cesumilo.github.io/LoveBrains/class_plugin_1_1_i_plugin.html">What is the IPlugin interface ?</a>). The plugin will be able to add some objects, colliders and sensors to the objects factory of LoveBrains.

```c++
// IPlugin example.
class Plugin : public Plugin::IPlugin
{
	public:
		Plugin();
		~Plugin();

		std::vector<Graphics::IObject *>& getObjects(void);
		std::vector<Graphics::ICollider *>& getColliders(void);
		std::vector<Graphics::ISensor *>& getSensors(void);

	private:
};
```

Be careful ! There is a function that will be needed by LoveBrains in order to create your plugin !

```c++
extern "C"
{
  Plugin::IPlugin	*CreatePlugin(void)
  {
	// Replace "PluginClass" by your plugin class name.
    return (new PluginClass());
  }
}
```

## Add a plugin in LoveBrains

If you want to add your plugin in LoveBrains, it's very simple ! You have to copy your ".so" file at the root of the directory called **"mods"**.

## Set the simulator's configurations

As you can see, there are two files with LoveBrains. First, the simulator configurations file and then the environment configurations file. In this part, I will show you how to set the simulator with its file.

```bash
# Simulator Configuration file

# The crossing rate is a characteristic of the genetic algorithm.
# The range is between 0 and 1.
# It will determine the percentage of parent's genes that will be add to the child.
crossing_rate: 0.7

# The mutation rate is a characteristic of the genetic algortihm.
# The range is between 0 and 1.
# It will determine the percentage of chance that has the individual to mutate.
mutation_rate: 0.1

# The selection rate is a characteristic of the genetic algorithm.
# The range is between 0 and 1.
# It will determine the percentage of individuals that will be removed in the next generation.
selection_rate: 0.9

# It will determine the score that we want to reach.
expected_fitness: 10000

# The tournament pool size is a characteristic of the genetic algorithm.
# The range is between 1 and POPULATION_SIZE.
# It will determine the size of pool in the tournament. The tournament will randomly create a pool of pool_size individuals. The engine will take the best individual in this pool and add it to the parents. At the end of the tournament, there is a list of parents that will be used to generate the childs for the next generation.
tournament pool_size: 5

# It will determine how many epochs that you want to do. -1 says to the engine that there is not maximum epochs.
max epochs: -1

# It will determine the interval between each report of the population.
report interval: 10

# It will determine the size of the population. Be careful ! The size of the population means the number of artificial intelligences in the environment. The size of the population has to be the same as the number of artificial intelligences in the environment configurations.
population size: 50

# It will determine the topology of the neural network. Be careful about it, it's in relation with your simulation.
neural network: 2-2-5

# It will determine if the simulator is in "tournament" mode or not.
tournament: false

# It will determine the display mode.
# Values : NONE, 2D
display mode: 2D

# It will determine the activation function for the intern layers of the neural network.
# Value : sigmoid, threshold
activation function: sigmoid

# It will determine the activation function for the output layer of the neural network.
# Values : sigmoid, threshold
outputs activation function: sigmoid

# It will determine the size of the window.
environment size: 1280x720
```

## Set the environment's configurations

The environment configurations file provides the informations about the environment. You have to write the type of the object, the number of object in the environment and if it will be generated by the physics engine when one of them dies.

```bash
# This is a file that provides objets for the simulation

# type, number of object, generation condition.
basic_food, 60, true # Object of type "basic_food" is given in the basic survival plugin.
basic_survival_ai, 50, false # Object of type "basic_survival_ai" is given in the basic survival plugin.
```

## Set the tournament mode

First you have to set the tournament mode in the simulator configurations file. The effect of this option is that LoveBrains will generate some AI with the neural networks given at the root of the directory called **"brains"**. At the end of the simulation, it will create a file **"tournament.txt"** which contains the score of each AI created with a file.

```bash
# Simulator configurations file.
[...]
tournament: true
[...]
```

## Example

You will find an example of plugin in the directory **"mods"** which is called **"basic_survival"**. It is ready to be compiled and runned in the simulator. You have to move the file *"basic_survival.so"* at the root of the directory called **"mods"**.

# Licence
<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">LoveBrains</span> by <span xmlns:cc="http://creativecommons.org/ns#" property="cc:attributionName">Robin Guillaume</span> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.<br />Based on a work at <a xmlns:dct="http://purl.org/dc/terms/" href="https://github.com/cesumilo/LoveBrains" rel="dct:source">https://github.com/cesumilo/LoveBrains</a>.
