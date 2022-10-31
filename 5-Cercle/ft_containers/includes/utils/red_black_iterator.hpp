/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:35:21 by armendes          #+#    #+#             */
/*   Updated: 2022/10/31 21:46:49 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_ITERATOR_HPP
# define RED_BLACK_ITERATOR_HPP

namespace ft
{

    enum e_tree_color
    {
        NONE,
        RED,
        BLACK
    };

    template <typename T>
    struct setNode
    {
        T               _value;
        setNode         *_parent;
        setNode         *_left;
        setNode         *_right;
        e_tree_color    _color;

        setNode(T src = T()) : _value(src)
        {
            this->_parent = NULL;
            this->_left = NULL;
            this->_right = NULL;
            this->_color = RED;
        }

        setNode(T src, e_tree_color color, setNode *parent, setNode *left, setNode *right) : _value(src)
        {
            this->_parent = parent;
            this->_left = left;
            this->_right = right;
            this->_color = color;
        }

        setNode(e_tree_color color, setNode *parent, setNode *left, setNode *right)
        {
            this->_parent = parent;
            this->_left = left;
            this->_right = right;
            this->_color = color;
        }
    };

    template <typename T>
    struct mapNode
    {
        T               _value;
        mapNode         *_parent;
        mapNode         *_left;
        mapNode         *_right;
        e_tree_color    _color;

        mapNode(T src = T()) : _value(src)
        {
            this->_parent = NULL;
            this->_left = NULL;
            this->_right = NULL;
            this->_color = RED;
        }

        mapNode(T src, e_tree_color color, mapNode *parent, mapNode *left, mapNode *right) : _value(src)
        {
            this->_parent = parent;
            this->_left = left;
            this->_right = right;
            this->_color = color;
        }

        mapNode(e_tree_color color, mapNode *parent, mapNode *left, mapNode *right)
        {
            this->_parent = parent;
            this->_left = left;
            this->_right = right;
            this->_color = color;
        }
    };

    template <typename T, typename Node>
    class red_black_iterator
    {

        public:
            typedef T               value_type;
            typedef Node            node_type;
            typedef Node            *node_pointer;
            typedef value_type      &reference;
            typedef value_type      *pointer;
            typedef std::ptrdiff_t  difference_type;

            red_black_iterator(void) {}

            red_black_iterator(node_type *src, node_type *sentinal = NULL)
            {
                this->_node = src;
                if (sentinal != NULL)
                    this->_sentinal = sentinal;
            }

            red_black_iterator(red_black_iterator const &other)
            {
                *this = other;
            }

            virtual ~red_black_iterator(void) {}

            operator red_black_iterator<const T, Node>(void)
            {
                return (red_black_iterator<const T, Node>(this->_node, this->_sentinal));
            }

            red_black_iterator &operator=(red_black_iterator const &other)
            {
                if (this == &other)
                    return (*this);
                this->_node = other._node;
                if (other._sentinal != NULL)
                    this->_sentinal = other._sentinal;
                return (*this);
            }

            friend bool operator==(red_black_iterator const &lhs, red_black_iterator const &rhs)
            {
                if (lhs._node == rhs._node)
                    return (true);
                return (false);
            }

            friend bool operator!=(red_black_iterator const &lhs, red_black_iterator const &rhs)
            {
                if (lhs._node != rhs._node)
                    return (true);
                return (false);
            }

            red_black_iterator &operator++(void)
            {
                this->_node = rbi_increment(this->_node);
                return (*this);
            }

            red_black_iterator operator++(int)
            {
                red_black_iterator tmp = (*this);
                ++(*this);
                return (tmp);
            }

            red_black_iterator &operator--(void)
            {
                this->_node = rbi_decrement(this->_node);
                return (*this);
            }

            red_black_iterator operator--(int)
            {
                red_black_iterator tmp = (*this);
                --(*this);
                return (tmp);
            }

            reference operator*(void) const
            {
                return (this->_node->_value);
            }

            pointer operator->(void) const
            {
                return (&(this->operator*()));
            }


        private:
            Node    *_node;
            Node    *_sentinal;

            node_pointer rbi_increment(node_pointer head)
            {
                if (head->_right != this->_sentinal)
                    head = lastLeft(head->_right);
                else
                {
                    node_type   *child = head;
                    head = head->_parent;
                    while (head != this->_sentinal && child == head->_right)
                    {
                        child = head;
                        head = head->_parent;
                    }
                }
                return (head);
            }

            node_pointer rbi_decrement(node_pointer head)
            {
                if (head == this->_sentinal)
                {
                    while (head->_parent != this->_sentinal)
                        head = head->_parent;
                    head = lastRight(head);
                }
                else if (head->_left != this->_sentinal)
                    head = lastRight(head->_left);
                else
                {
                    node_type   *child = head;
                    head = head->_parent;
                    while (head != this->_sentinal && child == head->_left)
                    {
                        child = head;
                        head = head->_parent;
                    }
                }
                return (head);
            }

    };

    template <typename T>
    setNode<T> *lastLeft(setNode<T> *head)
    {
        if (head->_color != NONE)
        {
            while (head->_left->_color != NONE)
                head = head->_left;
        }
        return (head);
    }

    template <typename T>
    mapNode<T> *lastLeft(mapNode<T> *head)
    {
        if (head->_color != NONE)
        {
            while (head->_left->_color != NONE)
                head = head->_left;
        }
        return (head);
    }

    template <typename T>
    setNode<T> *lastRight(setNode<T> *head)
    {
        if (head->_color != NONE)
        {
            while (head->_right->_color != NONE)
                head = head->_right;
        }
        return (head);
    }

    template <typename T>
    mapNode<T> *lastRight(mapNode<T> *head)
    {
        if (head->_color != NONE)
        {
            while (head->_right->_color != NONE)
                head = head->_right;
        }
        return (head);
    }

}

#endif