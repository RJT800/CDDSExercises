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

	//LinkedList<int> list1 = LinkedList<int>();
	//LinkedList<int> list2 = LinkedList<int>();


	//list1.pushBack(1);
	//list1.pushBack(2);
	//list1.insert(3, 2);

	//list1.pushFront(0);
	//LinkedList<int> list3 = LinkedList<int>(list1);

	//Iterator<int> 

	//list1.remove(3);
	//list1.pushBack(4);

	//if (list1.contains(5))
	//	std::cout << 'd' << std::endl;

	////list1.destroy();
	//list2 = list1;
	//list1.print();
	//list2.print();
	//list3.print();

	//int uh = list1.first();

	//std::cout << uh << std::endl;
	DynamicArray<int> nums = DynamicArray<int>();

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
	wards.print();
	std::cout << add(45, 33) << std::endl;

}