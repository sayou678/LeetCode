//SLL

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Node
{
	char *str;
	struct Node *next;
}node;

typedef struct List
{
	node *head;
}list;

list * createList()
{
	list *lst = (list *)malloc(sizeof(list));
	assert(lst != NULL);
	lst->head = NULL;
	return lst;
}

void destroyList()
{

}

void addList(list *pList, char *str)
{
	node *n = NULL;
	assert(pList != NULL);

	n = (node *)malloc(sizeof(node));
	assert(n != NULL);

	if (pList->head == NULL)
	{
		pList->head = n;
		n->next = NULL;
	}
	else
	{
		n->next = pList->head;
		pList->head = n;
	}
}

int compare(char *str1, char *str2)
{
	return 0;
}

void sort(list *pList)
{

}

void dumpList(list *pList)
{
	node *p = NULL;
	if (pList == NULL && pList->head == NULL)
	{
		return;
	}

	p = pList->head;
	
	while(p != NULL)
	{
		printf("%s\n", p->str);
		p = p->next;
	}
}

void test99()
{
	char *strList[] = {"Hello world", "apple", "food", "car", "house", "foot", "cup"};

	int i = 0;
	list *lst = createList();
	assert(lst);

	for (i = 0; i < sizeof(strList); i++)
	{
		addList(lst, strList[i]);
	}

	dumpList(lst);

    printf("%s", "Hello world");
}
