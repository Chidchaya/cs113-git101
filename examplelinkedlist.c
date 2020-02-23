//6210451128 chidchaya jenkalpana
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void bubblesort(struct Node *head){
    struct Node *p ,*q;
    int swap;
    for(p=head;p;p=p->next){
        for(q=p->next;q;q=q->next){
            if(p->data > q->data){
                swap = p->data;
                p->data = q->data;
                q->data = swap;
            }
        }
    }
}
struct Node *createNode(){
    struct Node *create=(struct Node *)malloc(sizeof(struct Node));
    return create;
}
void buildll(struct Node **head,int number){
    struct Node *create=createNode();
    struct Node *tmp = *head;
    create->data = number;
    create->next = NULL;
    if(*head == NULL){
        *head = create;
    }
    else{
        while(tmp->next!=NULL){
            tmp = tmp -> next;
        }
        tmp->next = create;
        bubblesort(*head);
    }
}

void printsort(struct Node **head){
    struct Node *tmp;
    for(tmp = *head; tmp ;tmp= tmp->next){
        printf("%d\n",tmp->data);
    }
}
int main(){
    struct Node *head = NULL;
    int input;
    while (scanf("%d",&input)==1){
        if(input <= -1){
            break;
        }
        buildll(&head,input);
    }
    printsort(&head);
}