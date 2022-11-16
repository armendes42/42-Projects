/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:34:55 by armendes          #+#    #+#             */
/*   Updated: 2022/11/17 00:03:35 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# include TREE_HPP

# include <algorithm>
# include <iterator>
# include <limits>
# include "tree_algo.hpp"
# include "tree_iterator.hpp"

namespace ft
{
    template <typename T, typename Compare, typename Allocator>
    class tree
    {
        public:
            typedef T                                                   value_type;
            typedef Compare                                             value_compare;
            typedef Allocator                                           allocator_type;
            typedef typename allocator_type::size_type                  size_type;
            typedef typename allocator_type::difference_type            difference_type;
            typedef value_type&                                         reference;
            typedef const value_type&                                   const_reference;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;
            typedef tree_iterator<value_type, difference_type>          iterator;
            typedef const_tree_iterator<value_type, difference_type>    const_iterator;

            tree(const value_compare& comp) : _alloc(node_allocator()), _value_alloc(allocator_type()), _comp(comp), _end_node(), _size(0)
            {
                _begin_iter = end_node();
            }

            tree(const tree& other) : _alloc(other._alloc), _value_alloc(other._value_alloc), _comp(other._comp), _end_node(), _size(0)
            {
                _begin_iter = end_node();
                insert(other.begin(), other.end());
            }

            tree(const value_compare& comp, const allocator_type alloc) : _alloc(node_allocator()), _value_alloc(alloc), _comp(comp), _end_node(), _size(0)
            {
                _begin_iter = end_node();
            }

            tree& operator=(const tree& other)
            {
                if (this == &other)
                    return (*this);
                tree tmp(other);
                swap(tmp);
                return (*this);
            }

            ~tree()
            {
                destroy(root());
            }

            allocator_type geet_allocator() const
            {
                return (_value_alloc);
            }

            iterator begin()
            {
                return (iterator(_begin_iter));
            }

            const_iterator begin() const
            {
                return (const_iterator(_begin_iter));
            }

            iterator end()
            {
                return (iterator(end_node()));
            }

            const_iterator end() const
            {
                return (const_iterator(end_node()));
            }

            bool empty() const
            {
                return (size() == size_type(0));
            }

            size_type size() const
            {
                return (_size);
            }

            size_type max_size() const
            {
                return (std::min(_alloc.max_size(), static_cast<size_type>(std::numeric_limits<difference_type>::max())));
            }

            void clear()
            {
                destroy(root());
                _end_node.left = NULL;
                _begin_iter = end_node();
                _size = 0;
            }

            value_compare& value_comp()
            {
                return (_comp);
            }

            const value_compare& value_comp() const
            {
                return (_comp);
            }

            pair<iterator, bool> insert(const value_type& value)
            {
                end_node_pointer parent;
                node_pointer& child = find_pos(parent, value);
                bool inserted = false;
                iterator it(child);
                if (child == NULL)
                {
                    it = insert_at(child, parent, value);
                    inserted = true;
                }
                return (ft::make_pair(it, inserted));
            }

            iterator insert(const_iterator hint, const value_type& value)
            {
                end_node_pointer parent;
                node_pointer dummy;
                node_pointer& child = find_pos(hint.base(), parent, value, dummy);
                iterator it(child);
                if (child == NULL)
                    it = insert_at(child, parent, value);
                return (it);
            }

            template <typename InputIt>
            void insert(InputIt first, InputIt last)
            {
                for (; first != last, ++first)
                    insert(*first);
            }

            iterator erase(const_iterator pos)
            {
                const_iterator next(pos);
                ++next;
                if (_begin_iter == pos.base())
                    _begin_iter = next.base();
                node_pointer ptr = pos.node_ptr();
                tree_remove_node(end_node()->left, ptr);
                delete_node(ptr);
                _size--;
                return (iterator(next.base()));
            }




        private:
            typedef typename tree_node_types<value_type>::end_note_type         end_note_type;
            typedef typename tree_node_types<value_type>::node_type             node_type;
            typedef typename tree_node_types<value_type>::end_note_pointer      end_node_pointer;
            typedef typename tree_node_types<value_type>::node_pointer          node_pointer;
            typedef typename allocator_type::template rebind<node_type>::other  node_allocator;

            node_allocator      _alloc;
            allocator_type      _value_alloc;
            value_compare       _comp;
            end_note_type       _end_node;
            end_node_pointer    _begin_iter;
            size_type           _size;
    };
}

#endif