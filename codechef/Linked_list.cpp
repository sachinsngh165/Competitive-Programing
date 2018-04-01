#include<stdio.h>
#include<stdlib.h>

struct list{
    int info;
    struct list* next;
};


void print(struct list **head)
{
    struct list *ptr= *head;
    
    while (ptr!=NULL) {
        printf("%d -> ",ptr->info);
        ptr= ptr->next;
    }
}


void insertAtBeg(struct list **head,int info){
    
    //create a new node
    struct list *node= (struct list*)malloc(sizeof(struct list));
    node->info = info;
    node->next = NULL;
    
    //insert node
    
     //if no element in the list
        if (head==NULL) {
            *head = node;
            return;
        }
    
    node->next = *head;
    *head = node;
}



int main(){
    
     struct list* head1=NULL;
     struct list* head2=NULL;
    
    insertAtBeg(&head1,3);
    insertAtBeg(&head1,3);
    insertAtBeg(&head1,4);
    insertAtBeg(&head1,5);
    
       insertAtBeg(&head2,1);
       insertAtBeg(&head2,1);
       insertAtBeg(&head2,2);
       insertAtBeg(&head2,2);
       insertAtBeg(&head2,4);
    
    
    
    
    print(&head1);
    printf("\n");
    print(&head2);
    
   
    
    
    
    
    return 0;
}