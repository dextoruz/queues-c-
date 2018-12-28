#include <iostream>

using namespace std;

struct node{
  int info;
  node *next;
};

class  Queue{
private:
  node *front, *rear, *temp;

public:
  void enqueue(int x){
    if(front == NULL){
      front = new node;
      front -> info = x;
      front -> next = rear;
      rear = front;
      return;
    }
    temp = new node;
    temp -> info = x;
    temp -> next = NULL;
    rear -> next = temp;
    rear = temp;
  }
  void dequeue(){
    if(front == NULL){
      cout<<"underflow\n";
      return;
    }
    temp = front;
    front = front->next;
    delete temp;
  }

  Queue(){
    front = rear = NULL;
  }
  ~Queue(){
    while(front -> next != NULL){
      rear = front -> next;
      delete front;
      front = rear;
    }
    delete rear;
  }
};


int main(){
  Queue q;
  for(int i = 0; i<5; i++){
  q.enqueue(i+10);
  }
  for(int i = 0; i<3; i++){
  q.dequeue();
  }



  return 0;
}
