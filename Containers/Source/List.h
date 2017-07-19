#pragma once
#include <iostream>
#include "Exception.h"

template<class T>
class List
{
private:

	class ListNode
	{
	public:
		/*
		Listnode Constructor sets the next and previous pointers to nullptr to make sure they arnt pointing to garbage
		no returns
		*/
		ListNode()
		{
			Next = nullptr;
			Previous = nullptr;
		}

		/*
		List Node Copy Constructor creates a new objects when the list node is created
		@param newobj the object being created
		no returns
		*/
		ListNode(T newobj)
		{
			Next = nullptr;
			Previous = nullptr;
			obj = newobj;
		}

		~ListNode()
		{
		}

		/*
		Pointers pointing to the next and previous objects in the list.
		*/
		ListNode * Next;
		ListNode * Previous;
		T obj;

	};

	/*
	The first and last objects of the list
	*/
	ListNode * m_first;
	ListNode * m_last;


	//Number of elements in the list
	float m_eleNum = 0;


public:
	class Iterator
	{
	public:
		Iterator() {};

		/*
		Iterator copy Constructor creates copy iterator
		@param other another iterator
		no returns
		*/
		Iterator(const Iterator & other) { ptr = other.ptr; };

		~Iterator() {};

		ListNode * ptr;

		/*
		++ operator overloader for going to the next object in the list (ptr++)
		no returns
		*/
		void operator++(int) { ptr = ptr->Next; };

		/*
		++ operator overloader for going to the next object in the list (++ptr)
		no returns
		*/
		void operator++() { ptr = ptr->Next; };


		/*
		-- operator overloader for going to the previous object in the list (--ptr)
		no returns
		*/
		void operator--() { ptr = ptr->Previous; };

		/*
		-- operator overloader for going to the previous object in the list (ptr--)
		no returns
		*/
		void operator--(int) { ptr = ptr->Previous; };

		/*
		+= operator overloader for going to the previous object in the list (--ptr)
		no returns
		*/
		void operator+=(int position)
		{
			for (int i = 1; i < position; i++)
			{
				ptr = ptr->Next;
			}
		};

		/*
		!= operator overloader for checking whether two iterators dont equal
		returns false
		*/
		bool operator!=(const Iterator & other) { return ptr != other.ptr; };

		/*
		== operator overloader for checking whether two iterators equal
		returns true
		*/
		bool operator==(const Iterator & other) { return ptr == other.ptr; };

		/*
		= operator overloader for asigning two iterators
		returns iterator
		*/
		Iterator &operator=(const Iterator & other) { ptr = other.ptr; return *this; };

		/*
		-> operator overloader for pointing to objects
		returns object pointed to
		*/
		T *operator ->()
		{
			return &ptr->obj;
		};

		/*
		-> operator overloader for pointing to objects (const correct version)
		returns object pointed to
		*/
		const Iterator *operator ->()const
		{

			return *this;
		}

		/*
		* operator overloader for pointing to and object 
		returns object
		*/
		T &operator*() { return ptr->obj; };

	};

	/*
	Iterator end function that gets the end of the list
	returns nullptr
	*/
	Iterator end()
	{
		Iterator temp;
		temp.ptr = nullptr;
		return temp;
	};

	/*
	Iterator begin function that gets the beginning of the list
	returns the first node
	*/
	Iterator begin()
	{
		Iterator temp;
		temp.ptr = m_first;
		return temp;
	};

	/*
	get size function gets how many elements in the list 
	returns nullptr
	*/
	float getSize() { return m_eleNum; };

	List() {};
	~List() {};

	/*
	puts an elemement in the start of the list	
	@param value the object being put into the list
	no returns
	*/
	void pushFront(const T  value);
	
	/*
	puts an elemement in the back of the list
	@param value the object being put into the list
	no returns
	*/
	void pushBack(const T  value);
	
	/*
	puts an elemement in the start of the list
	@param value the object being put into the list 
	@param element where in the list to put the object
	no returns
	*/
	void insert(int element, const T & value);
	
	/*
	deletes the first element in the list
	no returns
	*/
	void popFront();

	/*
	deletes the last element in the list
	no returns
	*/
	void popBack();

	/*
	deletes the list
	no returns
	*/
	void deleteList();
	
	/*
	deletes a specific position in the list
	@param position what position in the list you want to delete
	no returns
	*/
	void deletePosition(float position);

	/*
	gets the last element in the list
	returns the last object in the list
	*/
	T& last();
};

template<class T>
inline void List<T>::pushFront(const T value)
{
	if (m_eleNum < 0)
	{
		exceptTHROW("The number of elements in tree is a negative");
	}

	if (m_eleNum == 0)
	{
		m_first = new ListNode(value);
		m_last = m_first;
	}
	else
	{
		ListNode * N = new ListNode();

		N->Previous = nullptr;

		N->Next = m_first;

		m_first->Previous = N;

		m_first = N;

		m_first->obj = value;
	}
	m_eleNum++;
}

template<class T>
inline void List<T>::pushBack(const T value)
{
	if (m_eleNum < 0)
	{
		exceptTHROW("The number of elements in tree is a negative");
	}

	if (m_eleNum == 0)
	{
		m_last = new ListNode(value);
		m_first = m_last;
	}
	else
	{
		ListNode * N = new ListNode();

		N->Next = nullptr;

		N->Previous = m_last;

		m_last->Next = N;

		m_last = N;

		m_last->obj = value;
	}

	m_eleNum++;
}

template<class T>
inline void List<T>::popFront()
{
	if (m_eleNum <= 0)
	{
		exceptTHROW("Tried to delete a node or list that didnt exist");
	}

	if (m_eleNum == 1)
	{
		deleteList();

	}
	else
	{

		ListNode * holder = m_first->Next;

		delete m_first;

		holder->Previous = nullptr;

		m_first = holder;

		m_eleNum--;
	}

}

template<class T>
inline void List<T>::popBack()
{
	if (m_eleNum <= 0)
	{
		exceptTHROW("Tried to delete a node or list that didnt exist");
	}

	if (m_eleNum == 1)
	{
		deleteList();

	}
	else
	{

		ListNode * holder = m_last->Previous;

		delete m_last;

		holder->Next = nullptr;

		m_last = holder;

		m_eleNum--;
	}
}

template<class T>
inline void List<T>::insert(int element, const T & value)
{
	if (element < 0 || element > m_eleNum)
	{
		exceptTHROW("Trying to insert outside the boundries of the list");
	}

	if (element == 0)
	{
		pushFront(value);
	}
	else if (element == m_eleNum)
	{
		pushBack(value);
	}
	else
	{

		List<T>::Iterator holder = begin();

		holder += (element);

		ListNode * N = new ListNode();

		N->Next = (holder.ptr);
		N->Previous = holder.ptr->Previous;

		(holder.ptr)->Previous->Next = N;

		//(holder.ptr)->Next = N;

		N->obj = value;

		m_eleNum++;
	}

}

template<class T>
inline void List<T>::deleteList()
{
	if (m_eleNum < 0)
	{
		exceptTHROW("Trying to delete a list that doesnt exist");
	}
	int listDel = 0;
	ListNode * Start = m_first;

	for (int i = 0; i < m_eleNum; i++)
	{
		m_first = m_first->Next;

		delete Start;

		Start = m_first;
		listDel++;
	}
	m_eleNum = m_eleNum - listDel;
	m_first = nullptr;

	m_last = nullptr;

}

template<class T>
inline void List<T>::deletePosition(float position)
{

	if (position < 0 || position > m_eleNum)
	{
		exceptTHROW("Trying to delete outside the boundries of the list");
	}

	if (position == 0)
	{
		popFront();
	}
	else if (position == m_eleNum)
	{
		popBack();
	}

	else
	{

		List<T>::Iterator holder = begin();

		holder += (position);

		(holder.ptr)->Next->Previous = (holder.ptr)->Previous;

		(holder.ptr)->Previous->Next = (holder.ptr)->Next;

		delete holder.ptr;

		m_eleNum--;

	}
}

template<class T>
inline T & List<T>::last()
{
	if (m_eleNum < 0)
	{
		exceptTHROW("Trying to get the last element of a list that doesnt exist");
	}
	return m_last->obj;
}


