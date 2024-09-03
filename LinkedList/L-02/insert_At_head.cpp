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
void insertathead(int val,node* &head,node* &tail){
    //2.case-> LLis empty or not empty
    //1.case -> ll is empty
    
    if(head==NULL&&tail==NULL){
        // step1:create node
        node *newnode=new node(val);
        //step2: data mein val ko insert karo
        newnode->data=val;
        //step3: head & tail ko new node pe assign karo
        head=newnode;
        tail=newnode;
    }

    else{ //LL is ot empty
    //step1: create node
    node *newnode=new node(val);
    //step2: newnode ke next ko head  pe point karo
    newnode->next=head;
    //step3: head ko newnode  pe  point karo
    head->prev=newnode;
    //step4: head ko update karo
    head=newnode;
    }
}
void print(node *head){
    node *temp=head;
    while (temp!=NULL)
    {
         //print karo temp ki data
    cout<<temp->data<<"->";
    //step2: temp ko aage badhao
    temp=temp->next;
    }
       cout<<endl;
    
   
}
void print_reverse(node *tail){
    node* temp=tail;
    while (temp!=NULL)
    {
       cout<<temp->data<<"->";
       temp=temp->prev;
    }cout<<endl;
    
}
int main(){
    node *head=NULL;
    node *tail=NULL;
    
//insert at head
insertathead(10,head,tail);
//10->
insertathead(20,head,tail);
//20->10->
insertathead(30,head,tail);  // LL-> 30 20 10
print(head);
//30->20->10->
print_reverse(tail);
//10->20->30
}