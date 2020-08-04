#include <iostream>
using namespace std;
class node{
  public:
  int d;
  node* next;
};
node* head;
node* tail;

void inserttop(int data){
  node* temp = new node();
  temp->d=data;
  temp->next=head;
  if(head==0)
    tail=temp;
  head=temp;
    }

void insertlast(int data){
  node* temp = new node();
  if(head==0){
    temp->d=data;
    temp->next=NULL;
    head=temp;
    tail=temp;
  }
  else{
    temp->d=data;
    temp->next=NULL;
    tail->next=temp;
    tail=temp;
  }
}

void insertmiddle(int data, int x){
  node* temp=new node();
  node* pre=new node();
  pre=head;
  while((pre->d)!=x){
    pre=pre->next;
  }
  temp->d=data;
  temp->next=pre->next;
  pre->next=temp;
}

void del(int data){
  node* current = new node();
  node* pre=new node();
  current=head;
  while((current->d)!=data){
    pre=current;
    current=current->next;
  }
  pre->next=current->next;
}

void display(){
  node * current=head;
  while(current!=NULL)
  {
    cout<<current->d<<"->";
    current=current->next;
  }
}
int main() {
  inserttop(10);
  inserttop(8);
  insertlast(1);
  insertmiddle(44,10);
  //del(10);
  display();
}
