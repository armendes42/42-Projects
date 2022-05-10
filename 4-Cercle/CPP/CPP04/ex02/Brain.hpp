/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:49:27 by armendes          #+#    #+#             */
/*   Updated: 2022/05/10 16:03:49 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain{

public:
	Brain(void);
	Brain(Brain const &T);
	~Brain(void);
	Brain &operator=(Brain const &T);

	std::string	ideas[100];

};

#endif
