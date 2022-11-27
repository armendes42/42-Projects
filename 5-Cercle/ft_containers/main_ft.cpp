/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:41:07 by armendes          #+#    #+#             */
/*   Updated: 2022/11/27 17:58:40 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <string>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"

using namespace std;

void print_vector(ft::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << "Element " << i << " is " << vec[i] << endl;
    }
}

void test_constructor_vector(void)
{
    cout << "\033[1;34mConstructor Vector: Empty\033[0;m" << endl;
    ft::vector<int> first;
    print_vector(first);
    cout << endl;

    cout << "\033[1;34mConstructor Vector: Allocator\033[0;m" << endl;
    allocator<int> alloc;
    ft::vector<int> second(alloc);
    print_vector(second);
    cout << endl;

    cout << "\033[1;34mConstructor Vector: Count Values\033[0;m" << endl;
    ft::vector<int> third(5, 1, alloc);
    print_vector(third);
	ft::vector<int> third1(0, 1, alloc);
	print_vector(third1);
	// ft::vector<int> third2(third.max_size(), 1, alloc);
	// print_vector(third2);
    cout << endl;

    cout << "\033[1;34mConstructor Vector: Other Vector\033[0;m" << endl;
    ft::vector<int> fourth(third);
    print_vector(fourth);
    cout << endl;

    cout << "\033[1;34mConstructor Vector: Range\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> fifth(range, range + 5);
    print_vector(fifth);
    cout << endl;
}

void test_operator_equal_vector(void)
{
    cout << "\033[1;34mOperator = Vector\033[0;m" << endl;
    ft::vector<int> first(4, 1);
    ft::vector<int> second(4, 2);
    print_vector(first);
    cout << endl;
    print_vector(second);
    cout << endl << endl;
    second = first;
    print_vector(first);
    cout << endl;
    print_vector(second);
    cout << endl;
}

void test_assign_vector(void)
{
    cout << "\033[1;34mAssign Vector : Count Values\033[0;m" << endl;
    ft::vector<int> first(4, 1);
    print_vector(first);
    cout << endl;
    first.assign(3, 2);
    print_vector(first);
    cout << endl;

    cout << "\033[1;34mAssign Vector : Range\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> second(4, 1);
    print_vector(second);
    cout << endl;
    second.assign(range, range + 5);
    print_vector(second);
    cout << endl;
}

void test_get_allocator_vector(void)
{
    cout << "\033[1;34mGet Allocator Vector\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    int *p = NULL;
    p = first.get_allocator().allocate(5);
    for (int i = 0; i < 5; ++i)
        p[i] = i + 1;
    for (int i = 0; i < 5; ++i)
        cout << p[i] << endl;
    cout << endl;
}

void test_at_vector(void)
{
    cout << "\033[1;34mAt Vector\033[0;m" << endl;
    int range[] = {2, 4, 6, 8, 10};
    ft::vector<int> first(range, range + 5);
    cout << "Element 2 is " << first.at(2) << endl;
    cout << "Element 4 is " << first.at(4) << endl;
	// cout << "Element out of bound is " << first.at(-1) << endl;
	// cout << "Element out of bound is " << first.at(7) << endl;
    cout << endl;
}

void test_operator_square_brackets_vector(void)
{
    cout << "\033[1;34mOperator [] Vector\033[0;m" << endl;
    int range[] = {5, 4, 3, 2, 1};
    ft::vector<int> first(range, range + 5);
    for (size_t i = 0; i < 5; i++)
	{
        cout << first[i] << endl;
	}
	cout << first[-1] << endl;
	cout << first[7] << endl;
    cout << endl;
}

void test_front_vector(void)
{
    cout << "\033[1;34mFront Vector\033[0;m" << endl;
    int range[] = {2, 3, 5, 6, 8, 9};
    ft::vector<int> first(range, range + 6);
    cout << first.front() << endl;
	// ft::vector<int> second;
	// cout << second.front() << endl;
    cout << endl;
}

void test_back_vector(void)
{
    cout << "\033[1;34mBack Vector\033[0;m" << endl;
    int range[] = {2, 3, 5, 6, 8, 9};
    ft::vector<int> first(range, range + 6);
    cout << first.back() << endl;
	// ft::vector<int> second;
	// cout << second.back() << endl;
    cout << endl;
}

void test_data_vector(void)
{
    cout << "\033[1;34mData Vector\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    int *p = first.data();
    for (int i = 0; i < 5; i++)
	{
        cout << p[i] << endl;
	}
	// ft::vector<int> second;
	// int *p2 = second.data();
	// cout << p2[0] << endl;
    cout << endl;
}

void test_begin_vector(void)
{
    cout << "\033[1;34mBegin Vector\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    cout << *first.begin() << endl;
	ft::vector<int> second;
	if (second.begin() == second.end())
		cout << "Begin is good on an empty vector" << endl;
    cout << endl;
}

void test_end_vector(void)
{
    cout << "\033[1;34mEnd Vector\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    cout << *(first.end() - 1) << endl;
    cout << endl;
}

void test_rbegin_vector(void)
{
    cout << "\033[1;34mRbegin Vector\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    cout << *first.rbegin() << endl;
	ft::vector<int> second;
	if (second.rbegin() == second.rend())
		cout << "Rbegin is good on an empty vector" << endl;
    cout << endl;
}

void test_rend_vector(void)
{
    cout << "\033[1;34mRend Vector\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    cout << *(first.rend() - 1) << endl;
    cout << endl;
}

void test_empty_vector(void)
{
    cout << "\033[1;34mEmpty Vector\033[0;m" << endl;
    ft::vector<int> first;
    cout << first.empty() << endl;
    cout << endl;
    ft::vector<int> second(3, 1);
    cout << second.empty() << endl;
    cout << endl;
}

void test_size_vector(void)
{
    cout << "\033[1;34mSize Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    cout << first.size() << endl;
	ft::vector<int> second;
	cout << second.size() << endl;
    cout << endl;
}

void test_max_size_vector(void)
{
    cout << "\033[1;34mMax Size Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    cout << first.max_size() << endl;
    cout << endl;
}

void test_capacity_vector(void)
{
    cout << "\033[1;34mCapacity Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    cout << first.capacity() << endl;
    cout << endl;
}

void test_reserve_vector(void)
{
    cout << "\033[1;34mReserve Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    cout << first.capacity() << endl;
    first.reserve(6);
    cout << first.capacity() << endl;
	// first.reserve(first.max_size());
    cout << endl;
}

void test_clear_vector(void)
{
    cout << "\033[1;34mClear Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    print_vector(first);
    cout << "Size of vector is " << first.size() << endl;
	cout << "Capacity of vector is " << first.capacity() << endl;
    first.clear();
    print_vector(first);
    cout << "Size of vector is " << first.size() << endl;
	cout << "Capacity of vector is " << first.capacity() << endl;
    cout << endl;
}

void test_insert_vector(void)
{
    cout << "\033[1;34mInsert Vector : Pos value\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    print_vector(first);
    cout << endl;
    ft::vector<int>::iterator i = first.begin() + 2;
	ft::vector<int>::iterator it = first.insert(i, 2);
    print_vector(first);
	cout << *it << endl;
    cout << endl << endl;

    cout << "\033[1;34mInsert Vector : Pos Count Values\033[0;m" << endl;
    ft::vector<int> second(3, 1);
    print_vector(second);
    cout << endl;
    ft::vector<int>::iterator j = second.begin() + 2;
    second.insert(j, 2, 3);
    print_vector(second);
    cout << endl << endl;

    cout << "\033[1;34mInsert Vector : Range\033[0;m" << endl;
    ft::vector<int> third(3, 1);
    print_vector(third);
    cout << endl;
    int range[] = {3, 4, 5};
    ft::vector<int>::iterator k = third.begin() + 2;
    third.insert(k, range, range + 3);
    print_vector(third);
    cout << endl << endl;
}

void test_erase_vector(void)
{
    cout << "\033[1;34mErase Vector : Pos\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    print_vector(first);
    cout << endl;
    ft::vector<int>::iterator i = first.begin() + 2;
    ft::vector<int>::iterator it = 	first.erase(i);
    print_vector(first);
	cout << *it << endl;
	ft::vector<int>::iterator it2 = first.erase(first.begin() + 3);
	print_vector(first);
	cout << *it2 << endl;
    cout << endl << endl;

    cout << "\033[1;34mErase Vector : Range\033[0;m" << endl;
    int range2[] = {1, 2, 3, 4, 5, 6, 7};
    ft::vector<int> second(range2, range2 + 7);
    print_vector(second);
    cout << endl;
    ft::vector<int>::iterator j = second.begin() + 2;
    ft::vector<int>::iterator jt = second.erase(j, j + 2);
    print_vector(second);
	cout << *jt << endl << endl;
	ft::vector<int>::iterator jt2 = second.erase(second.begin() + 3, second.begin() + 5);
	print_vector(second);
	cout << *jt2 << endl << endl;
	ft::vector<int>::iterator jt3 = second.erase(second.begin(), second.begin());
	print_vector(second);
	cout << *jt3 << endl;
    cout << endl;
}

void test_push_back_vector(void)
{
    cout << "\033[1;34mPush Back Vector\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    print_vector(first);
    cout << endl;
    first.push_back(6);
    print_vector(first);
    cout << endl;
}

void test_pop_back_vector(void)
{
    cout << "\033[1;34mPop Back Vector\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    print_vector(first);
    cout << endl;
    first.pop_back();
    print_vector(first);
	ft::vector<int> second;
	second.pop_back();
    cout << endl;
}

void test_resize_vector(void)
{
    cout << "\033[1;34mResize Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    cout << "Size is " << first.size() << endl;
	print_vector(first);
	cout << endl;
    first.resize(6);
    cout << "Size is " << first.size() << endl;
	print_vector(first);
	cout << endl;
	first.resize(4);
	cout << "Size is " << first.size() << endl;
	print_vector(first);
    cout << endl;
}

void test_swap_vector(void)
{
    cout << "\033[1;34mSwap Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    ft::vector<int> second(4, 5);
    print_vector(first);
    cout << endl;
    print_vector(second);
    cout << endl << endl;
    first.swap(second);
    print_vector(first);
    cout << endl;
    print_vector(second);
    cout << endl;
}

void test_relational_equal_vector(void)
{
    cout << "\033[1;34mRelational == Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    ft::vector<int> second(3, 1);
    ft::vector<int> third(5, 1);
    ft::vector<int> fourth(3, 2);
    cout << (first == second) << endl;
    cout << (first == third) << endl;
    cout << (first == fourth) << endl;
    cout << endl;
}

void test_relational_non_equal_vector(void)
{
    cout << "\033[1;34mRelational != Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    ft::vector<int> second(3, 1);
    ft::vector<int> third(5, 1);
    ft::vector<int> fourth(3, 2);
    cout << (first != second) << endl;
    cout << (first != third) << endl;
    cout << (first != fourth) << endl;
    cout << endl;
}

void test_relational_less_vector(void)
{
    cout << "\033[1;34mRelational < Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    ft::vector<int> second(3, 1);
    ft::vector<int> third(5, 1);
    ft::vector<int> fourth(3, 2);
    cout << (first < second) << endl;
    cout << (first < third) << endl;
    cout << (first < fourth) << endl;
    cout << endl;
}

void test_relational_less_equal_vector(void)
{
    cout << "\033[1;34mRelational <= Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    ft::vector<int> second(3, 1);
    ft::vector<int> third(5, 1);
    ft::vector<int> fourth(3, 2);
    cout << (first <= second) << endl;
    cout << (first <= third) << endl;
    cout << (first <= fourth) << endl;
    cout << endl;
}

void test_relational_more_vector(void)
{
    cout << "\033[1;34mRelational > Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    ft::vector<int> second(3, 1);
    ft::vector<int> third(5, 1);
    ft::vector<int> fourth(3, 2);
    cout << (first > second) << endl;
    cout << (first > third) << endl;
    cout << (first > fourth) << endl;
    cout << endl;
}

void test_relational_more_equal_vector(void)
{
    cout << "\033[1;34mRelational >= Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    ft::vector<int> second(3, 1);
    ft::vector<int> third(5, 1);
    ft::vector<int> fourth(3, 2);
    cout << (first >= second) << endl;
    cout << (first >= third) << endl;
    cout << (first >= fourth) << endl;
    cout << endl;
}

void test_std_swap_vector(void)
{
    cout << "\033[1;34mstd::swap Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    ft::vector<int> second(5, 2);
    print_vector(first);
    cout << endl;
    print_vector(second);
    cout << endl << endl;
    swap(first, second);
    print_vector(first);
    cout << endl;
    print_vector(second);
    cout << endl;
}

void main_vector(void)
{
    cout << "\033[1;4;32mVECTOR STD\033[0;m" << endl << endl;
    test_constructor_vector();
    test_operator_equal_vector();
    test_assign_vector();
    test_get_allocator_vector();
    test_at_vector();
    test_operator_square_brackets_vector();
    test_front_vector();
    test_back_vector();
    test_data_vector();
    test_begin_vector();
    test_end_vector();
    test_rbegin_vector();
    test_rend_vector();
    test_empty_vector();
    test_size_vector();
    test_max_size_vector();
    test_capacity_vector();
    test_reserve_vector();
    test_clear_vector();
    test_insert_vector();
    test_erase_vector();
    test_push_back_vector();
    test_pop_back_vector();
    test_resize_vector();
    test_swap_vector();
    test_relational_equal_vector();
    test_relational_non_equal_vector();
    test_relational_less_vector();
    test_relational_less_equal_vector();
    test_relational_more_vector();
    test_relational_more_equal_vector();
    test_std_swap_vector();
}

//MAP

void print_map(ft::map<char, int> &m)
{
    cout << "{ ";
    for (ft::map<char, int>::iterator it = m.begin(); it != m.end(); it++)
        cout << "(" << it->first << ":" << it->second << ") ";
    cout << "}" << endl;
}

void test_constructor_map(void)
{
    cout << "\033[1;34mConstructor Map : Empty\033[0;m" << endl;
    ft::map<char, int> first;
    print_map(first);
    cout << endl;

    cout << "\033[1;34mConstructor Map : Compare and Allocator\033[0;m" << endl;
    allocator<int> alloc;
    ft::map<char, int> second(less<char>(), alloc);
    print_map(second);
    cout << endl;

    cout << "\033[1;34mConstructor Map : Range\033[0;m" << endl;
    first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
    first['d'] = 4;
    ft::map<char, int> third(first.begin(), first.end());
    print_map(third);
	first['a'] = 5;
	ft::map<char, int> third2(first.begin(), first.end());
	print_map(third2);
    cout << endl;

    cout << "\033[1;34mConstructor Map : Copy\033[0;m" << endl;
    ft::map<char, int> fourth(first);
    print_map(fourth);
		cout << endl;
}

void test_operator_equal_map(void)
{
    cout << "\033[1;34mOperator = Map\033[0;m" << endl;
    ft::map<char, int> first;
    first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
    ft::map<char, int> second;
    second = first;
    print_map(second);
	cout << endl;
}

// void test_get_allocator_map(void)
// {
//
// }

void test_at_map(void)
{
	cout << "\033[1;34mAt Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
	first['d'] = 4;
	cout << first.at('c') << endl;
	// cout << first.at('e') << endl;
	cout << endl;
}

void test_operator_square_brackets_map(void)
{
	cout << "\033[1;34mOperator [] Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
	first['d'] = 4;
	cout << first['b'] << endl;
	print_map(first);
	cout << first['e'] << endl;
	print_map(first);
	cout << endl;
}

void test_begin_map(void)
{
	cout << "\033[1;34mBegin Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
	first['d'] = 4;
	cout << first.begin()->second << endl;
	ft::map<char, int> second;
	if (second.begin() == second.end())
		cout << "Begin is good for empty map" << endl;
	cout << endl;
}

void test_end_map(void)
{
	cout << "\033[1;34mEnd Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
	first['d'] = 4;
	ft::map<char, int>::iterator it = first.begin();
	it++;
	it++;
	it++;
	it++;
	cout << (it == first.end()) << endl;
	cout << endl;
}

void test_rbegin_map(void)
{
	cout << "\033[1;34mRbegin Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
	first['d'] = 4;
	cout << first.rbegin()->second << endl;
	ft::map<char, int> second;
	if (second.rbegin() == second.rend())
		cout << "Rbegin is good for empty map" << endl;
	cout << endl;
}

void test_rend_map(void)
{
	cout << "\033[1;34mRend Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
	first['d'] = 4;
	ft::map<char, int>::reverse_iterator rit = first.rbegin();
	rit++;
	rit++;
	rit++;
	rit++;
	cout << (rit == first.rend()) << endl;
	cout << endl;
}

void test_empty_map(void)
{
	cout << "\033[1;34mEmpty Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
	first['d'] = 4;
	ft::map<char, int> second;
	cout << first.empty() << " " << second.empty() << endl;
	cout << endl;
}

void test_size_map(void)
{
	cout << "\033[1;34mSize Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
	first['d'] = 4;
	ft::map<char, int> second;
	cout << first.size() << " " << second.size() << endl;
	cout << endl;
}

void test_max_size_map(void)
{
	cout << "\033[1;34mMax Size Map\033[0;m" << endl;
	ft::map<char, int> first;
	cout << first.max_size() << endl;
	cout << endl;
}

void test_clear_map(void)
{
	cout << "\033[1;34mClear Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
	first['d'] = 4;
	print_map(first);
	cout << "Size of map is " << first.size() << endl;
	first.clear();
	print_map(first);
	cout << "Size of map is " << first.size() << endl;
	cout << endl;
}

void test_insert_map(void)
{
	cout << "\033[1;34mInsert Map : Value\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
    first['b'] = 2;
    first['c'] = 3;
	first['d'] = 4;
	print_map(first);
	cout << endl;
	ft::pair<char, int> p1('e', 5);
	ft::pair<ft::map<char, int>::iterator, bool> pr = first.insert(p1);
	print_map(first);
	cout << pr.first->second << " " << pr.second << endl;
	cout << endl;

	cout << "\033[1;34mInsert Map : Pos Value\033[0;m" << endl;
	ft::map<char, int> second;
	second['a'] = 1;
    second['b'] = 2;
    second['c'] = 3;
	second['d'] = 4;
	print_map(second);
	cout << endl;
	ft::map<char, int>::iterator it = second.begin();
	ft::pair<char, int> p2('f', 6);
	second.insert(it, p2);
	print_map(second);
	cout << endl;

	cout << "\033[1;34mInsert Map : Range\033[0;m" << endl;
	ft::map<char, int> third;
	third['a'] = 1;
    third['b'] = 2;
    third['c'] = 3;
	third['d'] = 4;
	print_map(third);
	cout << endl;
	ft::map<char, int> fourth;
	fourth['e'] = 5;
    fourth['f'] = 6;
    fourth['g'] = 7;
	fourth['a'] = 8;
	print_map(fourth);
	ft::map<char, int>::iterator it1 = fourth.begin();
	ft::map<char, int>::iterator it2 = fourth.end();
	third.insert(it1, it2);
	print_map(third);
	cout << endl;
}

void test_erase_map(void)
{
	cout << "\033[1;34mErase Map : Pos\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;
	print_map(first);
	ft::map<char, int>::iterator it = first.begin();
	first.erase(it);
	print_map(first);
	cout << endl;

	cout << "\033[1;34mErase Map : Range\033[0;m" << endl;
	ft::map<char, int> second;
	second['a'] = 1;
	second['b'] = 2;
	second['c'] = 3;
	second['d'] = 4;
	print_map(second);
	ft::map<char, int>::iterator it1 = second.begin();
	ft::map<char, int>::iterator it2 = second.end();
	second.erase(it1, it2);
	print_map(second);
	cout << endl;

	cout << "\033[1;34mErase Map : Key\033[0;m" << endl;
	ft::map<char, int> third;
	third['a'] = 1;
	third['b'] = 2;
	third['c'] = 3;
	third['d'] = 4;
	print_map(third);
	cout << third.erase('c') << " " << third.erase('e') << endl;
	print_map(third);
	cout << endl;
}

void test_swap_map(void)
{
	cout << "\033[1;34mSwap Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;
	ft::map<char, int> second;
	second['e'] = 5;
	second['f'] = 6;
	second['g'] = 7;
	second['h'] = 8;
	print_map(first);
	print_map(second);
	cout << endl;
	first.swap(second);
	print_map(first);
	print_map(second);
	cout << endl;
}

void test_count_map(void)
{
	cout << "\033[1;34mCount Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;
	cout << first.count('b') << " " << first.count('e') << endl;
	cout << endl;
}

void test_find_map(void)
{
	cout << "\033[1;34mFind Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;
	cout << first.find('c')->second << endl;
	cout << endl;
}

void test_equal_range_map(void)
{
	cout << "\033[1;34mEqual Range Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;
	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> p = first.equal_range('b');
	for (; p.first != p.second; (p.first)++)
		cout << p.first->second << endl;
	cout << endl;
}

void test_lower_bound_map(void)
{
	cout << "\033[1;34mLower Bound Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;
	ft::map<char, int>::iterator it = first.lower_bound('b');
	cout << it->second << endl;
	cout << endl;
}

void test_upper_bound_map(void)
{
	cout << "\033[1;34mLower Bound Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;
	ft::map<char, int>::iterator it = first.upper_bound('b');
	cout << it->second << endl;
	cout << endl;
}

void test_key_comp_map(void)
{
	cout << "\033[1;34mKey Comp Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;
	ft::map<char, int>::key_compare k_c = first.key_comp();
	bool before = k_c(first.begin()->second, 0); // 1 < 0
	bool after = k_c(0, first.begin()->second); // 0 < 1
	cout << before << " " << after << endl;
	cout << endl;
}

void test_value_comp_map(void)
{
	cout << "\033[1;34mValue Comp Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;
	ft::map<char, int>::value_compare v_c = first.value_comp();
	ft::pair<char, int> p1('a', 1);
	ft::pair<char, int> p2('b', 2);
	bool before = v_c(p1, p2); // 1 < 2
	bool after = v_c(p2, p1); // 2 < 1
	cout << before << " " << after << endl;
	cout << endl;
}

void test_relational_equal_map(void)
{
	cout << "\033[1;34mRelational == Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	ft::map<char, int> second;
	second['b'] = 2;
	ft::map<char, int> third;
	third['a'] = 1;
	cout << (first == second) << endl;
	cout << (first == third) << endl;
	cout << endl;
}

void test_relational_non_equal_map(void)
{
	cout << "\033[1;34mRelational != Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	ft::map<char, int> second;
	second['b'] = 2;
	ft::map<char, int> third;
	third['a'] = 1;
	cout << (first != second) << endl;
	cout << (first != third) << endl;
	cout << endl;
}

void test_relational_less_map(void)
{
	cout << "\033[1;34mRelational < Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	ft::map<char, int> second;
	second['b'] = 2;
	ft::map<char, int> third;
	third['a'] = 1;
	cout << (first < second) << endl;
	cout << (first < third) << endl;
	cout << endl;
}

void test_relational_less_equal_map(void)
{
	cout << "\033[1;34mRelational <= Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	ft::map<char, int> second;
	second['b'] = 2;
	ft::map<char, int> third;
	third['a'] = 1;
	cout << (first <= second) << endl;
	cout << (first <= third) << endl;
	cout << endl;
}

void test_relational_more_map(void)
{
	cout << "\033[1;34mRelational > Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	ft::map<char, int> second;
	second['b'] = 2;
	ft::map<char, int> third;
	third['a'] = 1;
	cout << (first > second) << endl;
	cout << (first > third) << endl;
	cout << endl;
}

void test_relational_more_equal_map(void)
{
	cout << "\033[1;34mRelational >= Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	ft::map<char, int> second;
	second['b'] = 2;
	ft::map<char, int> third;
	third['a'] = 1;
	cout << (first >= second) << endl;
	cout << (first >= third) << endl;
	cout << endl;
}

void test_std_swap_map(void)
{
	cout << "\033[1;34mstd::swap Map\033[0;m" << endl;
	ft::map<char, int> first;
	first['a'] = 1;
	first['b'] = 2;
	first['c'] = 3;
	first['d'] = 4;
	ft::map<char, int> second;
	second['e'] = 5;
	second['f'] = 6;
	second['g'] = 7;
	second['h'] = 8;
	print_map(first);
	print_map(second);
	cout << endl;
	swap(first, second);
	print_map(first);
	print_map(second);
	cout << endl;
}

void main_map(void)
{
    cout << "\033[1;4;32mMAP STD\033[0;m" << endl << endl;
    test_constructor_map();
    test_operator_equal_map();
    // test_get_allocator_map();
	test_at_map();
	test_operator_square_brackets_map();
	test_begin_map();
	test_end_map();
	test_rbegin_map();
	test_rend_map();
	test_empty_map();
	test_size_map();
	test_max_size_map();
	test_clear_map();
	test_insert_map();
	test_erase_map();
	test_swap_map();
	test_count_map();
	test_find_map();
	test_equal_range_map();
	test_lower_bound_map();
	test_upper_bound_map();
	test_key_comp_map();
	test_value_comp_map();
	test_relational_equal_map();
    test_relational_non_equal_map();
    test_relational_less_map();
    test_relational_less_equal_map();
    test_relational_more_map();
    test_relational_more_equal_map();
	test_std_swap_map();
}

//STACK

void print_stack(ft::stack<int> &st)
{
	while (st.empty() == 0)
    {
        cout << st.top() << endl;
		st.pop();
    }
}

void test_constructor_stack(void)
{
	cout << "\033[1;34mConstructor Stack : Empty\033[0;m" << endl;
	ft::stack<int> first;
	print_stack(first);
	cout << endl;

	cout << "\033[1;34mConstructor Stack : Other Stack\033[0;m" << endl;
	first.push(2);
	first.push(3);
	ft::stack<int> second(first);
	print_stack(second);
	cout << endl;
}

void test_operator_equal_stack(void)
{
	cout << "\033[1;34mOperator = Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	ft::stack<int> second;
	second = first;
	print_stack(first);
	cout << endl;
	print_stack(second);
	cout << endl;
}

void test_top_stack(void)
{
	cout << "\033[1;34mTop Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	cout << first.top() << endl;
	cout << endl;
}

void test_empty_stack(void)
{
	cout << "\033[1;34mEmpty Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	ft::stack<int> second;
	cout << first.empty() << " " << second.empty() << endl;
	cout << endl;
}

void test_size_stack(void)
{
	cout << "\033[1;34mSize Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	cout << first.size() << endl;
	cout << endl;
}

void test_push_stack(void)
{
	cout << "\033[1;34mPush Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	print_stack(first);
	cout << endl;
}

void test_pop_stack(void)
{
	cout << "\033[1;34mPop Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	first.push(4);
	first.pop();
	print_stack(first);
	cout << endl;
}

void test_relational_equal_stack(void)
{
	cout << "\033[1;34mRelational == Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	ft::stack<int> second;
	second.push(1);
	second.push(2);
	ft::stack<int> third;
	third.push(2);
	third.push(3);
	cout << (first == second) << endl;
	cout << (first == third) << endl;
	cout << endl;
}

void test_relational_non_equal_stack(void)
{
	cout << "\033[1;34mRelational != Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	ft::stack<int> second;
	second.push(1);
	second.push(2);
	ft::stack<int> third;
	third.push(2);
	third.push(3);
	cout << (first != second) << endl;
	cout << (first != third) << endl;
	cout << endl;
}

void test_relational_less_stack(void)
{
	cout << "\033[1;34mRelational < Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	ft::stack<int> second;
	second.push(1);
	second.push(2);
	ft::stack<int> third;
	third.push(2);
	third.push(3);
	cout << (first < second) << endl;
	cout << (first < third) << endl;
	cout << endl;
}

void test_relational_less_equal_stack(void)
{
	cout << "\033[1;34mRelational <= Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	ft::stack<int> second;
	second.push(1);
	second.push(2);
	ft::stack<int> third;
	third.push(2);
	third.push(3);
	cout << (first <= second) << endl;
	cout << (first <= third) << endl;
	cout << endl;
}

void test_relational_more_stack(void)
{
	cout << "\033[1;34mRelational > Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	ft::stack<int> second;
	second.push(1);
	second.push(2);
	ft::stack<int> third;
	third.push(2);
	third.push(3);
	cout << (first > second) << endl;
	cout << (first > third) << endl;
	cout << endl;
}

void test_relational_more_equal_stack(void)
{
	cout << "\033[1;34mRelational >= Stack\033[0;m" << endl;
	ft::stack<int> first;
	first.push(2);
	first.push(3);
	ft::stack<int> second;
	second.push(1);
	second.push(2);
	ft::stack<int> third;
	third.push(2);
	third.push(3);
	cout << (first >= second) << endl;
	cout << (first >= third) << endl;
	cout << endl;
}

void main_stack(void)
{
	cout << "\033[1;4;32mSTACK STD\033[0;m" << endl << endl;
	test_constructor_stack();
	test_operator_equal_stack();
	test_top_stack();
	test_empty_stack();
	test_size_stack();
	test_push_stack();
	test_pop_stack();
	test_relational_equal_stack();
    test_relational_non_equal_stack();
    test_relational_less_stack();
    test_relational_less_equal_stack();
    test_relational_more_stack();
    test_relational_more_equal_stack();
}

int main(void)
{
    main_vector();
    main_map();
    main_stack();
}
