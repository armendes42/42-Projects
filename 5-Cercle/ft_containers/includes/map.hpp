/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:42:22 by armendes          #+#    #+#             */
/*   Updated: 2022/10/31 21:44:18 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <limits>
# include "equal.hpp"
# include "lexicographical_compare.hpp"
# include "red_black_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::mapNode<ft::pair<const Key, T> > > >
    class map
    {
        public:
            typedef Key                                                 key_type;
            typedef T                                                   mapped_type;
            typedef ft::pair<const key_type, mapped_type>               value_type;
            typedef Compare                                             key_compare;
            typedef Alloc                                               allocator_type;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;
            typedef ft::mapNode<value_type>                             node_type;
            typedef node_type                                           *node_ptr;
            typedef ft::red_black_iterator<value_type, node_type>       iterator;
            typedef ft::red_black_iterator<const value_type, node_type> const_iterator;
            typedef ft::reverse_iterator<iterator>                      reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                const_reverse_iterator;
            typedef std::ptrdiff_t                                      difference_type;
            typedef size_t                                              size_type;

            class value_compare : public std::binary_function<value_type, value_type, bool>
            {
                public:
                    Compare     comp;

                    value_compare(Compare c = key_compare()) : comp(c) {}

                    bool operator()(const value_type &x, const value_type &y) const
                    {
                        return (comp(x.first, y.first));
                    }
            };

            explicit map(key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type())
            {
                this->_sentinal = allocator_type().allocate(1);
                allocator_type().construct(this->_sentinal, node_type(NONE, NULL, NULL, NULL));
                this->_root = this->_sentinal;
                this->_keyCompare = comp;
                this->_alloc = alloc;
                this->_size = 0;
            }

            template <class Iterator>
            map(Iterator first, Iterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
            {
                this->_sentinal = allocator_type().allocate(1);
                allocator_type().construct(this->_sentinal, node_type(NONE, NULL, NULL, NULL));
                this->_root = this->_sentinal;
                this->_keyCompare = comp;
                this->_alloc = alloc;
                this->_size = 0;
                this->_insert(first, last);
            }

            map(map const &src)
            {
                this->_sentinal = allocator_type().allocate(1);
                allocator_type().construct(this->_sentinal, node_type(NONE, NULL, NULL, NULL));
                this->_root = this->_sentinal;
                this->_keyCompare = src._keyCompare;
                this->_alloc = src._alloc;
                this->_size = 0;
                this->_insert(src.begin(), src.end());
            }

            ~map(void)
            {
                this->clear();
                allocator_type().destroy(this->_sentinal);
                allocator_type().deallocate(this->_sentinal, 1);
            }

            map& operator=(const map &other)
            {
                this->clear();
                _insertIterator(other.begin(), other.end());
                return (*this);
            }

            iterator begin()
            {
                return (iterator(lastLeft(this->_root), this->_sentinal));
            }

            const_iterator begin() const
            {
                return (const_iterator(lastLeft(this->_root), this->_sentinal));
            }

            iterator end()
            {
                return (iterator(this->_sentinal, this->_sentinal));
            }

            const_iterator end() const
            {
                return (const_iterator(this->_sentinal, this->sentinal));
            }

            reverse_iterator rbegin()
            {
                return (reverse_iterator(iterator(this->_sentinal, this->_sentinal)));
            }

            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(const_iterator(tihs->_sentinal, tihs->_sentinal)));
            }

            reverse_iterator rend()
            {
                return (reverse_iterator(iterator(lastLeft(this->_root), this->_sentinal)));
            }

            const_reverse_iterator rend() const
            {
                return (const_reverse_iterator(const_iterator(lastLeft(this->_root), this->_sentinal)));
            }

            bool empty() const
            {
                if (this->_size == 0)
                    return (true);
                return (false);
            }

            size_type size() const
            {
                return (this->_size);
            }

            size_type max_size() const
            {
                return (std::numeric_limits<difference_type>::max() / (sizeof(node_type)));
            }

            mapped_type& operator[](const key_type &k)
            {
                return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
            }

            ft::pair<iterator, bool> insert(const value_type &val)
            {
                if (this->_mapInsertUnique(val) == false)
                    return (ft::make_pair(find(val.first), false));
                return (ft::make_pair(find(val.first), true));
            }

            iterator insert(iterator position, const value_type &val)
            {
                (void)position;
                return (insert(val).first);
            }

            template <class Iterator>
            void insert(Iterator first, Iterator last)
            {
                while (first != last)
                {
                    insert(*first);
                    first++;
                }
            }

            void erase(iterator position)
            {
                this->erase(position->first);
            }

            size_type erase(const key_type &k)
            {
                if (this->_redBlackTreeEraseAndRebalance(ft::make_pair(k, mapped_type())) == true)
                    return (1);
                return (0);
            }

            void erase(iterator first, iterator last)
            {
                while (first != last)
                {
                    first = find(first->first);
                    erase(first++);
                }
            }

            void swap(map &x)
            {
                map tmp;
                tmp._swapContent(x);
                x._swapContent(*this);
                this->_swapContent(tmp);
            }

            void clear()
            {
                if (this->_root != NULL)
                    this->_destroyNode(this->_root);
                this->_root = this->_sentinal;
                this->_size = 0;
            }

            key_compare key_comp() const
            {
                return (key_compare());
            }

            value_compare value_comp() const
            {
                return (value_compare(key_compare()));
            }

            iterator find(const key_type &k)
            {
                iterator itEnd = this->end();
                for (iterator itBegin = this->begin(); itBegin != itEnd; itBegin++)
                {
                    if (!this->_keyCompare(itBegin->first, k) && !this->_keyCompare(k, itBegin->first))
                        return (itBegin);
                }
                return (itEnd);
            }

            const_iterator find(const key_type &k) const
            {
                const iterator itEnd = this->end();
                for (const_iterator itBegin = this->begin(); itBegin != itEnd; itBegin++)
                {
                    if (!this->_keyCompare(itBegin->first, k) && !this->_keyCompare(k, itBegin->first))
                        return (itBegin);
                }
                return (itEnd);
            }

            size_type count(const key_type &k) const
            {
                return (this->find(k) != this->end() ? 1 : 0);
            }

            iterator lower_bound(const key_type &k)
            {
                iterator itEnd = this->end();
                for (iterator itBegin = this->begin(); itBegin != itEnd; itBegin++)
                {
                    if (!this->_keyCompare(itBegin->first, k))
                        return (itBegin);
                }
                return (itEnd);
            }

            const_iterator lower_bound(const key_type &k) const
            {
                const_iterator itEnd = this->end();
                for (const_iterator itBegin = this->begin(); itBegin != itEnd; itBegin++)
                {
                    if (!this->_keyCompare(itBegin->first, k))
                        return (itBegin);
                }
                return (itEnd);
            }

            iterator upper_bound(const key_type &k)
            {
                iterator itEnd = this->end();
                for (iterator itBegin = this->begin(); itBegin != itEnd; itBegin++)
                {
                    if (this->_keyCompare(k, itBegin->first))
                        return (itBegin);
                }
                return (itEnd);
            }

            const_iterator upper_bound(const key_type &k) const
            {
                const_iterator itEnd = this->end();
                for (const_iterator itBegin = this->begin(); itBegin != itEnd; itBegin++)
                {
                    if (this->_keyCompare(k, itBegin->first))
                        return (itBegin);
                }
                return (itEnd);
            }

            pair<iterator, iterator> equal_range(const key &k)
            {
                ft::pair<iterator, iterator> ret;
                ret.first = this->lower_bound(k);
                ret.second = this->upper_bound(k);
                return (ret);
            }

            pair<const_iterator, const_iterator> equal_range(const key &k) const
            {
                ft::pair<const_iterator, const_iterator> ret;
                ret.first = this->lower_bound(k);
                ret.second = this->upper_bound(k);
                return (ret);
            }

            allocator_type get_allocator() const
            {
                return (this->_alloc);
            }

        private:
            node_ptr        _root;
            node_ptr        _sentinal;
            allocator_type  _alloc;
            key_compare     _keyCompare;
            size_type       _size;

            template <class Iterator>
            void _insertIterator(Iterator first, Iterator last)
            {
                this->insert(first, last);
            }

            void _leftRotate(node_ptr node)
            {
                node_ptr tmp = node->_right;

                node->_right = tmp->_left;
                if (tmp->_left != this->_sentinal)
                    tmp->_left->_parent = node;
                tmp->_parent = node->_parent;
                if (node->_parent == this->_sentinal)
                    this->_root = tmp;
                else if (node == node->_parent->_left)
                    node->_parent->_left = tmp;
                else
                    node->_parent->_right = tmp;
                tmp->_left = node;
                node->_parent = tmp;
            }

            void _rightRotate(node_ptr node)
            {
                node_ptr tmp = node->_left;

                node->_left = tmp->_right;
                if (tmp->_right != this->_sentinal)
                    tmp->_right->_parent = node;
                tmp->_parent = node->_parent;
                if (node->_parent == this->_sentinal)
                    this->_root = tmp;
                else if (node == node->_parent->_right)
                    node->_aprent->_right = tmp;
                else
                    node->_parent->_left = tmp;
                tmp->_right = node;
                node->_parent = tmp;
            }
            
            bool _mapInsertUnique(const value_type &val)
            {
                node_ptr toInsert = allocator_type().allocate(1);
                allocator_type().construct(toInsert, node_type(val, RED, NULL, NULL, NULL));
                toInsert->_parent = this->_sentinal;
                toInsert->_left = this->_sentinal;
                toInsert->_right = this->_sentinal;
                value_compare comp;
                node_ptr current = NULL;
                node_ptr root = this->_root;

                this->_size++;
                if (this->_root == this->_sentinal)
                {
                    this->_root = toInsert;
                    this->_sentinal->_parent = this->_root;
                    this->_root->_color = BLACK;
                    return (true);
                }
                while (root != this->_sentinal)
                {
                    current = root;
                    if (comp(toInsert->_value, root->_value))
                        root = root->_left;
                    else if (comp(root->_value, toInsert->_value))
                        root = root->_right;
                    else
                    {
                        this->_size--;
                        allocator_type().destroy(toInsert);
                        allocator_type().deallocate(toInsert, 1);
                        return (false);
                    }
                }
                toInsert->_parent = current;
                if (current == NULL)
                    this->_root = toInsert;
                else if (comp(toInsert->_value, current->_value))
                    current->_left = toInsert;
                else if (comp(current->_value, toInsert->_value))
                    current->_right = toInsert;
                if (toInsert->_parent == this->_sentinal)
                {
                    toInsert->_color = BLACK;
                    return (true);
                }
                if (toInsert->_parent->_parent == this->_sentinal)
                    return (true);
                _redBlackTreeInsertAndRebalance(toInsert);
                return (true);
            }

            void _redBlackTreeInsertAndRebalance(node_ptr toFix)
            {
                node_ptr tmp;

                while (toFix->_parent->_color == RED)
                {
                    if (toFix->_parent == toFix->_parent->_parent->_right)
                    {
                        tmp = toFix->_parent->_parent->_left;
                        if (tmp != this->_sentinal && tmp->_color == RED)
                        {
                            tmp->_color == BLACK;
                            toFix->_parent->_color = BLACK;
                            toFix->_parent->_parent->_color = RED;
                            toFix = toFix->_parent->_parent;
                        }
                        else
                        {
                            if (toFix == toFix->_parent->_left)
                            {
                                toFix = toFix->_parent;
                                _rightRotate(toFix);
                            }
                            toFix->_parent->_color = BLACK;
                            toFix->_parent->_parent->_color = RED;
                            _leftRotate(toFix->_parent->_parent);
                        }
                    }
                    else
                    {
                        tmp = toFix->_parent->_parent->_right;
                        if (tmp != this->_sentinal && tmp->_color == RED)
                        {
                            tmp->_color = BLACK;
                            toFix->_parent->_color = BLACK;
                            toFix->_parent->_parent->_color = RED;
                            toFix = toFix->_parent->_parent;
                        }
                        else
                        {
                            if (toFix == toFix->_parent->_right)
                            {
                                toFix = toFix->_parent;
                                _leftRotate(toFix);
                            }
                            toFix->_parent->_color = BLACK;
                            toFix->_parent->_parent->_color = RED;
                            _rightRotate(toFix->_parent->_parent);
                        }
                    }
                    if (toFix == this->_root)
                        break ;
                }
                this->_root->_color = BLACK;
            }

            void _insertNewNode(node_ptr node, node_ptr toInsert)
            {
                if (node->_parent == this->_sentinal)
                    this->_root = toInsert;
                else if (node == node->_parent->_left)
                    node->_parent->_left = toInsert;
                else
                    node->_parent->_right = toInsert;
                toInsert->_parent = node->_parent;
            }

            void _eraseRotation(node_ptr toFix)
            {
                node_ptr tmp;

                while (toFix != this->_root && toFix->_color == BLACK)
                {
                    if (toFix == toFix->_parent->_left)
                    {
                        tmp = toFix->_parent->_right;
                        if (tmp->_color == RED)
                        {
                            tmp->_color = BLACK;
                            if (toFix->_parent->_color != NONE)
                                toFix->_parent->_color = RED;
                            _leftRotate(toFix->_parent);
                            tmp = toFix->_parent->_right;
                        }
                        if (tmp->_left->_color == BLACK && tmp->_right->_color == BLACK)
                        {
                            tmp->_color = RED;
                            if (toFix != this->_sentinal)
                                toFix = toFix->_parent;
                        }
                        else
                        {
                            if (tmp->_right->_color == BLACK)
                            {
                                tmp->_left->_color = BLACK;
                                tmp->_color = RED;
                                _rightRotate(tmp);
                                tmp = toFix->_parent->_right;
                            }
                            if (tmp->_color != NONE)
                                tmp->_color = toFix->_parent->_color;
                            if (toFix->_parent->_color != NONE)
                                toFix->_parent->_color = BLACK;
                            if (tmp->_right->_color != NONE)
                                tmp->_right->_color = BLACK
                            _leftRotate(toFix->_parent);
                            toFix = this->_root;
                        }
                    }
                    else
                    {
                        tmp = toFix->_parent->_left;
                        if (tmp->_color == RED)
                        {
                            tmp->_color = BLACK;
                            if (toFix->_parent->_color != NONE)
                                toFix->_parent->_color = RED;
                            _rightRotate(toFix->_parent);
                            tmp = toFix->_parent->_left;
                        }
                        if (tmp->_left->_color == BLACK && tmp->_right->_color == BLACK)
                        {
                            tmp->_color = RED;
                            toFix = toFix->_parent;
                        }
                        else
                        {
                            if (tmp->_left->_color == BLACK)
                            {
                                if (tmp->_right->_color != NONE)
                                    tmp->_right->_color = BLACK;
                                if (tmp->_color != NONE)
                                    tmp->_color = RED;
                                _leftRotate(tmp);
                                tmp = toFix->_parent->_left;
                            }
                            tmp->_color = toFix->_parent->_color;
                            if (toFix->_parent->_color != NONE)
                                toFix->_parent->_color = BLACK;
                            if (tmp->_left->_color != NONE)
                                tmp->_left->_color = BLACK;
                            _rightRotate(toFix->_parent);
                            toFix = this->_root;
                        }
                    }
                }
                if (toFix != this->_sentinal)
                    toFix->_color = BLACK;
            }

            pointer _rightMin(pointer node)
            {
                if (node == this->_sentinal)
                    return (this->_sentinal);
                while (node->_left != this->_sentinal)
                    node = node->_left;
                return (node);
            }

            bool _redBlackTreeEraseAndRebalance(value_type const &val)
            {
                node_ptr        node = this->_root;
                node_ptr        toDelete = NULL;
                node_ptr        tmp;
                node_ptr        current;
                value_compare   comp;

                while (node != this->_sentinal)
                {
                    if (comp(node->_value, val))
                        node = node->_right;
                    else if (comp(val, node->_value))
                        node = node->_left;
                    else
                    {
                        toDelete = node;
                        node = node->_right;
                    }
                }
                if (toDelete == NULL)
                    return (false);
                current = toDelete;
                int previousCurrentColor = current->_color;
                if (toDelete->_left == this->_sentinal)
                {
                    tmp = toDelete->_right;
                    _insertNewNode(toDelete, toDelete->_right);
                }
                else if (toDelete->_right == this->_sentinal)
                {
                    tmp = toDelete->_left;
                    _insertNewNode(toDelete, toDelete->_left);
                }
                else
                {
                    current = _rightMin(toDelete->_right);
                    previousCurrentColor = current->_color;
                    tmp = current->_right;
                    if (current->_parent == toDelete)
                    {
                        if (tmp != this->_sentinal)
                            tmp->_parent = current;
                    }
                    else
                    {
                        _insertNewNode(current, current->_right);
                        current->_right = toDelete->_right;
                        if (current->_right->_parent != this->_sentinal)
                            current->_right->_parent = current;
                    }
                    _insertNewNode(toDelete, current);
                    current->_left = toDelete->_left;
                    if (current->_left->_parent != this->_sentinal)
                        current->_left->_parent = current;
                    current->_color = toDelete->_color;
                }
                allocator_type().destroy(toDelete);
                allocator_type().deallocate(toDelete, 1);
                this->_size--;
                if (previousCurrentColor == BLACK)
                    _eraseRotation(tmp);
                this->_sentinal->_parent = this->_root;
                return (true);
            }

            void _swapContent(map &src)
            {
                this->clear();
                node_ptr newRoot = this->_root;
                node_ptr newSentinal = this->_sentinal;

                this->_root = src._root;
                this->_sentinal = src._sentinal;
                this->_keyCompare = src._keyCompare;
                this->_alloc = src._alloc;
                this->_size = src._size;
                src._root = newRoot;
                src._sentinal = newSentinal;
                src._size = 0;
            }

            void _destroyNode(node_ptr node)
            {
                if (node == this->_sentinal)
                    return ;
                this->_destroyNode(node->_right);
                this->_destroyNode(node->_left);
                allocator_type().destroy(node);
                allocator_type().deallocate(node, 1);
            }
    };

    template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
		if (lhs != rhs)
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		return (false);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
		if (lhs == rhs)
			return (true);
		return (!(rhs < lhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
		if (lhs == rhs)
			return (false);
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
    {
		if (lhs == rhs)
			return (true);
		return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y)
    {
		x.swap(y);
	}

}

#endif