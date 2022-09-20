/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:31:40 by armendes          #+#    #+#             */
/*   Updated: 2022/09/20 14:33:01 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NULLPTR_HPP
# define NULLPTR_HPP

namespace ft
{
    struct nullptr_t
    {
        void	*_ptr;

        struct __nat { int __for_bool_; };

        nullptr_t() : _ptr(0) {}
        nullptr_t(int __nat::*) : _ptr(0) {}
        
        operator int __nat::*() const { return 0; }

        template <class T>
        operator	T*() const { return 0; }

        template <class T, class _Up>
        operator	T _Up::*() const { return 0; }

        friend bool	operator==(nullptr_t, nullptr_t) { return true; }
        friend bool	operator!=(nullptr_t, nullptr_t) { return false; }
    };

    # define nullptr_  nullptr_t(0)
}

#endif