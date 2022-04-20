/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:16:16 by armendes          #+#    #+#             */
/*   Updated: 2022/04/07 20:39:05 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

private:
	Contact	tabContact[8];

public:
	PhoneBook( void );
	~PhoneBook( void );

	void	setContact( Contact contact );
	void	add( void );
	void	search( void );
};

#endif