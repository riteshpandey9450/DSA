#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *prev;
    node *next;
    //constructor
    node(int value){
         data=value;
         prev=NULL;
         next=NULL;
    }
};
void insertAtTail(int val,node* &head,node* &tail){
    //if LL is empty
    if (head==NULL&&tail==NULL)
    {
        //2 case-> LL empty, or not empty
        //LL is empty
        //step1: create node to insert
        node *newnode=new node(val);
        //step2: head &tail ko ishpe assign karo
        head=newnode;
        tail=newnode;
    }
    else{
        //LL is not empty
        //create node
        node *newnode=new node(val);
        //tail ke next ko newnode pe point karo
        tail->next=newnode;
        //newnodeke prev ko tail pe point karo
        newnode->prev=tail;
        //tail ko update karo -> tail ko left most pe le jao
        tail=newnode;
    }
    
}
void print(node *head){
    node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<endl;
    
}
int main(){
    node *head=NULL;
    node *tail=NULL;
    insertAtTail(10,head,tail);
    // 10->
     insertAtTail(20,head,tail);
    // 10->20->
     insertAtTail(30,head,tail);
    print(head);
    // 10->20->30
}