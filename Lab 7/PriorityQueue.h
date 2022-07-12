
template <typename T, int capacity>

class Queue {
private:
    T arr[capacity];
    int priority[capacity];
    int length; //amount of data queued


public:
    Queue() : priority{0}, length(-1) {} //initalizing variables (start with -1 as solution for first addition to queue)

    void enqueue(const T item, int prior) {
        if(length==capacity){ //if already full then leave and dont add
            return;
        }
        priority[++length] = prior; //increment length and then set priority to that index
        arr[length] = item; //place item in the same index
    }

    T dequeue() {
        int minimum = priority[0];
        int index = 0;
        for(int i = 0; i<length+1;i++){ //find the highest priority item
            if(priority[i]<minimum){
                minimum = priority[i];
                index = i;              //save index of highest priority
            }
        }
        T temp = arr[index];

        /*fill in gap with item at the end*/
        arr[index] = arr[length];
        priority[index] = priority[length--];    //replacing 'popped' item with last item and then decrementing

        return temp;
    }

    T peek() {//identitical to dequeue except it doesn't decrement or remove from queue
        int minimum = priority[0];
        int index = 0;
        for(int i = 0; i<length+1;i++){
            if(priority[i]<minimum){
                minimum = priority[i];
                index = i;
            }
        }
        return arr[index];
    }

    bool isEmpty() {
        return length<=0;
    }

    int count(){
        return length+1;
    }
};

