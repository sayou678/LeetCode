//SLL

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

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
    
    n->str = (char *)malloc(strlen(str) +1);
    strcpy(n->str, str);

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
    while(*str1 != '\0' && *str2 != '\0')
    {
        if(*str1 > *str2)
        {
            return 1;
        }
        else if(*str1 < *str2)
        {
            return -1;
        }
        else
        {
            str1++;
            str2++;
        }
    }

    if(*str1 == '\0' && str2 == '\0')
    {
        return 0;
    }
    else if(*str1 == '\0') 
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
void dumpList(list *pList);
void sort(list *pList)
{
    
    node *p = NULL, *q = NULL;
 
     assert(pList != NULL);
     p = pList->head;
 
     if(p == NULL)
         return;
 
     for(; q != pList->head; )
     {
         node *preP = pList->head;
         for(p = pList->head; p->next != q; )
         {
             if(compare(p->str, p->next->str) > 0)
             {
                node *pNext = NULL;
                 // swap p and p->next
                 if(p == pList->head)
                 {
                     pNext = p->next;
                     pList->head = pNext;
                     p->next = pNext->next;
                     pNext->next = p;
                 }
                 else
                 {
                     pNext = p->next;
                     preP->next = pNext;
                     p->next = pNext->next;
                     pNext->next = p;
                 }
                preP = pNext;
             }
             else
             {
                preP = p;
                p = p->next;
             }
            dumpList(pList);
         }
         q = p; 
     }
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

    printf("dump complete.\n\n");
}

void test99()
{
	char *strList[] = {"Hello world", "foodZZZZ", "apple", "food", "car", "house", "food", "foot", "cup"};

	int i = 0;
	list *lst = createList();
	assert(lst);

	for (i = 0; i < sizeof(strList)/sizeof(char *); i++)
	{
		addList(lst, strList[i]);
	}

	dumpList(lst);

    sort(lst);

    printf("\nsorting...\n");
    dumpList(lst);
}
