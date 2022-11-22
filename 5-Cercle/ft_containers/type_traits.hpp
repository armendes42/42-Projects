/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:59:12 by armendes          #+#    #+#             */
/*   Updated: 2022/11/22 16:37:26 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{

	template <bool B, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T>
	{
	    typedef T type;
	};

	template <typename T, T v>
	struct integral_constant
	{
	    static const bool value = v;
	    typedef T value_type;
	    typedef integral_constant type;

	    operator value_type() const
	    {
	        return (value);
	    }

	    value_type operator()() const
	    {
	        return (value);
	    }
	};

	template <bool V>
	struct bool_constant : public integral_constant<bool, V> {};

	struct true_type : public bool_constant<true> {};

	struct false_type : public bool_constant<false> {};

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

	template <typename>
	struct is_integral_base : public false_type {};

	template <>
	struct is_integral_base<bool> : public true_type {};

	template <>
	struct is_integral_base<char> : public true_type {};

	template <>
	struct is_integral_base<signed char> : public true_type {};

	template <>
	struct is_integral_base<short int> : public true_type {};

	template <>
	struct is_integral_base<int> : public true_type {};

	template <>
	struct is_integral_base<long int> : public true_type {};

	template <>
	struct is_integral_base<unsigned char> : public true_type {};

	template <>
	struct is_integral_base<unsigned short int> : public true_type {};

	template <>
	struct is_integral_base<unsigned int> : public true_type {};

	template <>
	struct is_integral_base<unsigned long int> : public true_type {};

	template <typename T>
	struct is_integral : is_integral_base<typename remove_cv<T>::type> {};

	template <typename T, typename U>
	struct is_same : public false_type {};

	template <typename T>
	struct is_same<T, T> : public true_type {};

}

#endif
