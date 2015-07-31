/*
** matrix.h for GANNEngine in /home/robin_f/Programming/Git/CPP/GANNEngine/include/ANN
** 
** Made by Guillaume ROBIN
** Login   <robin_f@epitech.eu>
** 
** Started on  Wed Jul  8 14:03:07 2015 Guillaume ROBIN
** Last update Tue Jul 14 13:20:31 2015 Guillaume ROBIN
*/

#ifndef MATRIX_H_
# define MATRIX_H_

# include <vector>
# include <iostream>

# define ERR_MATRIX_RANGE	(char *)"Error: Matrix: index is out of range !"
# define ERR_MATRIX_INVALID	(char *)"Error: Matrix: size is invalid !"
# define ERR_MATRIX_INVOP	(char *)"Error: Matrix: invalid operation !"

# define RANGE(i, j, m_i, m_j)((i) >= 0 && (j) >= 0 && (i) < (m_i) && (j) < (m_j) ? true : false)

namespace GANN
{
  template <typename T>
  class Matrix
  {
  public:
    Matrix(void)
    {
      _rows = 1;
      _cols = 1;
    }
    Matrix(unsigned int rows, unsigned int cols, T const& elem)
    {
      if (rows == 0 || cols == 0)
	{
	  std::cerr << ERR_MATRIX_INVALID << std::endl;
	  _rows = 1;
	  _cols = 1;
	}
      else
	{
	  _rows = rows;
	  _cols = cols;
	}
      _init = elem;
      for (unsigned int i = 0; i < rows * cols; i++)
	_m.push_back(elem);
    }
    Matrix(Matrix const& copy)
    {
      _rows = copy.rows();
      _cols = copy.cols();
      _init = copy.init();
      _m.clear();
      for (unsigned int i = 0; i < _rows * _cols; i++)
	_m.push_back(copy[i]);
    }

    /*
    ** Getters.
    */
    unsigned int	rows(void) const { return (_rows); }
    unsigned int	cols(void) const { return (_cols); }
    T const&		init(void) const { return (_init); }
    Matrix<T>		identity(unsigned int size, T const& null, T const& id)
    {
      Matrix<T>		m(size, size, null);

      for (unsigned int i = 0; i < size; i++)
	m(i, i) = id;
      return (m);
    }

    /*
    ** Overload.
    */
    Matrix<T>&	operator=(Matrix<T> const& m)
    {
      _rows = m.rows();
      _cols = m.cols();
      _m.clear();
      for (unsigned int i = 0; i < _rows * _cols; i++)
	_m.push_back(m[i]);
      return (*this);
    }
    const T&	operator[](unsigned int i) const
    {
      if (i < _rows * _cols)
	return (_m[i]);
      else
	std::cerr << ERR_MATRIX_RANGE << std::endl;
      return (_m[_rows * _cols - 1]);
    }
    T&	operator[](unsigned int i)
    {
      if (i < _rows * _cols)
	return (_m[i]);
      else
	std::cerr << ERR_MATRIX_RANGE << std::endl;
      return (_m[_rows * _cols - 1]);
    }
    const T&	operator()(unsigned int i, unsigned int j) const
    {
      if (RANGE(i, j, _rows, _cols))
	return (_m[i * _cols + j]);
      else
	std::cerr << ERR_MATRIX_RANGE << std::endl;
      return (_m[_cols * _cols - 1]);
    }
    T&	operator()(unsigned int i, unsigned int j)
    {
      if (RANGE(i, j, _rows, _cols))
	return (_m[i * _cols + j]);
      else
	std::cerr << ERR_MATRIX_RANGE << std::endl;
      return (_m[_cols * _cols - 1]);
    }

  private:
    unsigned int	_rows;
    unsigned int	_cols;
    std::vector<T>	_m;
    T			_init;
  };

  /*
  ** Overload.
  */
  template <class T>
  Matrix<T>	operator+(Matrix<T> const& m1, Matrix<T> const& m2)
  {
    Matrix<T>	result;

    if (m1.rows() == m2.rows() && m1.cols() == m2.cols())
      {
	result = Matrix<T>(m1.rows(), m1.cols(), m1.init());
	for (unsigned int i = 0; i < m1.rows() * m1.cols(); i++)
	  result[i] = m1[i] + m2[i];
      }
    else
      std::cerr << ERR_MATRIX_INVOP << std::endl;
    return (result);
  }

  template <class T>
  Matrix<T>	operator-(Matrix<T> const& m1, Matrix<T> const& m2)
  {
    Matrix<T>	result;

    if (m1.rows() == m2.rows() && m1.cols() == m2.cols())
      {
	result = Matrix<T>(m1.rows(), m1.cols(), m1.init());
	for (unsigned int i = 0; i < m1.rows() * m1.cols(); i++)
	  result[i] = m1[i] - m2[i];
      }
    else
      std::cerr << ERR_MATRIX_INVOP << std::endl;
    return (result);
  }

  template <class T>
  Matrix<T>	operator+(Matrix<T> const& m1, T const& s)
  {
    Matrix<T>	result;

    result = Matrix<T>(m1.rows(), m1.cols(), m1.init());
    for (unsigned int i = 0; i < m1.rows() * m1.cols(); i++)
      result[i] = m1[i] + s;
    return (result);
  }

  template <class T>
  Matrix<T>	operator*(Matrix<T> const& m1, T const& s)
  {
    Matrix<T>	result;

    result = Matrix<T>(m1.rows(), m1.cols(), m1.init());
    for (unsigned int i = 0; i < m1.rows() * m1.cols(); i++)
      result[i] = m1[i] * s;
    return (result);
  }

  template <class T>
  Matrix<T>	operator*(Matrix<T> const& m1, Matrix<T> const& m2)
  {
    Matrix<T>	result;

    if (m1.cols() == m2.rows())
      {
	result = Matrix<T>(m1.rows(), m2.cols(), m1.init());
	for (unsigned int i = 0; i < result.rows(); i++)
	  {
	    for (unsigned int j = 0; j < result.cols(); j++)
	      {
		for (unsigned int k = 0; k < m1.cols(); k++)
		  {
		    if (k == 0)
		      result(i, j) = m1(i, k) * m2(k, j);
		    else
		      result(i, j) += m1(i, k) * m2(k, j);
		  }
	      }
	  }
      }
    else
      std::cerr << ERR_MATRIX_INVOP << std::endl;
    return (result);
  }

  template <class T>
  bool	operator==(Matrix<T> const& m1, Matrix<T> const& m2)
  {
    if (m1.cols() == m2.rows())
      {
	for (unsigned int i = 0; i < m1.rows() * m1.cols(); i++)
	  {
	    if (m1[i] != m2[i])
	      return (false);
	  }
	return (true);
      }
    else
      std::cerr << ERR_MATRIX_INVOP << std::endl;
    return (false);
  }

  template <class T>
  bool	operator==(Matrix<T>& m1, Matrix<T>& m2)
  {
    if (m1.cols() == m2.rows())
      {
	for (unsigned int i = 0; i < m1.rows() * m1.cols(); i++)
	  {
	    if (m1[i] != m2[i])
	      return (false);
	  }
	return (true);
      }
    else
      std::cerr << ERR_MATRIX_INVOP << std::endl;
    return (false);
  }

  template <class T>
  std::ostream&	operator<<(std::ostream& flux, Matrix<T> const& m)
  {
    for (unsigned int i = 0; i < m.rows(); i++)
      {
	for (unsigned j = 0; j < m.cols(); j++)
	  flux << m(i, j) << ' ';
	flux << std::endl;
      }
    return (flux);
  }
}

#endif /* !MATRIX_H_ */
