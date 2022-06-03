/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:56:26 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 20:24:20 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "Form.hpp"
# include <iostream>
# include <string>

class RobotomyRequestForm : public Form{

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &T);
	~RobotomyRequestForm(void);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &T);

  void action(Bureaucrat const & executor) const;

};

#endif
