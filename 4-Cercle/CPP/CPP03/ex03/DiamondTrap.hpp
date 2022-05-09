/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:30:10 by armendes          #+#    #+#             */
/*   Updated: 2022/05/09 17:08:50 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>
# include <string>

class DiamondTrap : public ScavTrap, public FragTrap{

private:
  std::string _name;

public:
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &T);
	~DiamondTrap(void);
	DiamondTrap &operator=(DiamondTrap const &T);

  void attack(const std::string &target);
  void whoAmI(void);

  std::string getName(void) const;
  int getHitPoints(void) const;
  int getEnergyPoints(void) const;
  int getAttackDamage(void) const;

};

#endif
