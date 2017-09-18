// test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// C++ program to find maximum rectangular area in linear time
#include<iostream>
#include<stack>

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
#include <queue>
#include <sstream>
#include <list>
#include <assert.h>
using namespace std;

 

#include <94. Binary Tree Inorder Traversal\cpp94.cpp>

void test94()
{
	string line = "[1,2,4,8,null,null,null,5,null,9,3,6,null,10,7,null]";
	//string line = "[1,null,2,3]";


	TreeNode* root = stringToTreeNode(line);

	vector<int> ret = Solution().inorderTraversal(root);
	string out = integerVectorToString(ret);
	cout << out << endl;	

	ret = Solution().preorderTraversal(root);
	out = integerVectorToString(ret);
	cout << out << endl;	

	ret = Solution().postorderTraversal(root);
	out = integerVectorToString(ret);
	cout << out << endl;	
}

typedef int BOOL;

typedef struct sNode
{
	int val;
	struct sNode *next;
	struct sNode *pre;
}Node;

typedef struct sList
{
	Node *head;
	unsigned size;
}List;

List * CreateList()
{
	List *list = (List *)malloc(sizeof(List));
	assert(list != NULL);

	list->head = NULL;
	list->size = 0;

	return list;
}

void PushBack(List *list, int val)
{
	if (list == NULL)
	{
		return;
	}

	Node *node = (Node *)malloc(sizeof(Node));
	if (node == NULL)
	{
		return;
	}
	node->val = val;

	if (list->head == NULL)
	{
		list->head = node;
		list->head->next = node;
		list->head->pre = node;
	}
	else
	{
		list->head->pre->next = node;
		node->next = list->head;
		node->pre = list->head->pre;
		list->head->pre = node;
	}

	list->size++;
}

void PushFront(List *list, int val)
{
	if (list == NULL)
	{ 
		return;
	}

	Node *node = (Node *)malloc(sizeof(Node));
	if (node == NULL)
	{
		return;
	}
	node->val = val;

	if (list->head == NULL)
	{
		list->head = node;
		list->head->next = node;
		list->head->pre = node;
	}
	else
	{
		list->head->pre->next = node;
		node->next = list->head;
		node->pre = list->head->pre;
		list->head->pre = node;

		list->head = node;
	}

	list->size++;
}

int Back(List *list)
{
	assert(list != NULL && list->head != NULL);
	return list->head->pre->val;
}

int Front(List *list)
{
	assert(list != NULL && list->head != NULL);
	return list->head->val;
}

void PopBack(List *list)
{

}

void PopFront(List *list)
{

}

void DestroyList(List *list)
{

}

void Dump(List *list)
{
	assert(list != NULL);

	if (list->size == 0)
	{
		return;
	}

	Node *p = list->head;
	do
	{
		cout << p->val << ", ";
		p = p->next;
	}
	while (p != list->head);
}


void test1()
{
	List *list = CreateList();
	PushBack(list, 1);
	PushBack(list, 3);
	PushBack(list, 4);
	PushFront(list, 2);
	PushFront(list, 5);

	Dump(list);
}

extern "C"
{
	void test99();
};

int _tmain(int argc, _TCHAR* argv[])
{
	
   test99();

	return 0;
}

