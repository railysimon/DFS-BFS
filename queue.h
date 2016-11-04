#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

typedef int datatype;

struct Link
{
    datatype data;
    Link *next;
};

class Queue
{
public:
        Link *front, *rear;
        Queue() : front(nullptr), rear(nullptr) {}
        ~Queue();
        void Enqueue(datatype value);
        void Dequeue();
        void Show();
};

void Queue::Enqueue(datatype value)
{
    Link *temp = new Link;
    temp->data = value;
    temp->next = nullptr;
    if (!front) front = temp;
    else rear->next = temp;
    rear = temp;
}

void Queue::Dequeue()
{
    if (front)
    {
        Link *temp = front;
        front = temp->next;
        delete temp;
    }
    else
    {
        cout << "Черга порожня!" << endl;
        exit(0);
    }
}

void Queue::Show()
{
    cout << "Вміст черги: " << endl;
    Link *current = front;
    if (!current) cout << "Черга порожня!" << endl;
    while(current)
    {
        cout << "|| " << current->data << " ||" << endl;
        current = current->next;
    }
}

Queue::~Queue()
{
    while(front)
    {
        Link *temp = front->next;
        delete front;
        front = temp;
    }
}

#endif // QUEUE_H
