/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:13:56 by armendes          #+#    #+#             */
/*   Updated: 2022/11/16 21:32:33 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft
{

	template <typename It, typename Container>
	class vector_iterator
	{
		public:

			typedef It													iterator_type;
			typedef typename	iterator_traits<It>::iterator_category	iterator_category;
			typedef typename	iterator_traits<It>::value_type			value_type;
			typedef typename	iterator_traits<It>::difference_type	difference_type;
			typedef typename	iterator_traits<It>::pointer			pointer;
			typedef typename	iterator_traits<It>::reference			reference;

			vector_iterator() : _elem(iterator_type()) { }

			explicit vector_iterator(const iterator_type& it) : _elem(it) { }

			template <typename Iter>
			vector_iterator(const vector_iterator<It, typename enable_if<is_same<Iter, typename Container::pointer>::value, Container>::type>& it) : _elem(it.base()) { }

			~vector_iterator() { }

			vector_iterator& operator=(const vector_iterator& other)
			{
				if (&other == this)
					return (*this);
				_elem = other._elem;
				return (*this);
			}

			const iterator_type& base() const
			{
				return (_elem);
			}

			reference operator*() const
			{
				return (*_elem);
			}

			pointer operator->() const
			{
				return (_elem);
			}

			vector_iterator& operator++()
			{
				++_elem;
				return (*this);
			}

			vector_iterator operator++(int)
			{
				return (vector_iterator(_elem++));
			}

			vector_iterator& operator--()
			{
				--_elem;
				return (*this);
			}

			vector_iterator operator--(int)
			{
				return (vector_iterator(_elem--));
			}

			reference operator[](difference_type n)
			{
				return (*(_elem + n));
			}

			vector_iterator& operator+=(difference_type n)
			{
				_elem += n;
				return (*this);
			}

			vector_iterator operator+(difference_type n) const
			{
				return (vector_iterator(_elem + n));
			}

			vector_iterator& operator-=(difference_type n)
			{
				_elem -= n;
				return (*this);
			}

			vector_iterator operator-(difference_type n) const
			{
				return (vector_iterator(_elem - n));
			}		

		protected:
			It	_elem;

	};

	template <typename ItL, typename ItR, typename Container>
	inline bool operator==(const vector_iterator<ItL, Container>& lhs,
						const vector_iterator<ItR, Container>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename It, typename Container>
	inline bool operator==(const vector_iterator<It, Container>& lhs,
						const vector_iterator<It, Container>& rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename ItL, typename ItR, typename Container>
	inline bool operator!=(const vector_iterator<ItL, Container>& lhs,
						const vector_iterator<ItR, Container>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename It, typename Container>
	inline bool operator!=(const vector_iterator<It, Container>& lhs,
						const vector_iterator<It, Container>& rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename ItL, typename ItR, typename Container>
	inline bool operator>(const vector_iterator<ItL, Container>& lhs,
						const vector_iterator<ItR, Container>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename It, typename Container>
	inline bool operator>(const vector_iterator<It, Container>& lhs,
						const vector_iterator<It, Container>& rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename ItL, typename ItR, typename Container>
	inline bool operator<(const vector_iterator<ItL, Container>& lhs,
						const vector_iterator<ItR, Container>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename It, typename Container>
	inline bool operator<(const vector_iterator<It, Container>& lhs,
						const vector_iterator<It, Container>& rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename ItL, typename ItR, typename Container>
	inline bool operator>=(const vector_iterator<ItL, Container>& lhs,
						const vector_iterator<ItR, Container>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename It, typename Container>
	inline bool operator>=(const vector_iterator<It, Container>& lhs,
						const vector_iterator<It, Container>& rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename ItL, typename ItR, typename Container>
	inline bool operator<=(const vector_iterator<ItL, Container>& lhs,
						const vector_iterator<ItR, Container>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename It, typename Container>
	inline bool operator<=(const vector_iterator<It, Container>& lhs,
						const vector_iterator<It, Container>& rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename ItL, typename ItR, typename Container>
	inline typename vector_iterator<ItL, Container>::difference_type
	operator-(const vector_iterator<ItL, Container>& lhs, const vector_iterator<ItR, Container>& rhs)
	{
		return lhs.base() - rhs.base();
	}

	template <typename It, typename Container>
	inline typename vector_iterator<It, Container>::difference_type
	operator-(const vector_iterator<It, Container>& lhs, const vector_iterator<It, Container>& rhs)
	{
		return lhs.base() - rhs.base();
	}

	template <typename It, typename Container>
	inline vector_iterator<It, Container>
	operator+(typename vector_iterator<It, Container>::difference_type n,
			const vector_iterator<It, Container>& it)
	{
		return vector_iterator<It, Container>(it.base() + n);
	}

	template <class InputIt>
	typename iterator_traits<InputIt>::difference_type difference(InputIt start, InputIt end)
    {
		typename iterator_traits<InputIt>::difference_type len = 0;

		while (start != end)
        {
			len++;
			++start;
		}
		return (len);
	}

};

#endif
