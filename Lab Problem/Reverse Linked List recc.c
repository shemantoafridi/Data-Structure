#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
static void rev(struct Node** head)
{
    struct Node* pre = NULL;
    struct Node* curr = *head;
    struct Node* next = NULL;
    while (curr != NULL) {

        next = curr->next;

        curr->next = pre;

        pre = curr;
        curr = next;
    }
    *head = pre;
}

void push(struct Node** head, int ndata)
{
    struct Node* nnode
        = (struct Node*)malloc(sizeof(struct Node));
    nnode->data = ndata;
    nnode->next = (*head);
    (*head) = nnode;
}

void printList(struct Node* nhead)
{
    struct Node* temp = nhead;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct Node* nhead = NULL;

    push(&nhead, 20);
    push(&nhead, 4);
    push(&nhead, 15);
    push(&nhead, 85);

    printf("Given linked list\n");
    printList(nhead);
    rev(&nhead);
    printf("\nReversed Linked list \n");
    printList(nhead);
    getchar();
}
