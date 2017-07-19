#include <iostream>
#include "List.h"
#include "BinaryTree.h"
#include "Stack.h"

bool  unitTest()
{

/*************************************************************************************
**************************************************************************************
								Push Back test
**************************************************************************************
**************************************************************************************/
	List<int> L1;

	L1.pushBack(1);
	L1.pushBack(2);
	L1.pushBack(3);
	L1.pushBack(4);
	L1.pushBack(5);

	List<int>::Iterator It1;
	int i = 1;
	for (It1 = L1.begin(); It1 != L1.end(); It1++)
	{
	
		     if (*It1 != i)
			{
				std::cout << "The list did not push back properly" << std::endl;
				return false;
		}
			 i++;
	}

	if (L1.getSize() != 5)
	{
		std::cout << "Size of list for push back test is not correct" << std::endl;;
		return false;
	}

/*************************************************************************************
**************************************************************************************
								Push Front test
**************************************************************************************
**************************************************************************************/
	List<int> L2;

	L2.pushFront(1);
	L2.pushFront(2);
	L2.pushFront(3);
	L2.pushFront(4);
	L2.pushFront(5);

	int j = 5;
	for (It1 = L2.begin(); It1 != L2.end(); It1++)
	{

		if (*It1 != j)
		{
			std::cout << "The list did not push front properly" << std::endl;
			return false;
		}
		j--;
	}

	if (L2.getSize() != 5)
	{
		std::cout << "Size of list for push front test is not correct" << std::endl;;
		return false;
	}


/*************************************************************************************
**************************************************************************************
								insert after test (List)
**************************************************************************************
**************************************************************************************/
	List<int> L3;
	L3.pushBack(1);
	L3.pushBack(2);
	L3.pushBack(3);
	L3.pushBack(4);
	L3.pushBack(5);


	List<int>::Iterator It3 = L3.begin();

	L3.insert(5, 26);

	It3 += (6);

	if ( *It3 != 26)
	{
		std::cout << "Did not insert after properly" << std::endl;
		return false;
	}

	if (L3.getSize() != 6)
	{
		std::cout << "Size of list for insert after test is not correct" << std::endl;;
		return false;
	}



/*************************************************************************************
**************************************************************************************
					insert before test (List)
**************************************************************************************
**************************************************************************************/
	List<int> L4;
	L4.pushBack(1);
	L4.pushBack(2);
	L4.pushBack(3);
	L4.pushBack(4);
	L4.pushBack(5);


	List<int>::Iterator It4 = L4.begin();

	L4.insert(3, 26);

	It4 += (3);

	if (*It4 != 26)
	{
		std::cout << "Did not insert before properly" << std::endl;
		return false;
	}

	if (L4.getSize() != 6)
	{
		std::cout << "Size of list for insert before test is not correct" << std::endl;;
		return false;
	}



/*************************************************************************************
**************************************************************************************
						pop Back test
**************************************************************************************
**************************************************************************************/

	List<int> L5;
	L5.pushBack(1);
	L5.pushBack(2);
	L5.pushBack(3);
	L5.pushBack(4);
	L5.pushBack(5);


	L5.popBack();

	List<int>::Iterator It5 = L5.begin();

	int k = 1;

	for (It5 = L5.begin(); It5 != L5.end(); It5++)
	{

		if (*It5 != k)
		{
			std::cout << "The list did not pop back properly" << std::endl;
			return false;
		}
		k++;
	}

	if (L5.getSize() != 4)
	{
		std::cout << "Size of list for pop Back test is not correct" << std::endl;;
		return false;
	}


/*************************************************************************************
**************************************************************************************
								pop Front test
**************************************************************************************
**************************************************************************************/

	List<int> L6;
	L6.pushBack(1);
	L6.pushBack(2);
	L6.pushBack(3);
	L6.pushBack(4);
	L6.pushBack(5);


	L6.popFront();

	List<int>::Iterator It6 = L6.begin();

	int l = 2;

	for (It6 = L6.begin(); It6 != L6.end(); It6++)
	{

		if (*It6 != l)
		{
			std::cout << "The list did not pop front properly" << std::endl;
			return false;
		}
		l++;
	}

	if (L6.getSize() != 4)
	{
		std::cout << "Size of list for pop Front test is not correct" << std::endl;;
		return false;
	}

	

/*************************************************************************************
**************************************************************************************
							Delete List test
**************************************************************************************
**************************************************************************************/
	
	List<int> L7;
	L7.pushBack(1);
	L7.pushBack(2);
	L7.pushBack(3);
	L7.pushBack(4);
	L7.pushBack(5);
	
	L7.deleteList();

	List<int>::Iterator It7 = L7.begin();

	for (It7 = L7.begin(); It7 != L7.end(); It7++)
	{

	
		
		std::cout << "Delete whole list didn't work properly" << std::endl;
			return false;
	
	}

	if (L7.getSize() != 0)
	{
		std::cout << "Size of list for Delete List test is not correct" << std::endl;;
		return false;
	}

/*************************************************************************************
**************************************************************************************
							Delete position test (List)
**************************************************************************************
**************************************************************************************/


	List<int> L8;
	L8.pushBack(1);
	L8.pushBack(2);
	L8.pushBack(3);
	L8.pushBack(4);
	L8.pushBack(5);


	L8.deletePosition(3);

	List<int>::Iterator It8 = L8.begin();


	It8 += (3);

	if (*It8 != 4)
	{
		std::cout << "Did not delete position properly" << std::endl;
		return false;
	}

	if (L8.getSize() != 4)
	{
		std::cout << "Size of list for Delete position test is not correct" << std::endl;;
		return false;
	}


/*************************************************************************************
**************************************************************************************
					Insert Key and Value into Binary Tree 
**************************************************************************************
**************************************************************************************/
	BinaryTree<int, int> T;

	T.insert(1, 1);
	T.insert(2, 2);
	T.insert(3, 3);
	T.insert(4, 4);
	T.insert(5, 5);


	for (int i = 1; i <= 5; i++)
	{
		
		if (T.Search(i) != i )
		{
			std::cout << "Didn't Insert properly " << std::endl;
			return false;
		}
	}

	if (T.getLeafNum() != 5)
	{
		std::cout << "Wrong Binary Tree size after inserting" << std::endl;
		return false;
	}

/*************************************************************************************
**************************************************************************************
					Search through the binary tree
**************************************************************************************
**************************************************************************************/

	if (T.Search(4) != 4)
	{
		std::cout << "Didn't Search properly " << std::endl;
		return false;

	}


/*************************************************************************************
**************************************************************************************
						Delete Binary Tree
**************************************************************************************
**************************************************************************************/
	


	T.deleteTree();

	if (T.getLeafNum() != 0)
	{
		std::cout << "Wrong Binary Tree size after deleting therefore didnt delete properly " << std::endl;
		return false;
	}

	/*
	Insert 
	Delete 
	search 
	*/


	Stack<int> stack;
	stack.push(3);
	stack.push(4);
	stack.push(6);
	stack.push(8);

	return true;
}

int main()
{
	int foo;
	foo = -1;

	if (unitTest())
	{
		std::cout << " All tests passed successfully" << std::endl;
	}
	else 
	{
		std::cout << "Test Failed" << std::endl;
	}
	system("pause");
	return 0;

}