#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

typedef struct node
{
	int data;
	struct node* next;
}Node;

Node* createNode(int value)
{
	Node* res = new Node();
	res -> data =  value;
	res -> next = NULL;
	return res;
}

Node* createLL()
{
	Node* head=NULL,*prev;

	cout<<"Enter Values:"<<endl;
	while(1)
	{
		int value;
		cin>>value;
		if(value==0)
		{
			cout<<"Breaking loop";
			break;
		}
		Node* temp = createNode(value);
		if(!head)
		{
			head=temp;
			prev=temp;
		}
		else
		{
			prev->next=temp;
			prev=temp;
		}
	}
	return head;
}
void displayLL(Node* head)
{
	if(head==NULL)
	{
		cout<<"Empty List";
		return;
	}
	cout<<endl<<"List - ";
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
}

int count(Node* head)
{
	int cnt=0;
	while(head!=NULL)
	{
		cnt++;
		head=head->next;
	}
	return cnt;
}























