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

/*
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
}*/


int compare(char *str1, char *str2)
{
	return strcmp(str1, str2);
}
void dumpList(list *pList);
/*
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
}*/


/*
void sort(list *pList)
{
	node *p, *q, *r;
	char *tmp;

	if (pList->head == NULL || pList->head->next == NULL)
	{
		return;
	}

	r = NULL;

	while(r != pList->head)
	{
		p = pList->head; 
		q = p->next;

		while (q != r)
		{
			if (compare(p->str, q->str) > 0)
			{
				tmp = p->str;
				p->str = q->str;
				q->str = tmp;
			}
			p = p->next;
			q= q->next;
		}

		r = p;
	}
}*/

/*
void sort(list *pList)
{
	node *p, *q;
	char *tmp;

	if (pList->head == NULL || pList->head->next == NULL)
	{
		return;
	}
	
	for (p = pList->head; p != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (compare(p->str, q->str) > 0)
			{
				tmp = p->str;
				p->str = q->str;
				q->str = tmp;
			}
		}
	}
}*/

node *merge(node *left, node* right)
{
	node tmp, *p;
	p = &tmp;
	while(left != NULL && right != NULL)
	{
		if (compare(left->str, right->str) > 0)
		{
			p->next = right;
			p = p->next;
			right = right->next;
		}
		else
		{
			p->next = left;
			p = p->next;
			left = left->next;
		}
	}

	if (left != NULL)
	{
		p->next = left;
	}

	if (right != NULL)
	{
		p->next = right;
	}

	return tmp.next;
}

node* mergeSort(node *head)
{
	node *slow, *fast, *pre;
	node *left, *right;
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	slow = fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pre->next = NULL;

	left = mergeSort(head);
	right = mergeSort(slow);

	return merge(left, right);
}

// merge sort

void sort(list *pList)
{
	node *head;
	assert(pList != NULL);

	head = mergeSort(pList->head);
	pList->head = head;
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
