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
int main(){
    //creation of new node
node *newnode=new node(15); //newnode is the name of new creation node

}