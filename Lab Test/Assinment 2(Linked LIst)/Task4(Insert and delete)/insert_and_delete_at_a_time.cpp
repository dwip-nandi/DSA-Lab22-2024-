//  Delete a node from the end of a given linked list, and add that deleted node at the 
// beginning of that linked list 
//  Example: Input:  1 2 3 4 5 6 7 
//                  Output: 7 1 2 3 4 5 6 

#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int info;
    struct node* next;
};
struct node* head=NULL;
struct node* tail=NULL;

void input(int data)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        tail->next=newnode;
    }
    tail=newnode;
}
void display()
{
    cout<<endl<<"Your Linked List:"<<endl;
    struct node* cur=head;
    while(cur!=NULL)
    {
        cout<<cur->info<<" -> ";
        cur=cur->next;
    }
    cout<<"NULL";
}
void lasttofirst()
{
    struct node* save;
    save=(struct node*)malloc(sizeof(struct node));
    save->info=tail->info;
    save->next=NULL;

    struct node* cur=head;
    while(cur->next!=NULL)
    {
        if(cur->next->next==NULL)
        {
           tail=cur;
           tail->next=NULL;
           delete cur->next;
           break;
        }
        cur=cur->next;
    }
    save->next=head;
    head=save;
}


int main()
{
    int k;
    cout<<"Enter the number of node:";
    cin>>k;
    int b=0;
    for(int i=0;i<k;i++)
    {
        int x;
        cout<<endl<<"Enter the element number "<<i+1<<":";
        cin>>x;
        input(x);
        b++;
    }
    display();

    if(b<2)
    {
        cout<<endl<<"There are only one node. The Node is:";
        display();
    }
    else{

        lasttofirst();
        display();
    }

}

