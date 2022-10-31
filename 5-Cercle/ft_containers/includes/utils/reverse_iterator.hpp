/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:25:46 by armendes          #+#    #+#             */
/*   Updated: 2022/10/31 21:50:19 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{

	template <typename Iterator>
  	class reverse_iterator : public iterator<typename iterator_traits<Iterator>::value_type,
											typename iterator_traits<Iterator>::difference_type,
											typename iterator_traits<Iterator>::pointer,
											typename iterator_traits<Iterator>::reference>
    {

		private:
			Iterator							_current;
			typedef	iterator_traits<Iterator>	traits_type;

    	public:
			typedef Iterator								iterator_type;
			typedef typename traits_type::difference_type	difference_type;
			typedef typename traits_type::pointer			pointer;
			typedef typename traits_type::reference			reference;

			reverse_iterator() : _current() { }

			explicit reverse_iterator(iterator_type x) : _current(x) { }

			reverse_iterator(reverse_iterator const & other) : _current(other._current) { }

			template <typename InputIterator>
			reverse_iterator(reverse_iterator<InputIterator> const & other) : _current(other.base()) { }

			iterator_type base() const
			{
				return (_current);
			}

			reference operator*() const
			{
				Iterator tmp = _current;
				return (*(--tmp));
			}

			pointer operator->() const
			{
				return (&(operator*()));
			}

			reverse_iterator& operator++(void)
			{
				--_current;
				return (*this);
			}

			reverse_iterator operator++( int )
			{
				reverse_iterator tmp = (*this);
				--_current;
				return (tmp);
			}

			reverse_iterator& operator--(void)
			{
				++_current;
				return (*this);
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = (*this);
				++_current;
				return (tmp);
			}

			reverse_iterator operator+(difference_type n) const
			{
				return reverse_iterator(_current - n);
			}

			reverse_iterator& operator+=(difference_type n)
			{
				_current -= n;
				return (*this);
			}

			reverse_iterator operator-(difference_type n) const
			{
				return reverse_iterator(_current + n);
			}

			reverse_iterator& operator-=(difference_type n)
			{
				_current += n;
				return (*this);
			}

			reference operator[](difference_type n) const
			{
				return (*(*this + n));
			}

	};

	template<typename InputIterator>
	bool	operator==(const reverse_iterator<InputIterator>& x, const reverse_iterator<InputIterator>& y) {

		return (x.base() == y.base());
	}

	template<typename InputIterator>
	bool	operator<(const reverse_iterator<InputIterator>& x, const reverse_iterator<InputIterator>& y) {

		return (y.base() < x.base());
	}

	template<typename InputIterator>
	bool	operator!=(const reverse_iterator<InputIterator>& x, const reverse_iterator<InputIterator>& y) {

		return !(x == y);
	}

	template<typename InputIterator>
	bool	operator>(const reverse_iterator<InputIterator>& x, const reverse_iterator<InputIterator>& y) {

		return (y < x);
	}

	template<typename InputIterator>
	bool	operator<=(const reverse_iterator<InputIterator>& x, const reverse_iterator<InputIterator>& y) {

		return (!(y < x));
	}

	template<typename InputIterator>
	bool	operator>=(const reverse_iterator<InputIterator>& x, const reverse_iterator<InputIterator>& y) {

		return (!(x < y));
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator==(const reverse_iterator<InputIteratorL>& x, const reverse_iterator<InputIteratorR>& y) {

		return (x.base() == y.base());
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator<(const reverse_iterator<InputIteratorL>& x, const reverse_iterator<InputIteratorR>& y) {

		return (y.base() < x.base());
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator!=(const reverse_iterator<InputIteratorL>& x, const reverse_iterator<InputIteratorR>& y) {

		return (!(x == y));
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator>(const reverse_iterator<InputIteratorL>& x, const reverse_iterator<InputIteratorR>& y) {

		return (y < x);
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator<=(const reverse_iterator<InputIteratorL>& x, const reverse_iterator<InputIteratorR>& y) {

		return (!(y < x));
	}

	template<typename InputIteratorL, typename InputIteratorR>
	bool	operator>=(const reverse_iterator<InputIteratorL>& x, const reverse_iterator<InputIteratorR>& y) {

		return (!(x < y));
	}

	template<typename InputIterator>
	typename reverse_iterator<InputIterator>::difference_type	operator-(const reverse_iterator<InputIterator>& x,
		const reverse_iterator<InputIterator>& y) {

		return (y.base() - x.base());
	}

	template<typename InputIteratorL, typename InputIteratorR>
	typename reverse_iterator<InputIteratorL>::difference_type	operator-(const reverse_iterator<InputIteratorL>& x,
		const reverse_iterator<InputIteratorR>& y) {

		return (y.base() - x.base());
	}

	template<typename Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& x) {

		return (reverse_iterator<Iterator>(x.base() - n));
	}

};

#endif
