/* test.c
this program tests all the functions during the developing progress
*/

#include "List.h"
#include <stdio.h>
#include <string.h>

List AddNew(List list);
void showitem(Item item);

int main(void)
{
    List list;
    InitializeList(&list); // test Initialize

    if(ListIsEmpty(&list)) //test ListIsEmpty
        printf("the list is empty\n");
    else
        printf("the list is not empty\n");
    
//    unsigned int counter=0;
//    counter=ListItemCount(&list);

    Node* pnode;

    pnode=(Node*)malloc(sizeof(Node));
    
    Item *pitem;

    pitem=(Item*)malloc(sizeof(Item));

    pitem->ID=001;
    strcpy(pitem->content, "hello list");
    pitem->value=1;
    
    pnode->item=*pitem;

    list=pnode;

    list=AddNew(list);    //test AddNew

    unsigned int counter=0;
    counter=ListItemCount(&list);
    printf("there are %u items in the list\n", counter);
    
//    void (*pfun)(Item item)=showitem;

    Traverse(&list,showitem);    //test Traverse
    
//    EmptyTheList(&list);d
    if(ListIsEmpty(&list))
        printf("list is empty!\n");
    else 
        printf("list is not empty!\n");

    EmptyTheList(&list);

    return 0;
}

List AddNew(List list)
{
    Item temp;
    printf("Input Id for new item:\n");
    scanf("%d", &temp.ID);
    printf("Input value for new item:\n");
    scanf("%d", &temp.value);
    printf("Input content for new item:\n");
    char c;
    while((c=getchar())!='\n'&&c!=EOF)
        ;
    fgets(temp.content, SIZE_CONTENT, stdin);

    list=AddToHead(list, temp);
    return list;
}

void showitem(Item item)
{
    printf("%d\n", item.ID);
    printf("%d\n", item.value);
    printf("%s\n", item.content);
}
