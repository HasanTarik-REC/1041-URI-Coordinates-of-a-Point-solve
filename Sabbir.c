#include <stdio.h>
#include <stdlib.h>
struct Node* delIntermadiate(struct Node *head,int pos);
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *addToEmpty(struct Node *head,int data){
    struct Node *temp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct Node *addAtEnd(struct Node *head,int data){
    struct Node *temp,*tp;
    temp=(struct Node *)malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}

struct Node * delFirst(struct Node* head){
    struct Node* temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;
    return head;
}
struct Node* delLast(struct Node* head){
    struct Node *temp=head;
    struct Node* temp2;
    while (temp->next !=NULL) {
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    return head;
}

struct Node* delIntermadiate(struct Node *head,int pos){
    struct Node *temp=head;
    struct Node* temp2=NULL;
    if (pos == 1) {
        head=delFirst(head);
        return head;
    }
    for (int i=0; i<pos-1;i++) {
        temp=temp->next;
    }
    if (temp->next==NULL) {
        head=delLast(head);
        printf("\nLast Node delete.\n");
        
    }
    else {
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
    }
    return head;
}
void Print(struct Node *head){
    struct Node *temp=head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }

    printf("NULL\n");
}


int main()
{
    while(1){
    struct Node *head=NULL;
    struct Node *temp;
    int position;
    printf("Enter the position:\n");
    scanf("%d",&position);
    head=addToEmpty(head,45);
    head=addAtEnd(head,9);
    head=addAtEnd(head,100);
    head=addAtEnd(head,150);
    Print(head);
    head=delIntermadiate(head,position); 
    printf("\n"); 
    Print(head); 


} 
    return 0;
}