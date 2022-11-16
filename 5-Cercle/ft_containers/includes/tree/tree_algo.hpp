/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_algo.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:57:09 by armendes          #+#    #+#             */
/*   Updated: 2022/11/16 22:02:15 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ALGO_HPP
# include TREE_ALGO_HPP

# include <cstddef>
# include "tree_types.hpp"

namespace ft
{

    template <typename NodePtr>
    inline bool tree_is_left_child(NodePtr ptr)
    {
        return ptr == ptr->parent->left;
    }

    template <typename NodePtr>
    NodePtr tree_max(NodePtr ptr)
    {
        while (ptr->right != NULL)
            ptr = ptr->right;
        return (ptr);
    }

    template <typename NodePtr>
    NodePtr tree_min(NodePtr ptr)
    {
        while (ptr->left != NULL)
            ptr = ptr->left;
        return (ptr);
    }

    template <typename IterPtr, typename NodePtr>
    IterPtr tree_iter_next(NodePtr ptr)
    {
        if (ptr->right != NULL)
            return (tree_min(ptr->right));
        while (!tree_is_left_child(ptr))
            ptr = ptr->get_parent();
        return (ptr->parent);
    }


}

#endif