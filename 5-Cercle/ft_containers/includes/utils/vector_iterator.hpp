/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:13:56 by armendes          #+#    #+#             */
/*   Updated: 2022/10/24 16:37:48 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{

	template <class Iterator>
	class vector_iterator : public ft::iterator<random_access_iterator_tag, Iterator>
	{
		public:

			typedef typename	ft::iterator<random_access_iterator_tag, Iterator>::iterator_category	iterator_category;
			typedef typename	ft::iterator<random_access_iterator_tag, Iterator>::value_type				value_type;
			typedef typename	ft::iterator<random_access_iterator_tag, Iterator>::difference_type		difference_type;
			typedef typename	ft::iterator<random_access_iterator_tag, Iterator>::pointer					pointer;
			typedef typename	ft::iterator<random_access_iterator_tag, Iterator>::reference			reference;

			vector_iterator(void) : _current(NULL) {}

			vector_iterator(pointer x) : _current(x) {}

			vector_iterator(vector_iterator const &other)
			{
				this->_current = pther._current;
			}

			virtual ~vector_iterator() {}

			operator	vector_iterator<const value_type>(void) const
			{
				return (vector_iterator<const value_type>(this->_current));
			};

			vector_iterator& operator=(const vector_iterator &other)
			{
				if (this == &other)
					return (*this);
				this->_current = other._current;
				return (*this);
			}

			friend bool	operator==(vector_iterator const & lhs, vector_iterator const & rhs)
			{
				if (lhs._element == rhs._element)
					return (true);
				return (false);
			}

			friend bool	operator!=(vector_iterator const & lhs, vector_iterator const & rhs)
			{
				if (lhs._element != rhs._element)
					return (true);
				return (false);
			}

			friend bool	operator<(vector_iterator const & lhs, vector_iterator const & rhs)
			{
				if (lhs._element < rhs._element)
					return (true);
				return (false);
			}

			friend bool	operator>(vector_iterator const & lhs, vector_iterator const & rhs)
			{
				if (lhs._element > rhs._element)
					return (true);
				return (false);
			}

			friend bool	operator<=(vector_iterator const & lhs, vector_iterator const & rhs)
			{
				if (lhs._element <= rhs._element)
					return (true);
				return (false);
			}

			friend bool	operator>=(vector_iterator const & lhs, vector_iterator const & rhs)
			{
				if (lhs._element >= rhs._element)
					return (true);
				return (false);
			}

			vector_iterator	operator++(void)
			{
				++(this->_current);
				return (*this);
			}

			vector_iterator	operator++(int)
			{
				vector_iterator	tmp = (*this);
				++(*this);
				return (tmp);
			}

			vector_iterator&	operator--(void)
			{
				this->_current--;
				return (*this);
			}

			vector_iterator	operator--(int)
			{
				vector_iterator	tmp = (*this);
				--(*this);
				return (tmp);
			}

			vector_iterator	operator+(difference_type const & rhs) const
			{
				return (this->_current + rhs);
			}

			friend vector_iterator	operator+(difference_type n, vector_iterator const &rhs)
			{
				return (rhs._element + n);
			};

			friend difference_type	operator+(vector_iterator const &lhs, vector_iterator const &rhs)
			{
				return (lhs._element + rhs._element);
			};

			vector_iterator	operator+=(difference_type const & rhs)
			{
				return (vector_iterator(this->_current += rhs));
			}

			vector_iterator	operator-( difference_type const & rhs ) const
			{
				return (this->_current - rhs);
			}

			friend vector_iterator	operator-(difference_type n, vector_iterator const &rhs)
			{
				return (rhs._element - n);
			};

			friend difference_type	operator-(vector_iterator const &lhs, vector_iterator const &rhs)
			{
				return (lhs._element - rhs._element);
			};

			vector_iterator	operator-=( difference_type const & rhs )
			{
				return (vector_iterator(this->_current -= rhs));
			}

			difference_type	operator+(vector_iterator x)
			{
				return (this->_current + x._current);
			}

			difference_type	operator-(vector_iterator x)
			{
				return (this->_current - x._current);
			}

			reference operator*(void) const
			{
				return (*(this->_current));
			}

			reference	operator[](difference_type n) const
			{
				return (*(this->_current + n));
			}

			pointer	operator->(void) const
			{
				return (this->_current);
			}

		private:
			pointer			_current;


	};

};

#endif
