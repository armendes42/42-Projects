/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:34:41 by armendes          #+#    #+#             */
/*   Updated: 2022/09/08 18:22:41 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{

	template <typename T, T v>
	struct integral_constant
	{
  	static const T											value = v;
  	typedef T 													value_type;
  	typedef ft::integral_constant<T,v> 	type;
  	operator T() const { return v; }
	};

	typedef ft::integral_constant<bool, true>     true_type;
	typedef ft::integral_constant<bool, false>    false_type;

	template <class T> struct is_integral : public false_type {};
	template <class T> struct is_integral<const T> : public is_integral<T> {};
	template <class T> struct is_integral<volatile const T> : public is_integral<T> {};
	template <class T> struct is_integral<volatile T> : public is_integral<T> {};

	template<> struct is_integral<unsigned char> : public true_type {};
	template<> struct is_integral<unsigned short> : public true_type {};
	template<> struct is_integral<unsigned int> : public true_type {};
	template<> struct is_integral<unsigned long> : public true_type {};

	template<> struct is_integral<signed char> : public true_type{};
	template<> struct is_integral<short> : public true_type{};
	template<> struct is_integral<int> : public true_type{};
	template<> struct is_integral<long> : public true_type{};

	template<> struct is_integral<char> : public true_type{};
	template<> struct is_integral<bool> : public true_type{};

}

#endif
