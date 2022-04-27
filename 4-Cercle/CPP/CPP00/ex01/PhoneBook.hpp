/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:16:16 by armendes          #+#    #+#             */
/*   Updated: 2022/04/27 15:43:03 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string.h>

class PhoneBook {

private:
	Contact	tabContact[8];

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	setContact(Contact contact);
	void	add(void);
	void	search(void);
	void	format_output( std::string line);
	void	format_id(int id);
	void	print_the_contact(int id);
	int		check_id(int id);
};

#endif