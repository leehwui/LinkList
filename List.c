/* List.c*/
/* this file content all the operations on a list
*/
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

static void AddToNode(Node* pnode, Item item);

//iniiallize
void InitializeList(List* plist)
{
    *plist=NULL;
}

bool ListIsEmpty(List* plist)
{
    if(*plist==NULL)
        return true;
    else
        return false;
}

    
bool ListIsFull(List* plist)
{
    Node* pnode;
    bool full;

    pnode=(Node*)malloc(sizeof(Node));

    if(pnode==NULL)
        full=true;
    else
        full=false;

    free(pnode);
    return full;
}

unsigned int ListItemCount(const List* plist)
{
    Node* pnode;
    unsigned int counter=0;

    pnode=*plist;

    while(pnode!=NULL)
    {
        counter++;
        pnode=pnode->next;
    }
    
    return counter;
}

static void AddToNode(Node* pnode, Item item)
{
    pnode->item=item;
}

List AddToHead(List list, Item item)
{
    Node* pnode;
    pnode=(Node*)malloc(sizeof(Node));
    if(pnode==NULL)
        printf("Add Item failed!\n");
   
    AddToNode(pnode, item);
    pnode->next=list;
    
    return pnode;
}

void Traverse(const List* plist, void (*pfun)(Item item))
{
    Node* pnode;
    pnode=*plist;

    while(pnode!=NULL)
    {
        (*pfun)(pnode->item);
        pnode=pnode->next;
    }
}

void EmptyTheList(List* plist)
{
    Node* pnode;

    pnode=*plist;
    while(pnode!=NULL)
    {
        pnode=pnode->next;
        free(*plist);
        *plist=pnode;
    }
}
