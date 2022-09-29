#include <iostream>
#include <string>

class Queue
{
private:
    int* list;
    int front, rear, capacity;

public:
    Queue(int size);
    Queue(int* newList, int listSize, int queueSize);
    ~Queue();

    void enQueue(int data);
    int deQueue();
    int queueSize() const;
    int isEmptyQueue();
    int isFullQueue();

    void printQueue();
};

Queue::Queue(int size)
{
    capacity = size;
    front = rear = -1;
    list = new int[capacity];
}

Queue::Queue(int* newList, int listSize, int queueSize)
{
    
    capacity = queueSize;
    if (listSize < capacity)
    {
        front = 0;
        rear = listSize - 1;

        list = new int[capacity];
        for (int i = 0; i < listSize; i++)
            list[i] = newList[i];

    }
    else
        throw "Data is too large for the Queue";
}

void Queue::enQueue(int data)
{
    if (isFullQueue())
        throw "Queue Overflow";
    else
    {
        rear = (rear + 1) % capacity;
        list[rear] = data;
        if (front == -1)
            front = rear;
    }
}

int Queue::deQueue()
{
    if (isEmptyQueue())
        throw "Empty Queue Exception";

    int data = list[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % capacity;

    return data;
}

int Queue::queueSize() const
{
    return (capacity - front + rear + 1) % capacity;
}

int Queue::isEmptyQueue()
{
    return front == -1;
}

int Queue::isFullQueue()
{
    return (rear + 1) % capacity == front;
}

void Queue::printQueue()
{
    std::cout << "{ ";

    if (!isEmptyQueue())
    {
        for (int i = front; i != rear;)
        {
            std::cout << list[i] << ", ";
            i = (i + 1) % capacity;
        }

        std::cout << list[rear];
    }

    std::cout << " }" << std::endl;
}

Queue::~Queue()
{
    delete[] list;
}


int main()
{
    int listA[4] = { 2, 4, 5, 3 };

    Queue QueueA(listA, 4, 10);

    std::cout << "Initial Queue: ";
    QueueA.printQueue();
    std::cout << std::endl;

    std::cout << "Adding 9 and 6 to the queue: ";
    QueueA.enQueue(9);
    QueueA.enQueue(6);
    QueueA.printQueue();
    std::cout << std::endl;

    std::cout << "Dequeueing once : ";
    QueueA.deQueue();
    QueueA.printQueue();
    std::cout << std::endl;
}