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
    while(*str1 != '\0' && str2 != '\0')
    {
        if(*str1 != *str2)
        {
            return *str1 < *str2;
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
    else
    {
        return *str1 == '\0';
    }
}

void sort(list *pList)
{
    
    node *p = NULL, *q = NULL;
 
     assert(pList != NULL);
     p = pList->head;
 
     if(p == NULL)
         return;
 
     for(; q != pList->head; )
     {
         node *preP = NULL;
         for(p = pList->head; p->next != q; p = p->next)
         {
             if(!compare(p->str, p->next->str))
             {
                 // swap p and p->next
 
             }
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
}

void test99()
{
	char *strList[] = {"Hello world", "apple", "food", "car", "house", "foot", "cup"};

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
