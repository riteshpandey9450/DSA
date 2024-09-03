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
int getlength(node *head){
    node *temp=head;
    int count=0;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
    
}
void insertAtHead(int val,node *&head,node *&tail){
    //if LL is empty
    if (head==NULL&&tail==NULL)
    {
        //create
     node *newnode=new node(val);
     //head and tail ko ishpe laao
     head=newnode;
     tail=newnode;
    }
    else { //LL i not empty
    //step1:create
    node *newnode=new node(val);
    //newnode ko point karo head pe
    newnode->next=head;
     //head ko point karo newnode pe
    head->prev=newnode;
    //head ko update karo
    head=newnode;
    }
}
void insertAtTail(int val,node *&head,node *&tail){
    if (head==NULL&&tail==NULL)
    {
        //create
     node *newnode=new node(val);
     //head and tail ko ishpe laao
     head=newnode;
     tail=newnode;
    }
    else { //LL i not empty

    //create node
    node *newnode=new node(val);
    //6tail ke next ko assign karo
    tail->next=newnode;
    //newnode ke prev o tail pe point karo
    newnode->prev=tail;
    //tail ko update karo
    tail=newnode;
    }
}
void insetatposition(int position,int val,node *&head,node *&tail){
    int length=getlength(head);

    if(position<=0&&position>length+1) {
        cout<<"invalid position";
        return;
    }
   
    if(position==1) //means insertAtHead
    {
        insertAtHead(val,head,tail);
    }
    else if(position==length+1) //means insetattail
    {
        insertAtTail(val,head,tail);
    }
    else{
        //create node
         node *newnode=new node(val);
         //create temp-> to iterate on LL
        node *temp=head;
        //temp ko position-2 times aage badhao
        //mean tem ko jaha insert karna hai ushe aik pahle tak le jao
        for (int i = 0; i < position-2; i++)
        {
            temp=temp->next;
        }
        //new node ko 
        newnode->next=temp->next; 
        temp->next->prev=newnode;
        temp->next=newnode;
        newnode->prev=temp;
    }
    
}
void print(node *head){
    node *temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        //temp ko aage badao
        temp=temp->next;
    }cout<<endl;
    
}
void deleteFromPosition(int position,node *&head,node *&tail){
    //if LL is empty
    if (head==NULL&&tail==NULL)
    {
        cout<<"deletionnot possible";
        return;
    }
    //we have single node -> means deletion of single node
    //means when length of LL is one
    if(head==tail){
        //create temp
        node *temp=head;
       //head & tail ko null karo
       head=NULL;
       tail=NULL;
       //temp ko delete karo
       delete temp;
    }
    //deletion of head node 
    //means deletion of node at first position
    if (position=1)
    {
        node* temp=head;
        head=temp->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }
    else //LL ke kishi middle element ka deletion
    {
        //create temp
        node *temp=head;
        //jish pos pe deletion karna hai uhe aik pahle tak tamp ko le jao
        for (int i = 0; i < position-2; i++)
        {
            temp=temp->next;
        }
        node *nodetodelete=temp->next;
        node *forward=nodetodelete->next;
        temp->next=forward;
        forward->prev=temp;
        nodetodelete->next=NULL;
        nodetodelete->prev=NULL;
        delete nodetodelete;
        
    }
    
}
int main(){
    node *head=NULL;
    node *tail=NULL;
    insertAtHead(30,head,tail);
    insertAtHead(25,head,tail);
    insertAtHead(20,head,tail);
    insertAtHead(15,head,tail);
    int position=3;
    int value=50;
    insetatposition(position,value,head,tail);
    //15->20->50->25->30
    print(head);
    deleteFromPosition(3,head,tail);
    print(head);
   
}