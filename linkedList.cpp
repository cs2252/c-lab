#include<iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
	Node(int key,Node *nxt)
	{
		data=key;
		next=nxt;
	}
};
Node *push(Node *);
Node *pop(Node *);
Node *queue(Node *);
Node *sort(Node *head)
{
	Node *current,*prev;
	int count=0;
	current=head;
	while(current!=NULL)
	{
		count++;
		current=current->next;
	}
	cout<<"no of elements ="<<count<<endl;

	
	for(int i=0;i<count;i++)
	{
		for(int j=0;j<count-1-i;j++)
		{
				current=head;
				prev=NULL;
			int temp=0;
			while(temp!=j)
			{
				prev=current;
				current=current->next;
				temp++;
			}
			Node *nxt=current->next;
			int aj=current->data;
			int aj1=nxt->data;
			
			if(aj>aj1)
			{
				if(temp==0)
				{
					current->next=nxt->next;
					nxt->next=current;
					head=nxt;
				}
				else
				{
				prev->next=nxt;
				current->next=nxt->next;
				nxt->next=current;
				}
				
				
			}
		}
	}
	return head;
}
Node *create(int key,Node *nxt)
{
	Node *n=new Node(key,nxt);
	return n;
}
Node *insert_front(Node *head)
{
	int key;
	cout<<"enter the data"<<endl;
	cin>>key;
	Node *ptr;
	if(head==NULL)
	{
		ptr=create(key,NULL);
		head=ptr;
		return head;
	}
	ptr=create(key,head);
	return ptr;
}
Node *insert_back(Node *head)
{
	int key;
	cout<<"enter the data"<<endl;
	cin>>key;
	Node *ptr;
	if(head==NULL)
	{	
		ptr=create(key,NULL);
		head=ptr;
		return head;
	}
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=create(key,NULL);
	return head;
}
void display(Node *head)
{
	Node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"  ";
		ptr=ptr->next;
	}
	cout<<endl;
}
Node *reverse(Node *head)
{
	Node *current,*prev,*nxt;
	current=head;
	nxt=head->next;
	prev=NULL;
	while(current!=NULL)
	{
		nxt=current->next;
		current->next=prev;
		prev=current;
		current=nxt;
	}
	return prev;
}
Node *stack(Node *head)
{
	int option;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.display()"<<endl;
	cout<<"-1 to return to main function"<<endl;
	cout<<"enter your option"<<endl;
	cin>>option;
	do
	{
		switch(option)
		{
			case 1:
				head=push(head);
				break;
			case 2:
				head=pop(head);
				break;
			case 3:
				display(head);
		}
			cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3.display()"<<endl;
	cout<<"-1 to return to main function"<<endl;
	cout<<"enter your option"<<endl;
	cin>>option;
	}while(option!=-1);
	return head;
}
int main()
{
	Node *head,*ptr;
	head=NULL;
	int option;
	cout<<"1.insert back"<<endl;
	cout<<"2.insert front"<<endl;
	cout<<"3.display"<<endl;
	cout<<"4.reverse"<<endl;
	cout<<"5.stack"<<endl;
	cout<<"6.queue"<<endl;
	cout<<"7.sort by bubble sort"<<endl;
	cout<<"enter your option"<<endl;
	cin>>option;
	do{
		switch(option)
		{
			case 1:
				head=insert_back(head);
				break;
			case 2:
				head=insert_front(head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				head=reverse(head);
				break;
			case 5:
				head=stack(head);
				break;
			case 6:
				head=queue(head);
				break;
			case 7:
				head=sort(head);
		}
	cout<<"1.insert back"<<endl;
	cout<<"2.insert front"<<endl;
	cout<<"3.display"<<endl;
	cout<<"4.reverse"<<endl;
	cout<<"5.stack"<<endl;
	cout<<"6.queue"<<endl;
	cout<<"7.sort by bubble sort"<<endl;
	cout<<"enter your option"<<endl;
	cin>>option;
	}while(option!=-1);
	return 0;
}
Node *push(Node *head)
{
	head=insert_front(head);
	return head;
}
Node *pop(Node *head)
{
	return head->next;
}
Node *queue(Node *head)
{
	int option;
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3. front"<<endl;
	cout<<"4.display"<<endl;
	cout<<"5. exit"<<endl;
	cin>>option;
	do
	{
		switch(option)
		{
			case 1:
			head=insert_back(head);
			break;
			case 2:
				head=pop(head);
				break;
			case 3:
				cout<<head->data<<endl;
				break;
			case 4:
				display(head);
				break;
		}
	cout<<"1.push"<<endl;
	cout<<"2.pop"<<endl;
	cout<<"3. front"<<endl;
	cout<<"4.display"<<endl;
	cout<<"5. exit"<<endl;
	cin>>option;
	}while(option!=-1);
	return head;
}
