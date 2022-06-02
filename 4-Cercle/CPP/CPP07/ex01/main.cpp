/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:12:16 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 15:21:07 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <limits.h>
#include <stdlib.h>

class Awesome
{
  private:
    int _n;
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get();return o; }


template<typename T>
void	print(T const & a)
{
	std::cout << a << std::endl;
	return ;
}

template<typename T>
void	doooble(T const & a)
{

	if (a > INT_MAX / 2)
	{
		std::cout << "out of range" << std::endl;
		return ;
	}

	T result = a * 2;
	std::cout << result << std::endl;
	return ;
}

int main()
{
	int tab[] = { 0, 1, 2, 3, 4 };

	std::cout << std::endl << "\033[1;37mtab: { 0, 1, 2, 3, 4 }\033[0m" << std::endl;
	std::cout << std::endl << "Print tab:" << std::endl;
	iter( tab, 5, print );
	std::cout << std::endl << "Doooble tab:" << std::endl;
	iter( tab, 5, doooble );

	std::cout << std::endl << "\033[1;37mAwesome tab2[5]\033[0m" << std::endl;
	std::cout << std::endl << "Print tab2:" << std::endl;
	Awesome tab2[5];
	iter( tab2, 5, print );

	int randArray[15];
	for(int i = 0; i < 15; i++)
		randArray[i] = rand() %RAND_MAX;

	std::cout << std::endl << "Print tab:" << std::endl;
	iter( randArray, 15, print );
	std::cout << std::endl << "Doooble tab:" << std::endl;
	iter( randArray, 15, doooble );
	return 0;
}
