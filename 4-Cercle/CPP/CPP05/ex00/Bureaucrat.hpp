/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:53 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 16:03:33 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat{

private:
  std::string const _name;
  int _grade;

  static const int highestGrade;
  static const int lowestGrade;

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &T);
	~Bureaucrat(void);
	Bureaucrat &operator=(Bureaucrat const &T);

  std::string const getName(void) const;
  int getGrade(void) const;

  void upGrade(void);
  void downGrade(void);

  class GradeTooHighException : public std::exception{

  public:
    virtual const char *what() const throw()
    {
      return ("The grade you try to set is too high");
    }

  };

  class GradeTooLowException : public std::exception{

  public:
    virtual const char *what() const throw()
    {
      return ("The grade you try to set is too low");
    }

  };

};

std::ostream &operator<<(std::ostream &stdout, Bureaucrat const &person);

#endif
