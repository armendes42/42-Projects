/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:20:04 by armendes          #+#    #+#             */
/*   Updated: 2022/06/03 16:06:09 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form{

private:
  std::string const _name;
  bool  _signed;
  int const _sign_grade;
  int const _exec_grade;

  static const int highestGrade;
  static const int lowestGrade;

public:
	Form(std::string name, int sign_grade, int exec_grade);
	Form(Form const &T);
	~Form(void);
	Form & operator=(Form const &T);

  std::string getName(void) const;
  bool getSigned(void) const;
  int getSignGrade(void) const;
  int getExecGrade(void) const;

  void beSigned(Bureaucrat &person);

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

  class AlreadySignedException : public std::exception{

  public:
    virtual const char *what() const throw()
    {
      return ("The form is already signed");
    }

  };

};

std::ostream &operator<<(std::ostream &stdout, Form const &form);

#endif
