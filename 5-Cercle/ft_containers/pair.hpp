/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:10:42 by armendes          #+#    #+#             */
/*   Updated: 2022/09/08 19:36:03 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		T1					first;
		T2					second;

		pair() : first(), second() { };
		pair(const first_type& a, const second_type& b) : first(a), second(b) { };
		template <class U, class V>
		pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) { };

		pair& operator= (const pair& pr)
		{
			if (*this == pr)
				return *this;
			first = pr.first;
			second = pr.second;
			return *this;
		};

	};

	template <class T1, class T2>
  pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	};

	template <class T1, class T2>
  bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
  bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first != rhs.first && lhs.second != rhs.second);
	};

	template <class T1, class T2>
  bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first && lhs.second < rhs.second);
	};

	template <class T1, class T2>
  bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first <= rhs.first && lhs.second <= rhs.second);
	};

	template <class T1, class T2>
  bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first > rhs.first && lhs.second > rhs.second);
	};

	template <class T1, class T2>
  bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first >= rhs.first && lhs.second >= rhs.second);
	};

}

#endif
