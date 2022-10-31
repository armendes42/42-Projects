/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:42:22 by armendes          #+#    #+#             */
/*   Updated: 2022/10/31 19:20:16 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include <limits>
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
                    this->_destoryNode(this->_root);
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





        private:
            node_ptr        _root;
            node_ptr        _sentinal;
            allocator_type  _alloc;
            key_compare     _keyCompare;
            size_type       _size;
    };

}

#endif