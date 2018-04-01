#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};




void insertNode(int data,Node** head)
{
	Node* node = new Node;
	node->data = data;
	node->next = NULL;

	if (*head == NULL)
	{
		*head = node;
		return;
	}

	node->next = *head;
	*head = node;
}

void printList(struct Node* head)
{
	Node* ptr = head;
	while( ptr!=NULL )
	{
		cout<< ptr->data <<" -> ";
		ptr = ptr->next;
	}

	cout<<"NULL" <<endl;
}

Node* mergeList(Node** l1,Node** l2)
{

	//Base cases
	if (*l1 == NULL)
		return *l1;
	

	if (*l2 == NULL)
		return *l2;

	Node* newHead = NULL;
	Node* sorted = NULL;

	if ((*l1)->data <= (*l2)->data)
	{
		newHead = (*l1);
		(*l1) = (*l1)->next;
	}else
	{
		newHead = *l2;
		*l2 = (*l2)->next;
	}

	 sorted = newHead;

	while( (*l1) != NULL && (*l2) != NULL)
	{
		if ((*l1)->data <= (*l2)->data)
		{
			sorted->next =( *l1);
			sorted = sorted->next;
			*l1 = (*l1)->next;
		}
		else
		{
			sorted->next = *l2;
			sorted = sorted->next;
			*l2 = (*l2)->next;
		}

	}

	if (*l1 == NULL)
	{
		sorted->next = *l2;
	}
	else
	{
		sorted->next = *l1;
	}


	return newHead;
}


struct Node* SortedMerge(struct Node* a, struct Node* b)
{
  struct Node* result = NULL;
 
  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}

int main()
{
	Node* l1 = NULL;
	Node* l2 = NULL;



	
	
	
	insertNode(9,&l1);
	insertNode(6,&l1);
	insertNode(4,&l1);
	insertNode(2,&l1);
	cout<<"List 1 has been created\n";

	
	
	insertNode(8,&l2);
	insertNode(5,&l2);
	insertNode(1,&l2);

	cout<<"List 2 has been created\n";

	printList(l1);
	printList(l2);

	// Node* merge = mergeList(&l1,&l2);
	Node* merge  = SortedMerge(l1,l2);
	printList(merge);



	return 0;
}