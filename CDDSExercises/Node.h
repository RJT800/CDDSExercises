#pragma once
#include <iostream>

template <typename AnyType>
struct Node
{
public:
	Node<AnyType>();
	Node<AnyType>(AnyType value);
	Node<AnyType>* next;
	Node<AnyType>* previous;
	AnyType data;
};

//function defintions
template <typename AnyType>
inline Node<AnyType>::Node()
{
	next = nullptr;
	previous = nullptr;
}

template <typename AnyType>
inline Node<AnyType>::Node(AnyType value)
{
	next = nullptr;
	previous = nullptr;
	data = value;
}
