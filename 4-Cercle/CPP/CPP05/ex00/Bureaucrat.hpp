/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:53 by armendes          #+#    #+#             */
/*   Updated: 2022/05/11 18:33:57 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat{

private:
  std::string const _name;
  int _grade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &T);
	~Bureaucrat(void);
	Bureaucrat &operator=(Bureaucrat const &T);

};

#endif
