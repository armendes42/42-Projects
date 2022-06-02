/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 19:25:08 by armendes          #+#    #+#             */
/*   Updated: 2022/06/02 19:25:17 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

# define KEY ""

static std::string input;

int main()
{
	std::cout << std::endl << "Please, press ENTER" << KEY << std::endl;
	std::getline(std::cin, input);
	system ("clear");
	std::cout << std::endl << "*" << "\033[1;34m Simple tests \033[0m------------------------------------- *" << std::endl;
	if (input == KEY)
	{
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{
			std::cout << std::endl;
			Span sp = Span(10);
			sp.addNumber(0);
			sp.addNumber(2);
			sp.addNumber(28);
			sp.addNumber(50);
			sp.addNumber(37);
			sp.addNumber(20);
			sp.addNumber(26);
			sp.addNumber(8);
			sp.addNumber(5);
			sp.addNumber(99);
			std::cout << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{
			std::cout << std::endl << "test full span" << std::endl;
			Span sp = Span(2);
			try
			{
				std::cout << "try to add 0" << std::endl;
				sp.addNumber(0);
				std::cout << "try to add 2" << std::endl;
				sp.addNumber(2);
				std::cout << "try to add 28" << std::endl;
				sp.addNumber(28);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() <<  std::endl;
			}
			std::cout << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{
			std::cout << std::endl << "test empty span" << std::endl;
			Span sp = Span(0);
			try
			{
				std::cout << sp.longestSpan() << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() <<  std::endl;
			}

			try
			{
				std::cout << sp.shortestSpan() << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() <<  std::endl;
			}
		}
	}

	std::cout << std::endl << "Please, press ENTER" << KEY << std::endl;
	std::getline(std::cin, input);
	system ("clear");
	std::cout << std::endl << "*" << "\033[1;34m addRange tests \033[0m----------------------------------- *" << std::endl;
	if (input == KEY)
	{
		Span sp = Span(50000);
		std::vector<int> range(50000, 8);
		sp.addRange(range.begin(), range.end());
		std::cout << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl << "Please, press ENTER" << KEY << std::endl;
	std::getline(std::cin, input);
	system ("clear");
	std::cout << std::endl << "*" << "\033[1;34m Random tests \033[0m------------------------------------- *" << std::endl;
	if (input == KEY)
	{
		{
			srand (time(NULL));
			size_t size = rand() %20;
			Span sp = Span(size);
			for (unsigned int i = 0; i < size; i++)
				sp.addNumber(rand() %1000);
			std::cout << std::endl << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{
			srand (time(NULL));
			size_t size = rand() %50;
			Span sp = Span(size);
			for (unsigned int i = 0; i < size; i++)
				sp.addNumber(rand() %100);
			std::cout << std::endl << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{
			srand (time(NULL));
			size_t size = rand() %100;
			Span sp = Span(size);
			for (unsigned int i = 0; i < size; i++)
				sp.addNumber(rand() %10);
			std::cout << std::endl << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{
			srand (time(NULL));
			size_t size = 10;
			Span sp = Span(size);
			for (unsigned int i = 0; i < size; i++)
				sp.addNumber(rand() %50000);
			std::cout << std::endl << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{
			srand (time(NULL));
			size_t size = 10;
			Span sp = Span(size);
			for (unsigned int i = 0; i < size; i++)
				sp.addNumber(rand() %10000);
			std::cout << std::endl << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
		{
			srand (time(NULL));
			size_t size = 10;
			Span sp = Span(size);
			for (unsigned int i = 0; i < size; i++)
				sp.addNumber(rand() %RAND_MAX);
			std::cout << std::endl << "[span] : \033[1m" << sp << "\033[0m" << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
		}
	}

	return 0;
}
