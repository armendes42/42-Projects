/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:37:17 by armendes          #+#    #+#             */
/*   Updated: 2022/11/22 16:47:25 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR_HPP
# define TREE_ITERATOR_HPP

# include <iterator>
# include "tree_algo.hpp"
# include "tree_types.hpp"

namespace ft
{
	template <typename T, typename DiffType>
	class const_tree_iterator;

	template <typename T, typename DiffType>
	class tree_iterator
	{
		public:
		    typedef std::bidirectional_iterator_tag  iterator_category;
		    typedef T                                value_type;
		    typedef T&                               reference;
		    typedef T*                               pointer;
		    typedef DiffType                         difference_type;
		    typedef const_tree_iterator<T, DiffType> const_iterator;

		private:
		    typedef typename tree_node_types<T>::end_node_pointer  end_node_pointer;
		    typedef typename tree_node_types<T>::node_pointer      node_pointer;

		public:
		    tree_iterator() : _ptr(NULL) { }

		    tree_iterator(end_node_pointer p) : _ptr(p) { }

		    tree_iterator(node_pointer p) : _ptr(static_cast<end_node_pointer>(p)) { }

		public:
		    end_node_pointer& base()
		    {
		        return (_ptr);
		    }

		    const end_node_pointer& base() const
		    {
		        return (_ptr);
		    }

		    node_pointer node_ptr() const
		    {
		        return (static_cast<node_pointer>(_ptr));
		    }

		    reference operator*() const
		    {
		        return (static_cast<node_pointer>(_ptr)->value);
		    }

		    pointer operator->() const
		    {
		        return (&(operator*()));
		    }

		    tree_iterator& operator++()
		    {
		        _ptr = tree_iter_next<end_node_pointer>(static_cast<node_pointer>(_ptr));
		        return (*this);
		    }

		    tree_iterator operator++(int)
		    {
		        tree_iterator t = *this;
		        ++(*this);
		        return (t);
		    }

		    tree_iterator& operator--()
		    {
		        _ptr = tree_iter_prev<node_pointer>(_ptr);
		        return (*this);
		    }

		    tree_iterator operator--(int)
		    {
		        tree_iterator t = *this;
		        --(*this);
		        return (t);
		    }

		    bool operator==(const tree_iterator& other) const
		    {
		        return (_ptr == other._ptr);
		    }

		    bool operator==(const const_iterator& other) const
		    {
		        return (_ptr == other.base());
		    }

		    bool operator!=(const tree_iterator& other) const
		    {
		        return (!(*this == other));
		    }

		    bool operator!=(const const_iterator& other) const
		    {
		        return (!(*this == other));
		    }

		private:
		    end_node_pointer _ptr;
	};

	template <typename T, typename DiffType>
	class const_tree_iterator
	{
		public:
		    typedef std::bidirectional_iterator_tag iterator_category;
		    typedef T                               value_type;
		    typedef const T&                        reference;
		    typedef const T*                        pointer;
		    typedef DiffType                        difference_type;
		    typedef tree_iterator<T, DiffType>      non_const_iterator;

		private:
		    typedef typename tree_node_types<T>::end_node_pointer  end_node_pointer;
		    typedef typename tree_node_types<T>::node_pointer      node_pointer;

		public:
		    const_tree_iterator() : _ptr(NULL) { }

		    const_tree_iterator(end_node_pointer p) : _ptr(p) { }

		    const_tree_iterator(node_pointer p) : _ptr(static_cast<end_node_pointer>(p)) { }

		    const_tree_iterator(non_const_iterator it) : _ptr(it.base()) { }

		public:
		    end_node_pointer& base()
		    {
		        return (_ptr);
		    }

		    const end_node_pointer& base() const
		    {
		        return (_ptr);
		    }

		    node_pointer node_ptr() const
		    {
		        return (static_cast<node_pointer>(_ptr));
		    }

		    reference operator*() const
		    {
		        return (static_cast<node_pointer>(_ptr)->value);
		    }

		    pointer operator->() const
		    {
		        return (&(operator*()));
		    }

		    const_tree_iterator& operator++()
		    {
		        _ptr = tree_iter_next<end_node_pointer>(static_cast<node_pointer>(_ptr));
		        return (*this);
		    }

		    const_tree_iterator operator++(int)
		    {
		        const_tree_iterator t = *this;
		        ++(*this);
		        return (t);
		    }

		    const_tree_iterator& operator--()
		    {
		        _ptr = tree_iter_prev<node_pointer>(_ptr);
		        return (*this);
		    }

		    const_tree_iterator operator--(int)
		    {
		        const_tree_iterator t = *this;
		        --(*this);
		        return (t);
		    }

		    bool operator==(const const_tree_iterator& other) const
		    {
		        return (_ptr == other._ptr);
		    }

		    bool operator==(const non_const_iterator& other) const
		    {
		        return (_ptr == other.base());
		    }

		    bool operator!=(const const_tree_iterator& other) const
		    {
		        return (!(*this == other));
		    }

		    bool operator!=(const non_const_iterator& other) const
		    {
		        return (!(*this == other));
		    }

		private:
		    end_node_pointer _ptr;
	};

}

#endif
