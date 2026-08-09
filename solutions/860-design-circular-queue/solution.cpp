class MyCircularQueue {
public:
    vector<int> q;
    int front , rear , size , curr;
    MyCircularQueue(int k) {
        q = vector<int>(k);
        front =-1;
        rear = -1;
        size = k;
        curr = 0;

    }
    
    bool enQueue(int value) {
        if(this->isFull()==true) return false;
        if(this->isEmpty()){
            rear = 0;
            front = 0;
            q[rear] = value;
            curr =1;
            return true;
        }

        rear--;
        if(rear==-1) rear = size-1;
        q[rear] = value;
        curr++;
        return true;
    }
    
    bool deQueue() {
        if(this->isEmpty()) return false;

        if(front==rear){
            front=-1;
            rear=-1;
            curr=0;
            return true;
        }


        front--;
        if(front==-1) front=size-1;

        curr--;
        return true;
    }
    
    int Front() {
        if(this->isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(this->isEmpty()) return -1;
        return q[rear];
        
    }
    
    bool isEmpty() {
        return curr==0;
    }
    
    bool isFull() {
        return curr==size;
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