#pragma once
#include <iostream>
#include "Iterator.h"

template<typename AnyType>
class LinkedList
{
public:
	LinkedList();
	//LinkedList(const LinkedList<AnyType>& other);
	//~LinkedList();

	//void destroy();

	Iterator<AnyType> begin() const;
	Iterator<AnyType> end()const;

	//AnyType first()const;
	//AnyType last()const;

	//bool contains(const AnyType value)const;

	void pushFront(const AnyType& value);
	void pushBack(const AnyType& value);

	AnyType popFront();
	AnyType popBack();

	bool insert(const AnyType& value, int index);
	bool remove(const AnyType& value);

	void print() const;

	//void initilaize();
	//bool isEmpty()const;

	//bool getData(Iterator<AnyType>& iter, int index);

	//int getLength() const;

	//void operator = (const LinkedList<AnyType>& otherLinkedList);

	//void sort();

private:
	Node <AnyType>* m_first;
	Node <AnyType>* m_last;

	int m_nodeCount;
};

template<typename AnyType>
inline LinkedList<AnyType>::LinkedList()
{
	m_first = nullptr;
	m_last = nullptr;
}


template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::begin() const
{
	return Iterator<AnyType>(m_first);
}


template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::end() const
{
	if (m_last)
		return Iterator<AnyType>(m_last->next);

	return Iterator<AnyType>(nullptr);
}


template<typename AnyType>
inline void LinkedList<AnyType>::print() const
{
	for (Iterator<AnyType> iter = begin(); iter != end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}






template<typename AnyType>
inline void LinkedList<AnyType>::pushBack(const AnyType& value)
{
	//create an new node to put the valuein
	Node<AnyType>* newNode = new Node<AnyType>(value);
	// update thenode count to incluide the new node.
	m_nodeCount++;
	//if the last noe is null that must mean the list is empty...
	if (!m_last)
	{
		//... so set the new node to be the first and last
		m_last = newNode;
		m_first = newNode;
		return;
	}

	//set the last nodes next to be the new node.
	m_last->next = newNode;
	//tell tehe new node toset its previous to the old last node
	newNode->previous = m_last;
	//Mark the new node as being the last node.
	m_last = newNode;
}






template<typename AnyType>
inline void LinkedList<AnyType>::pushFront(const AnyType& value)
{
	//create an new node to put the valuein
	Node<AnyType>* newNode = new Node<AnyType>(value);
	// update thenode count to incluide the new node.
	m_nodeCount++;
	//if the last noe is null that must mean the list is empty...
	if (!m_first)
	{
		//... so set the new node to be the first and last
		m_last = newNode;
		m_first = newNode;
		return;
	}

	//set the last nodes next to be the new node.
	m_first->previous = newNode;
	//tell tehe new node toset its previous to the old last node
	newNode->next = m_first;
	//Mark the new node as being the last node.
	m_first = newNode;
}


template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	//check if the index is within the bounds of the list
	if (index < 0 || index >= m_nodeCount)
		return false;

	// if the list is empty...
	if (m_nodeCount == 0)
	{
		//...reuse the logic from the pushback to add it to the list.
		pushBack(value);
		return true;
	}


	if (index == 0)
	{
		pushFront(value);

		return true;
	}

	Node<AnyType>* newNode = new Node<AnyType>(value);
	Node<AnyType>* iter = m_first;

	for (int i = 0; i < index; i++)
	{
		if (iter->next == nullptr)
			break;

		iter = iter->next;
	}
	//the iter looks at the target node
	newNode->next = iter;
	newNode->previous = iter->previous;
	newNode->previous->next = newNode;
	iter->previous = newNode;

	return true;
}

template<typename AnyType>
inline bool LinkedList<AnyType>::remove(const AnyType& value)
{
	Node<AnyType>* iter = m_first;

	for (int i = 0; i < m_nodeCount; i++)
	{
		if (iter == nullptr)
			return false;

		if (iter->data == value)
			break;

		iter = iter->next;
	}


	if (iter == m_last)
	{
		popBack();
		return true;
	}
	else if (iter == m_first)
	{
		popFront();
		return true;
	}
	m_nodeCount--;

	iter->next->previous = iter->previous;
	iter->previous->next = iter->next;


	delete iter;
	return true;
}



template<typename AnyType>
inline AnyType LinkedList<AnyType>::popFront()
{
	if (m_nodeCount == 0)
	return AnyType();

	AnyType value = m_first->data;

	if (m_first->previous)
	{
		delete m_first->previous;
		m_first = m_first->next;
	}

	return value;
}

template<typename AnyType>
inline AnyType LinkedList<AnyType>::popBack()
{

	if (m_nodeCount == 0)
	return AnyType();

	AnyType value = m_last->data;

	m_last = m_last->previous;

	if (m_last->next)
	{
		m_last = m_last->next;
	}
	m_last->next = nullptr;

	return true;
}