/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:34:41 by armendes          #+#    #+#             */
/*   Updated: 2022/11/16 21:30:47 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{

	template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		operator T() { return (v); }
	};

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template <class T> struct is_integral : public false_type {};

	template<> struct is_integral<bool> : public true_type {};
	template<> struct is_integral<char> : public true_type {};
	template<> struct is_integral<signed char> : public true_type {};
	template<> struct is_integral<unsigned char> : public true_type {};
	template<> struct is_integral<wchar_t> : public true_type {};
	template<> struct is_integral<short> : public true_type {};
	template<> struct is_integral<unsigned short> : public true_type {};
	template<> struct is_integral<int> : public true_type {};
	template<> struct is_integral<unsigned int> : public true_type {};
	template<> struct is_integral<long> : public true_type {};
	template<> struct is_integral<long long> : public true_type {};
	template<> struct is_integral<unsigned long> : public true_type {};
	template<> struct is_integral<unsigned long long> : public true_type {};

	template <typename T>
	struct remove_const
	{
		typedef T type;
	};

	template <typename T>
	struct remove_const<const T>
	{
		typedef T type;
	};

	template <typename T>
	struct remove_volatile
	{
		typedef T type;
	};

	template <typename T>
	struct remove_volatile<volatile T>
	{
		typedef T type;
	};

	template <typename T>
	struct remove_cv
	{
		typedef typename remove_volatile<typename remove_const<T>::type>::type type;
	};

	template <typename T, typename U>
	struct is_same : public false_type {};

	template <typename T>
	struct is_same<T, T> : public true_type {};

};

#endif
