#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
template<typename AnyType>
AnyType add(AnyType a, AnyType b)
{
	return a + b;
}

int main()
{

	LinkedList<int> listy = LinkedList<int>();


	listy.pushBack(1);
	listy.print();



	/*DynamicArray<int> nums = DynamicArray<int>();

	nums.addItem(2);
	nums.addItem(3);
	nums.addItem(1);
	nums.addItem(8);
	nums.addItem(6);
	nums.addItem(0);

	nums.print();
	DynamicArray<char> wards = DynamicArray<char>();
	
	wards.addItem('l');
	wards.addItem('o');
	wards.addItem('d');
	wards.addItem('i');
	wards.addItem('s');
	wards.print();*/
	//std::cout << add(45, 33) << std::endl;

}