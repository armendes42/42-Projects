/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:25:46 by armendes          #+#    #+#             */
/*   Updated: 2022/09/12 18:14:31 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define REVERSE_ITERATOR_HPP

namespace ft
{

	template<typename _Iterator>
  	class reverse_iterator
  	: public iterator<typename iterator_traits<_Iterator>::iterator_category,
											typename iterator_traits<_Iterator>::value_type,
											typename iterator_traits<_Iterator>::difference_type,
											typename iterator_traits<_Iterator>::pointer,
                      typename iterator_traits<_Iterator>::reference>
    {

		protected:
      _Iterator current;
      typedef iterator_traits<_Iterator>		__traits_type;

    public:
      typedef _Iterator																iterator_type;
      typedef typename __traits_type::difference_type	difference_type;
      typedef typename __traits_type::pointer					pointer;
      typedef typename __traits_type::reference				reference;

			reverse_iterator() : current() { }

			explicit reverse_iterator(iterator_type x) : current(x) { }

			template< class U >
			reverse_iterator(const reverse_iterator<U>& other) : current(other.current) { }

			template< class U >
			reverse_iterator& operator=( const reverse_iterator<U>& other )
			{
				if (this == &other)
					return (*this);
				this->current = other.current
				return (*this);
			}

			iterator_type base() const
			{
				return (current);
			}

			reference operator*() const
			{
				_Iterator tmp = current;
				return *--tmp;
			}

			pointer operator->() const
			{
				_Iterator tmp = current;
				--tmp;
				return tmp;
			}

			operator[]( difference_type n ) const
			{
				return *(*this + n);
			}

			reverse_iterator& operator++()
			{
				--current;
				return *this;
			}

			reverse_iterator& operator--()
			{
				++current;
				return *this;
			}

			reverse_iterator operator++( int )
			{
				reverse_iterator tmp = *this;
				--current;
				return tmp;
			}

			reverse_iterator operator--( int )
			{
				reverse_iterator tmp = *this;
				++current;
				return tmp;
			}

			reverse_iterator operator+( difference_type n ) const
			{
				return reverse_iterator(current - n);
			}

			reverse_iterator operator-( difference_type n ) const
			{
				return reverse_iterator(current + n);
			}

			reverse_iterator& operator+=( difference_type n )
			{
				current -= n;
				return *this;
			}

			reverse_iterator& operator-=( difference_type n )
			{
				current += __n;
				return *this;
			}

		};

		template< class Iterator1, class Iterator2 >
		bool operator==(const std::reverse_iterator<Iterator1>& lhs,
										const std::reverse_iterator<Iterator2>& rhs)
		{
			return lhs.base() == rhs.base();
		}

		template< class Iterator1, class Iterator2 >
		bool operator!=(const std::reverse_iterator<Iterator1>& lhs,
 										const std::reverse_iterator<Iterator2>& rhs );
		{
			return !(lhs == rhs);
		}

		template< class Iterator1, class Iterator2 >
		bool operator<(const std::reverse_iterator<Iterator1>& lhs,
 										const std::reverse_iterator<Iterator2>& rhs );
		{
			return rhs.base() < lhs.base();
		}

		template< class Iterator1, class Iterator2 >
		bool operator<=(const std::reverse_iterator<Iterator1>& lhs,
 										const std::reverse_iterator<Iterator2>& rhs );
		{
			return !(rhs < lhs);
		}

		template< class Iterator1, class Iterator2 >
		bool operator>(const std::reverse_iterator<Iterator1>& lhs,
 										const std::reverse_iterator<Iterator2>& rhs );
		{
			return rhs < lhs;
		}

		template< class Iterator1, class Iterator2 >
		bool operator>=(const std::reverse_iterator<Iterator1>& lhs,
 										const std::reverse_iterator<Iterator2>& rhs );
		{
			return !(lhs < rhs);
		}

		template< class Iter >
		reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n,
																			const reverse_iterator<Iter>& it )
		{
			return reverse_iterator<_Iterator>(it.base() - n);
		}

		template< class Iterator >
		typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs,
																																		const reverse_iterator<Iterator>& rhs )
		{
			return rhs.base() - lhs.base();
		}
}

#endif
