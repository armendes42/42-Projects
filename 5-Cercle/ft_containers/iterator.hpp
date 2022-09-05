/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:29:35 by armendes          #+#    #+#             */
/*   Updated: 2022/06/22 16:29:39 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>
# include <string>

class iterator{

private:


public:
	iterator(void);
	iterator(iterator const &T);
	~iterator(void);
	iterator &operator=(iterator const &T);

};

#endif
