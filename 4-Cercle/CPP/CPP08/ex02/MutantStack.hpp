/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:33:09 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 19:50:00 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>{

public:
	MutantStack(void);
	MutantStack(MutantStack const &A);
	virtual ~MutantStack(void);
	MutantStack<T> &operator=(MutantStack const &A);

  typedef typename std::stack<T>::container_type::iterator iterator;

  iterator begin(void) { return this->c.begin(); }
  iterator end(void) { return this->c.end(); }

};

template <typename T>
MutantStack<T>::MutantStack(void)
{
  return;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &A) : std::stack<T>(A)
{
  return;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
  return;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &A)
{
  if (this == &A)
    return (*this);
  std::stack<T>::operator=(A);
  return (*this);
}

#endif
