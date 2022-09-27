#include "vector.hpp"
// #include "../Containers/Vector-old.hpp"
#include <iostream>
#include <vector>
#include <iterator>

#ifndef FT
 #define FT ft
#endif

void	vector_constructor_test(void) {
	FT::vector<int>	first;									// empty vector of int
	FT::vector<int>	second((size_t)4, 100);					// 4 int of value 100
	FT::vector<int>	third(second.begin(), second.end());	// iterating through second
	FT::vector<int>	fourth(third);							// copy of third

	//iterator constructor can also be used to construct from arrays
	int	tab[] = {15, 3, 50, 30};
	FT::vector<int>	fifth(tab, tab + sizeof(tab) / sizeof(int));
////
	std::cerr << "Vector 'first' values :" << std::endl;
	for (FT::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cerr << *it << ' ';
	std::cerr << std::endl;

	std::cerr << "Vector 'second' values :" << std::endl;
	for (FT::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cerr << *it << ' ';
	std::cerr << std::endl;

	std::cerr << "Vector 'third' values :" << std::endl;
	for (FT::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cerr << *it << ' ';
	std::cerr << std::endl;

	std::cerr << "Vector 'fourth' values :" << std::endl;
	for (FT::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cerr << *it << ' ';
	std::cerr << std::endl;

	std::cerr << "Vector 'fifth' values :" << std::endl;
	for (FT::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cerr << *it << ' ';
	std::cerr << std::endl;
////
	std::cout << "Vector 'first' values :" << std::endl;
	for (FT::vector<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << "Vector 'fourth' values :" << std::endl;
	for (FT::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << "Vector 'fifth' values :" << std::endl;
	for (FT::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void	vector_operator_test(void) {
	FT::vector<int>	first(3, 0);
	FT::vector<int>	second(5, 0);

	second = first;
	first = FT::vector<int>();
	std::cout << "Size of first : " << int(first.size()) << std::endl;
	std::cout << "Size of second : " << int(second.size()) << std::endl;
}

void	vector_begin_test(void) {
	FT::vector<int>	vec;
	for (size_t i = 1; i <= 5; i++){
		vec.push_back(i);
	}
	
	std::cout << "Vec contains :" << std::endl;
	for (FT::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

void	vector_end_test(void) {
	FT::vector<int>	vec;
	for (size_t i = 1; i <= 5; i++)
		vec.push_back(i);
	
	std::cout << "Vec contains :" << std::endl;
	for (FT::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

void	vector_rbegin_test(void) {
	FT::vector<int>	vec;	// 5 default constructor int.
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(7);
	
	std::cout << "Vec contains :" << std::endl;
	for (FT::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;
}

void	vector_rend_test(void) {
	FT::vector<int>	vec;	// 5 default constructor int.
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(2);
	vec.push_back(7);
	
	std::cout << "Vec contains :" << std::endl;
	for (FT::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit)
		std::cout << *rit << " ";
	std::cout << std::endl;
}

void	vector_size_test(void) {
	FT::vector<int>	vec;
	std::cout << "A. size : " << vec.size() << std::endl;

	for (size_t i = 0; i < 10; i++) {
		vec.push_back(i);
	}
	std::cout << "B. size : " << vec.size() << std::endl;

	vec.insert(vec.end(), 10, 100);
	std::cout << "C. size : " << vec.size() << std::endl;
	
	vec.pop_back();
	std::cout << "D. size : " << vec.size() << std::endl;
}

void	vector_maxsize_test(void) {
	FT::vector<int>	vec;

	for (size_t i = 0; i < 100; i++)
		vec.push_back(i);
	std::cout << "Size	 : " << vec.size() << std::endl;
	std::cout << "Max_size : " << vec.max_size() << std::endl;
	std::cout << "Capacity : " << vec.capacity() << std::endl;
}

void	vector_resize_test(void) {
	FT::vector<int>	vec;

	for (size_t i = 0; i < 10; i++)
		vec.push_back(i);
	vec.resize(5);
	vec.resize(8, 100);
	vec.resize(12);
	std::cout << "Vec contains :" << std::endl;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
}

void	vector_capacity_test(void) {
	FT::vector<int>	vec;

	for (size_t i = 0; i < 100; i++)
		vec.push_back(i);
	std::cout << "Size	 : " << vec.size() << std::endl;
	std::cout << "Max_size : " << vec.max_size() << std::endl;
	std::cout << "Capacity : " << vec.capacity() << std::endl;
}

void	vector_empty_test(void) {
	FT::vector<int>	vec;
	int						sum(0);

	for (size_t i = 1; i <= 10; i++)
		vec.push_back(i);
	while (!vec.empty()) {
		sum += vec.back();
		vec.pop_back();
	}
	std::cout << "Total: " << sum << std::endl;
}

void	vector_reserve_test(void) {
	FT::vector<int>::size_type	first;
	FT::vector<int>				second;

	first = second.capacity();
	std::cout << "Making second grow :" << std::endl;
	for (size_t i = 0; i < 100; i++) {
		second.push_back(i);
		if (first != second.capacity()) {
			first = second.capacity();
			std::cout << "Capacity changed to : " << first << std::endl; 
		}
	}
	FT::vector<int>				third;
	first = third.capacity();
	third.reserve(100);
	std::cout << "Making third grow :" << std::endl;
	for (size_t i = 0; i < 100; i++) {
		third.push_back(i);
		if (first != third.capacity()) {
			first = third.capacity();
			std::cout << "Capacity changed to : " << first << std::endl; 
		}
	}
}

void	vector_subscript_operator_test(void) {
	FT::vector<int>					first(10);
	FT::vector<int>::size_type		second = first.size();

	for (unsigned int i = 0; i < second; i++)
		first[i] = i;
	for (unsigned i = 0; i < second/2; i++) {
		int tmp;
		tmp = first[second - 1 - i];
		first[second - 1 - i] = first[i];
		first[i] = tmp;
	}
	std::cout << "Vec contains :" << std::endl;
	for (unsigned int i = 0; i < second; i++)
		std::cout << first[i] << ' ';
	std::cout << std::endl;
}

void	vector_at_test(void) {
	FT::vector<int>		vec(10);

	for (unsigned i = 0; i < vec.size(); i++) 
		vec.at(i) = i;
	std::cout << "Vec contains :" << std::endl;
	for (unsigned i = 0; i < vec.size(); i++)
		std::cout << vec.at(i) << ' ';
	std::cout << std::endl;
}

void	vector_front_test(void) {
	FT::vector<int>		vec;

	vec.push_back(70);
	vec.push_back(20);
	vec.front() -= vec.back();
	std::cout << "Vec front() : " << vec.front() << std::endl;
}

void	vector_back_test(void) {
	FT::vector<int>		vec;

	vec.push_back(16);
	while (vec.back() != 0)
		vec.push_back(vec.back() - 1);
	std::cout << "Vec contains :" << std::endl;
	for (unsigned i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
}

void	vector_assign_test(void) {
	FT::vector<int>					first;
	FT::vector<int>					second;
	FT::vector<int>					third;
	FT::vector<int>::iterator		it;
	int								tab[] = {16, 4, 8};

	first.assign(7, 100);
	it = first.begin() + 1;
	second.assign(it, first.end() - 1);
	third.assign(tab, tab + 3);

	std::cout << "Size of first	: " << int(first.size()) << std::endl;
	std::cout << "Vec first contains :" << std::endl;
	for (unsigned i = 0; i < first.size(); i++)
		std::cout << first[i] << ' ';
	std::cout << std::endl << std::endl;

	std::cout << "Size of second	: " << int(second.size()) << std::endl;
	std::cout << "Vec second contains :" << std::endl;
	for (unsigned i = 0; i < second.size(); i++)
		std::cout << second[i] << ' ';
	std::cout << std::endl << std::endl;

	std::cout << "Size of third	: " << int(third.size()) << std::endl;
	std::cout << "Vec third contains :" << std::endl;
	for (unsigned i = 0; i < third.size(); i++)
		std::cout << third[i] << ' ';
	std::cout << std::endl;
}

void	vector_insert_test(void) {
	FT::vector<int>::iterator	it;
	FT::vector<int>				first(3, 100);
	FT::vector<int>				second(2, 400);
	int							array[] = {1, 2, 3};

	it = first.begin();
	it = first.insert(it, 200);
	first.insert(it, 2, 300);

	it = first.begin();
	first.insert(it + 2, second.begin(), second.end());
	first.insert(first.begin(), array, array + 3);

	std::cout << "Vec first contains :" << std::endl;
	for (it = first.begin(); it != first.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void	vector_erase_test(void) {
	FT::vector<int>		vec;

	for (size_t i = 1; i <= 10; i++)
		vec.push_back(i);
	// std::cout << "Vec contains (before) :" << std::endl;
	// for (unsigned i = 0; i < vec.size(); i++)
	// 	std::cout << vec[i] << ' ';
	// std::cout << std::endl;
	vec.erase(vec.begin());
	vec.erase(vec.begin() + 5);
	vec.erase(vec.begin(), vec.begin() + 4);
	std::cout << "Vec contains :" << std::endl;
	for (unsigned i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
}

void	vector_swap_test(void) {
	FT::vector<int>				first(3, 100);
	FT::vector<int>				second(4, 200);
	FT::vector<int>::iterator	it = first.begin();

	std::cout << "*it : " << *it << std::endl;
	first.swap(second);
	std::cout << "*it : " << *it << std::endl;
	std::cout << "Vec first contains :" <<std::endl;
	
	for (unsigned i = 0; i < first.size(); i++)
		std::cout << first[i] << ' ';
	std::cout << std::endl << std::endl;

	std::cout << "Vec second contains :" <<std::endl;
	for (unsigned i = 0; i < second.size(); i++)
		std::cout << second[i] << ' ';
	std::cout << std::endl;
}

void	vector_clear_test(void) {
	FT::vector<int>		vec;

	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(300);
	std::cout << "Vec contains :" << std::endl;
	for (unsigned i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl << std::endl;

	vec.clear();
	vec.push_back(400);
	vec.push_back(500);
	std::cout << "Vec contains :" << std::endl;
	for (unsigned i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
}

void	vector_get_allocator_test(void) {
	FT::vector<int>		vec;
	int					*p = vec.get_allocator().allocate(5);

	for (unsigned int i = 0; i < 5; i++)
		vec.get_allocator().construct(&p[i], i);
	std::cout << "Vec contains :" << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		std::cout << p[i] << ' ';
	std::cout << std::endl;
	for (unsigned int i = 0; i < 5; i++)
		vec.get_allocator().destroy(&p[i]);
	vec.get_allocator().deallocate(p, 5);
}

void	vector_nm_swap_test(void) {
	FT::vector<int>		first(3, 100);
	FT::vector<int>		second(4, 300);

	first.swap(second);
	std::cout << "Vec first contains :" << std::endl;
	for (FT::vector<int>::iterator it = first.begin(); it != first.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;

	std::cout << "Vec second contains :" << std::endl;
	for (FT::vector<int>::iterator it = second.begin(); it != second.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void	vector_testing(void) {
	std::cout << "\033[1;35m/* ******** Vector Constructor Test ******** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_constructor_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Operators Test ********** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_operator_test();
	
	/* ****************************** Iterators ***************************** */
	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Begin Test ************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_begin_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector End Test **************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_end_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Rbegin Test ************* */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_rbegin_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Rend Test *************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_rend_test();

	/* ****************************** Capacity ****************************** */
	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Size Test *************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_size_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Maxsize Test ************ */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_maxsize_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Resize Test ************* */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_resize_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Capacity Test *********** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_capacity_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Empty Test ************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_empty_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Reserve Test ************ */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_reserve_test();

	/* *************************** Element Access *************************** */
	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Subscript Operator Test * */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_subscript_operator_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector At Test ***************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_at_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Front Test ************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_front_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Back Test *************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_back_test();

	/* ****************************** Modifiers ***************************** */
	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Assign Test ************* */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_assign_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Insert Test ************* */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_insert_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Erase Test ************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_erase_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Swap Test *************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_swap_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Clear Test *************** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_clear_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector Get_Allocator Test ****** */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_get_allocator_test();

	std::cout << std::endl;
	std::cout << "\033[1;35m/* ******** Vector NM_Swap Test ************ */\033[0m" << std::endl;
	std::cout << std::endl;
	vector_nm_swap_test();

	std::cout << std::endl;
}

int		main( void ) {
	/* ********************************************************************** */
	/* **************************** TESTS VECTOR **************************** */
	/* ********************************************************************** */
	std::cout << "\033[1;34m/* ***************************************** */\033[0m" << std::endl;
	std::cout << "\033[1;34m/* ************** TESTS VECTOR ************* */\033[0m" << std::endl;
	std::cout << "\033[1;34m/* ***************************************** */\033[0m" << std::endl;
	std::cout << std::endl;

	vector_testing();
	return 0;
}