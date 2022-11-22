/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:51:59 by armendes          #+#    #+#             */
/*   Updated: 2022/11/22 16:20:29 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <typename T, typename Container = vector<T> >
	class stack
	{
		public:
		    typedef Container                                container_type;
		    typedef typename container_type::value_type      value_type;
		    typedef typename container_type::size_type       size_type;
		    typedef typename container_type::reference       reference;
		    typedef typename container_type::const_reference const_reference;

		public:
		    explicit stack(const container_type& cont = container_type()) : _c(cont) { }

		    stack(const stack& other) : _c(other._c) { }

		    stack& operator=(const stack& other)
		    {
		        _c = other._c;
		        return *this;
		    }

		    ~stack() { }

		public:
		    reference top()
		    {
		        return _c.back();
		    }

		    const_reference top() const
		    {
		        return _c.back();
		    }

		    bool empty() const
		    {
		        return _c.empty();
		    }

		    size_type size() const
		    {
		        return _c.size();
		    }

		    void push(const value_type& value)
		    {
		        _c.push_back(value);
		    }

		    void pop()
		    {
		        _c.pop_back();
		    }

		    template <typename T1, typename C1>
		    friend bool operator==(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

		    template <typename T1, typename C1>
		    friend bool operator<(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

		protected:
		    container_type _c;
	};

	template <typename T, typename Container>
	inline bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
	    return lhs._c == rhs._c;
	}

	template <typename T, typename Container>
	inline bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
	    return !(lhs == rhs);
	}

	template <typename T, typename Container>
	inline bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
	    return lhs._c < rhs._c;
	}

	template <typename T, typename Container>
	inline bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
	    return !(rhs < lhs);
	}

	template <typename T, typename Container>
	inline bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
	    return rhs < lhs;
	}

	template <typename T, typename Container>
	inline bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
	{
	    return !(lhs < rhs);
	}
}

#endif
