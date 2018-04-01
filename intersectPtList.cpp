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

Node* intersectPt(Node* l1,Node* l2)
{
	int len1 = 0;
	int len2 = 0;
	int diff;

	Node* ptr1= l1;
	Node* ptr2 = l2;
	Node* intrsn = NULL;

	while(ptr1!=NULL)
	{
		len1++;
		ptr1 = ptr1->next;
	}
	while(ptr2!=NULL)
	{
		len2++;
		ptr2 = ptr2->next;
	}

	ptr1 = l1;
	ptr2 = l2;

	if (len1 >= len2)
	{
		diff = len1-len2;
		// Skip diff number of nodes in list 1
		for (int i = 0; i < diff; ++i)
		{
			ptr1 = ptr1->next;
		}

		while(ptr1!=NULL)
		{
			if (ptr1 == ptr2)
			{
				intrsn = ptr1;
				break;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}else 
	{
		diff = len2 - len1;
		// Skip diff number of nodes in list 1
		for (int i = 0; i < diff; ++i)
		{
			ptr2 = ptr2->next;
		}

		while(ptr2!=NULL)
		{
			if (ptr1 == ptr2)
			{
				intrsn = ptr2;
				break;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}

	}

	return intrsn;

}

int main()
{
	Node* l1 = NULL;
	Node* l2 = NULL;



	
	
	insertNode(6,&l1);
	insertNode(5,&l1);
	insertNode(4,&l1);

	l2 = l1;

	insertNode(3,&l1);
	insertNode(2,&l1);
	insertNode(1,&l1);
	insertNode(0,&l1);
	cout<<"List 1 has been created\n";

	
	insertNode(8,&l2);
	insertNode(7,&l2);

	cout<<"List 2 has been created\n";

	printList(l1);
	printList(l2);

	
	Node* intrsn = intersectPt(l1,l2);
	cout<< intrsn->data <<endl;;


	return 0;
}