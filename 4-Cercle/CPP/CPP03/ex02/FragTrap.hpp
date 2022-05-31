/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:03:00 by armendes          #+#    #+#             */
/*   Updated: 2022/05/31 17:15:14 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap{

public:
	FragTrap(std::string name);
	FragTrap(FragTrap const &T);
	~FragTrap(void);
	FragTrap &operator=(FragTrap const &T);

	void attack(const std::string &target);
  void highFivesGuys(void);

};

#endif
