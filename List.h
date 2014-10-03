/* List.h*/

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>
#include <stdlib.h>

#define SIZE_CONTENT 100

#endif
//define item of the node, make change on this to apply diffent cases.
typedef struct item{
    int ID;
    char content[SIZE_CONTENT];
    int value;
}Item;

//define Node of the list. dont have to change this.
typedef struct node{
    Item item;
    struct node* next;
}Node;

typedef Node* List;

//initialize a list
//before: there is a listpointer point to some list
//after: the content of the list become NULL
void InitializeList(List* plist);

//if the list is empty
//before: plist point to an exist list
//after: if it's empty return true, else return false
bool ListIsEmpty(List* plist);

//if the list is full
//before: pass a pointer of list to the function
//after: if the list is full, return trun, else return false
bool ListIsFull(List* plist);

//to tell how many items are here in the list
//before: pass a pointer of a list to the func.
//after: gives back the count of items in the list
unsigned int ListItemCount(const List* plist);



//addNode: Add a node to the head of the given list
//before: a given list
//after: add a new node to the head of the list
List AddToHead(List list, Item item);

//Traverse: go through the list do the function
//before; a given list and a given function
//after: go through the list do the function on every item

void Traverse(const List* plist, void (*pfun)(Item item));

//EmptyTheList: empty the list
//empty a given list
void EmptyTheList(List* plist);

