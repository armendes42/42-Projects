/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:41:07 by armendes          #+#    #+#             */
/*   Updated: 2022/11/25 01:28:59 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <string>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"

using namespace std;

template <typename T>
void print_vector(const ft::vector<T> &vec)
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
    cout << endl;
    
    cout << "\033[1;34mConstructor Vector: Copy\033[0;m" << endl;
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
    cout << endl;
}

void test_operator_square_brackets_vector(void)
{
    cout << "\033[1;34mOperator [] Vector\033[0;m" << endl;
    int range[] = {5, 4, 3, 2, 1};
    ft::vector<int> first(range, range + 5);
    for (size_t i = 0; i < 5; i++)
        cout << first[i] << endl;
    cout << endl;
}

void test_front_vector(void)
{
    cout << "\033[1;34mFront Vector\033[0;m" << endl;
    int range[] = {2, 3, 5, 6, 8, 9};
    ft::vector<int> first(range, range + 6);
    cout << first.front() << endl;
    cout << endl;
}

void test_back_vector(void)
{
    cout << "\033[1;34mBack Vector\033[0;m" << endl;
    int range[] = {2, 3, 5, 6, 8, 9};
    ft::vector<int> first(range, range + 6);
    cout << first.back() << endl;
    cout << endl;
}

void test_data_vector(void)
{
    cout << "\033[1;34mData Vector\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    int *p = first.data();
    for (int i = 0; i < 5; i++)
        cout << p[i] << endl;
    cout << endl;
}

void test_begin_vector(void)
{
    cout << "\033[1;34mBegin Vector\033[0;m" << endl;
    int range[] = {1, 2, 3, 4, 5};
    ft::vector<int> first(range, range + 5);
    cout << *first.begin() << endl;
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
    cout << endl;
}

void test_clear_vector(void)
{
    cout << "\033[1;34mClear Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    print_vector(first);
    cout << "Size of vector is " << first.size() << endl;
    first.clear();
    print_vector(first);
    cout << "size of vector is " << first.size() << endl;
    cout << endl;
}

void test_insert_vector(void)
{
    cout << "\033[1;34mInsert Vector : Pos value\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    print_vector(first);
    cout << endl;
    ft::vector<int>::iterator i = first.begin() + 2;
    first.insert(i, 2);
    print_vector(first);
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
    first.erase(i);
    print_vector(first);
    cout << endl << endl;

    cout << "\033[1;34mErase Vector : Range\033[0;m" << endl;
    int range2[] = {1, 2, 3, 4, 5, 6, 7};
    ft::vector<int> second(range2, range2 + 7);
    print_vector(second);
    cout << endl;
    ft::vector<int>::iterator j = second.begin() + 2;
    second.erase(j, j + 2);
    print_vector(second);
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
    cout << endl;
}

void test_resize_vector(void)
{
    cout << "\033[1;34mResize Vector\033[0;m" << endl;
    ft::vector<int> first(3, 1);
    cout << "Size is " << first.size() << endl;
    first.resize(6);
    cout << "Size is " << first.size() << endl;
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

// void test_constructor_map(void)
// {
//     cout << "\033[1;34mConstructor Map : Empty\033[0;m" << endl;
//     map<int, int> first;
// }

// void main_map(void)
// {
//     cout << "\033[1;4;32mMAP STD\033[0;m" << endl << endl;
//     test_constructor_map();
// }

//STACK

// void main_stack(void)
// {
    
// }

int main(void)
{
    main_vector();
    // main_map();
    // main_stack();
}