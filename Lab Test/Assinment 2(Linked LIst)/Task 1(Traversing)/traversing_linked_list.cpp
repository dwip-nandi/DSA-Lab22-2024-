// traversing linked list

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    struct node* next;
};
node* head = NULL;
node* tail = NULL;

void input(int x)
{
    node* newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->info=x;
    newnode->next=NULL;

    if(head==NULL){
        head = newnode;
    }else{
        tail->next=newnode;
    }
    tail=newnode;
}
void display(){
    cout<<"The linked list is : ";
    node* cur=head;
    while(cur != NULL){
        cout<<cur->info<<' ';
        cur=cur->next;
    }
    cout<<endl;
}
int main()
{
    cout << "Enter the number of elements of the Linled List :";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enyer the element number" << i + 1 << " : ";
        int x;
        cin >> x;
        input(x);
    }
    // display the linked list
    display();
}