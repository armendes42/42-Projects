/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:56:29 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 16:25:43 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include "Form.hpp"
# include <iostream>
# include <string>

class PresidentialPardonForm : public Form{

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &T);
	~PresidentialPardonForm(void);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &T);

  void execute(Bureaucrat const & executor) const;

};

#endif
