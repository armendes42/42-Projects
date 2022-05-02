/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:52:46 by armendes          #+#    #+#             */
/*   Updated: 2022/05/02 20:13:47 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	void default_msg(void);
	int getLevel(std::string level);

public:
	Harl(void);
	~Harl(void);
	void switchComplain(std::string level);
	void complain(std::string level);

};

#endif