#include <iostream>

using namespace std;


class Queue{
private:
  int *array;
  int front, rear,size = 10;
public:

  void enqueue(int x){
    if(front == -1){
      rear++;
      array[rear] = x;
      front++;
    }
    else if(rear != size-1){
      rear++; array[rear] = x;
    }
    else if(rear == size-1 && front != 0){
      rear = 0;
      array[rear] = x;
    }

    else cout<<"overflow\n";

  }
  void dequeue(){
    if(front != rear && front != size){
      array[front] = -100; front++;
    }
    else if(front == size && rear != 0){
      front = 0; array[front] = -100;
    }
    else if(front == size && rear == 0){
      front = -1; array[rear] = -100;
      rear = front;
    }
    else cout<<"underflow\n";
  }
  void currentVal(){
    if (front == -1) {
      cout<<"queue is empty\n";
      return;
    }
    cout<<array[front]<<endl;
  }
  void print(){
    if (front == -1)
    {
      cout<<"queue is empty\n";
      return;
    }
    if(front < rear)
      for(int i = front; i<=rear; i++)
        cout<<array[i]<<' ';
    cout<<endl;
    if(front > rear){
      for(int i = front; i < size; i++)
        cout<<array[i]<<' ';
      for(int i = 0; i<=rear; i++)
        cout<<array[i]<<' ';
      cout<<endl;
    }
  }

  Queue(){
    front = rear = -1;
    array = new int[size];
    for(int i = 0; i<size; i++){
      array[i] = -100;
    }
  }
  ~Queue(){
    delete [] array;
    rear = front = -1;
  }

};

int main(){
  Queue q;
  for(int i = 0; i<10; i++){
    q.enqueue(i+10);
  }
  for(int i = 0; i<5; i++){
    q.dequeue();
  }

    q.enqueue(1000);

  for(int i = 0; i<6; i++){
    q.dequeue();
  }
  q.print();
  q.currentVal();

  return 0;
}
#include <iostream>

using namespace std;


class Queue{
private:
  int *array;
  int front, rear,size = 10;
public:

  void enqueue(int x){
    if(front == -1){
      rear++;
      array[rear] = x;
      front++;
    }
    else if(rear != size-1){
      rear++; array[rear] = x;
    }
    else if(rear == size-1 && front != 0){
      rear = 0;
      array[rear] = x;
    }
    else cout<<"overflow\n";

  }
  void dequeue(){
    if(front != rear && front != size){
      array[front] = -100; front++;
    }
    else if(front == size && rear != 0){
      front = 0; array[front] = -100;
    }
    else cout<<"underflow\n";
  }
  void currentVal(){
    cout<<array[front]<<endl;
  }
  void print(){
    if(front < rear)
      for(int i = front; i<=rear; i++)
        cout<<array[i]<<' ';
    cout<<endl;
    if(front > rear){
      for(int i = front; i < size; i++)
        cout<<array[i]<<' ';
      for(int i = 0; i<=rear; i++)
        cout<<array[i]<<' ';
      cout<<endl;
    }
  }

  Queue(){
    front = rear = -1;
    array = new int[size];
    for(int i = 0; i<size; i++){
      array[i] = -100;
    }
  }
  ~Queue(){
    delete [] array;
    rear = front = -1;
  }

};

int main(){
  Queue q;
  for(int i = 0; i<10; i++){
    q.enqueue(i+10);
  }
  for(int i = 0; i<5; i++){
    q.dequeue();
  }
  for(int i = 0; i<3; i++){
    q.enqueue(i+10);
  }
  for(int i = 0; i<4; i++){
    q.dequeue();
  }
  q.print();
  q.currentVal();

  return 0;
}
