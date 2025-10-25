#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> Q;
    int front, rear, maxSize;

    bool fullQueue() {
        return (rear+1) % maxSize == front;
    }

public:
    MyCircularQueue(int k) {
        front = -1;
        rear = -1;
        maxSize = k;
        Q = vector<int>(k,-1);    
    }
    
    bool enQueue(int value) {
        if(fullQueue())
            return false;

        rear = (rear+1) % maxSize;
        Q[rear] = value;

        if(front == -1)
            front = 0;

        return true;
    }
    
    bool deQueue() {
        if(front == -1)
            return false;
        Q[front] = -1;
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else
            front = (front+1) % maxSize;
        
        return true;
    }
    
    int Front() {
        if(front == -1)
            return -1;
        return Q[front];
    }
    
    int Rear() {
        if(rear == -1)
            return -1;
        return Q[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return fullQueue();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */