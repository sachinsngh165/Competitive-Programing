#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	char info;
	node* left;
	node* right;
	bool visited;
};
node* CreateNewNode(char info)
{
	node* newnode = new node;
	newnode->info = info;
	newnode->left =NULL;
	newnode->right = NULL;
	newnode->visited=false;

	return newnode;
}
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}

/* Print nodes at a given level */
void printGivenLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%c ", root->info);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void bfs_traversal(node* root)
{
	queue<node*> q;
	q.push(root);
	node* temp;
	ll ht = height(root);
	while(!q.empty())
		{
			ll size = q.size();
			for (int i = 1; i <=(2*ht-size); ++i)
			{
				cout<<"  ";
			}

			for (int i = 1; i <=size; ++i)
			{
				temp = q.front();
			cout<<temp->info <<"  ";		
			q.pop();
			
			if (temp->left!=NULL )
			{
				q.push(temp->left);
			}
			if (temp->right!=NULL )
			{
				q.push(temp->right);
			}
			}
			
		cout<<endl;
			
		}

}
void traversal(node* ptr)
{
	if (ptr==NULL)
	{
		return;
	}
	cout<<ptr->info <<" ";
	traversal(ptr->left);
	traversal(ptr->right);
}

void ConstructTree(string str,node** root)
{
	ll size = str.size();
	stack<int> s;
	stack<node*> s2;
	node *a,*b;
	
	node* head =NULL;
	char temp;
	for (int i = 0; i < size; ++i)
	{
		temp = str[i];

		//if oprator make it root
		if (temp>='0' && temp<='9')
		{
			
				s2.push(CreateNewNode(temp));
		
		}else if (temp=='+' || temp=='-' || temp=='*' || temp=='/')
		{
			s.push(temp);
		}else
		{
			if (temp=='(')
			{
				s.push(temp);
			}else
			{
				
					
					head = CreateNewNode(s.top());
					s.pop();
					if (s2.size()<2)
					{
						cout<<"Invalid Infix Expression\n";
						return;
					}
					b = s2.top();
					s2.pop();
					a = s2.top();
					s2.pop();

					head->left = a;
					head->right= b;
					s2.push(head);	
	
				s.pop();
			}
		}
	}
	
	*root = s2.top();
}


int main()
{
  string str;
  cin>>str;
  node* root=NULL;
  ConstructTree(str,&root);
 
 cout<<"Inorder Traversal\n";
 /*for (int i = 1; i <=height(root); ++i)
 {
 	printGivenLevel(root,i);
 	cout<<endl;
 }*/

 bfs_traversal(root);
  cout<<endl;

  return 0;
}