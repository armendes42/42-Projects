/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:04:49 by armendes          #+#    #+#             */
/*   Updated: 2022/05/16 17:16:58 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include <iostream>
# include <string>

class Intern{

private:
  typedef struct s_form_struct
  {
      std::string formName;
      Form *formType;
  }               t_form_struct;

public:
	Intern(void);
	Intern(Intern const &T);
	~Intern(void);
	Intern &operator=(Intern const &T);

  Form *makeForm(std::string nameForm, std::string target);

  class FormNotExistException : public std::exception{

  public:
    virtual const char *what() const throw()
    {
      return ("The form you try to create doesn't exist");
    }

  };

};

#endif
