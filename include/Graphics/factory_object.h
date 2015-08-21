/*
** factory_object.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 13:55:29 2015 Guillaume ROBIN
** Last update Fri Aug 21 14:45:37 2015 Guillaume ROBIN
*/

#ifndef FACTORY_OBJECT_H_
# define FACTORY_OBJECT_H_

# include <map>
# include "Graphics/i_object.h"

namespace Graphics
{
  /*!
   * \class FactoryObjects
   * \brief Define a factory of objects that will fill the environment in term of the environment file.
   */
  class FactoryObjects
  {
  public:
    /*!
     * \brief Constructor.
     */
    FactoryObjects(void);
    /*!
     * \brief Destructor.
     */
    ~FactoryObjects(void);

    /*!
     * \brief Register a new object in the factory.
     * \param key : Contains the key of the object.
     * \param obj : Contains the object that will be cloned in order to create a new object.
     */
    static void	Register(std::string const& key, IObject* obj);
    /*!
     * \brief Delete all the objects that have been registered in the factory.
     */
    static void	DeleteAll(void);
    /*!
     * \brief Create a new object of the given key.
     * \param key : Contains the key of the object.
     */
    IObject	*Create(std::string const& key) const;
    /*!
     * \brief Search if an object is contained in the factory.
     * \param key : Contains the key of the object.
     * \return true : if it's contained.
     * \return false : if it's not contained.
     */
    bool	Contains(std::string const& key) const;

  private:
    static std::map<std::string, IObject *>	_map; /*!< Contains all the objects with their keys. */
  };
}

#endif /* !FACTORY_OBJECT_H_ */
