#include <iostream>

using namespace std;

/// queue size is 10 by deflaut
class Queue{

private:
  int *array;
  int *front, *rear, size;

public:

  void enqueue(int x){
    if(front == NULL && rear == NULL){
      front = array;
      rear = front;
      *front = x;
      return;
    }
    else if(front == array && rear == array+9){
      cout<<"overflow\n";
      return;
    }
    else if(front != array && rear == array+9){
      rear = array;
      *rear = x;
    }
    else{
      rear++;
      *rear = x;
    }
  }

  void dequeue(){
    if (front == NULL && rear == NULL){
      cout<<"underflow\n";
      return;
    }
    else if(front == rear){
        *front = -100;
        front = rear = NULL;
    }
    else if(front == array+9 && rear != array+9){
      *front = -100;
      front = array;
    }
    else {
      *front = -100;
      front++;
    }

  }
  void print(){
    if (front == NULL){
      cout<<"queue is empty\n";
      return;
    }
    int * temp;
    temp = front;
    while(temp != array+10 && temp != rear){
      cout<<*temp<<" ";
      temp++;
    }
    if(temp == array+10){
      temp = array;
      while(temp != rear+1){
        cout<<*temp<<" ";
        temp++;
      }
    }
    cout<<endl<<endl;

  }

  Queue(){
    front = rear = NULL;
    size = 10;
    array = new int[size];
    for(int i = 0; i<size; i++){
      array[i] = -100;
    }

  }
  ~Queue(){
    delete [] array;
    rear = front = array = NULL;
    size = 0;
  }

};

int main(){
  Queue q;
  for(int i = 0; i<11; i++){
    q.enqueue(i+10);
  }
  q.print();

    q.dequeue();
    q.print();
    q.enqueue(999);
    q.print();
  for(int i = 0; i<11; i++){
    q.dequeue();
    q.print();
  }

  return 0;
}
