/*
** a_object.h for LoveBrains in /home/robin_f/Programming/Git/CPP/LoveBrains
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul 22 12:05:50 2015 Guillaume ROBIN
** Last update Fri Aug 21 15:18:36 2015 Guillaume ROBIN
*/

#ifndef I_OBJECT_H_
# define I_OBJECT_H_

# include <vector>
# include <string>
# include <SFML/Graphics.hpp>

namespace Graphics
{
  /*!
   * \class IObject
   * \brief Define the interface of an object.
   */
  class IObject : public sf::Drawable
  {
  public:
    /*!
     * \brief Destructor.
     */
    virtual ~IObject(void) { }

    /*
    ** Getters.
    */

    /*!
     * \brief Verify if the object is dead (not be able to draw).
     * \return true : if the object is dead.
     * \return false : if the object is not dead.
     */
    virtual bool	       	isDead(void) const = 0;
    /*!
     * \brief Verify if the object contains a neural network.
     * \return true : if the object has a neural network.
     * \return false : if the object doesn't have not a neural netowrk.
     */
    virtual bool		hasBrain(void) const = 0;
    /*!
     * \brief Get the ky (type) of the object in the environment.
     * \return std::string
     */
    virtual std::string		getType(void) const = 0;

    /*
    ** Setters.
    */

    /*!
     * \brief Set the current position of the object.
     * \param position : Contains the new position of the object.
     */
    virtual void	setPosition(sf::Vector2f const& position) = 0;
    /*!
     * \brief Set the current state of the object.
     * \param condition : Contains if the object is dead or not.
     */
    virtual void	setIsDead(bool condition) = 0;
    /*!
     * \brief Set the elapsed time between the previous and the current update.
     * \param time : Contains the delta time.
     */
    virtual void	setElapsedTime(sf::Time& time) = 0;

    /*
    ** Methods.
    */

    /*!
     * \brief Clone the current object.
     * \return success : IObject
     * \return error : NULL
     */
    virtual IObject	*Clone(void) = 0;
    /*!
     * \brief Update the object.
     */
    virtual void	Update(void) = 0;

  protected:
    /*!
     * \brief Allow the object to be drawn on the window.
     * \param target : Contains the render target.
     * \param states : Contains the current state of the render target.
     */
    virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
  };
}

#endif /* !A_OBJECT_H_ */
