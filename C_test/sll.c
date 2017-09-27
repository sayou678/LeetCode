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

}

void test99()
{
	char *strList[] = {"Hello world", "apple", "food", "car", "house", "foot", "cup"};

	list *lst = createList();
	assert(0);

	printf("hello\n");

    printf("%s", "Hello world");

}
