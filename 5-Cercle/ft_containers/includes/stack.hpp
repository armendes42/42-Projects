/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:12:33 by armendes          #+#    #+#             */
/*   Updated: 2022/10/30 23:30:56 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
    template < class T, class Container = ft::vector<T> >
    class stack
    {

        public:
            typedef Container                           container_type;
            typedef typename Container::value_type      value_type;
            typedef typename Container::reference       reference;
            typedef typename Container::const_reference const_reference;
            typedef typename Container::size_type       size_type;

        protected:
            container_type  _container;

        public:
            explicit stack(const container_type &container = container_type()) : _container(container) {};

            virtual ~stack(void) {}

            bool empty() const
            {
                return (this->_container.empty());
            }

            void pop()
            {
                this->_container.pop_back();
            }

            void push(const value_type &val)
            {
                this->_container.push_back(val);
            }

            size_type size() const
            {
                return (this->_container.size());
            }

            reference top()
            {
                return (this->_container.back());
            }

            const_reference top() const
            {
                return (this->_container.back());
            }

            friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
            {
                return (lhs._container == rhs._container);
            }

            friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
            {
                return (lhs._container < rhs._container);
            }
    };

    template <class T, class Container>
    bool operator!=(const stack<T,Container> &lhs, const stack<T,Container> &rhs) {

        return (!(lhs == rhs));
    }

    template <class T, class Container>
    bool operator<=(const stack<T,Container> &lhs, const stack<T,Container> &rhs) {

        return (!(rhs < lhs));
    }

    template <class T, class Container>
    bool operator>(const stack<T,Container> &lhs, const stack<T,Container> &rhs) {

        return (rhs < lhs);
    }

    template <class T, class Container>
    bool operator>=(const stack<T,Container> &lhs, const stack<T,Container> &rhs) {

        return (!(lhs < rhs));
    }
}

#endif