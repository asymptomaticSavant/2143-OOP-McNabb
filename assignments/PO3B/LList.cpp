#include "LList.h"

Node::Node(BaseFighter d, Node* n = nullptr, Node* n2 = nullptr)
{
    data = d;
    next = n;
    prev = n2;
}

LList::LList()
{
    front = nullptr;
    tail = nullptr;
}

LList::~LList()
{
    Node* travel = front;

    while (travel != nullptr)
    {
        Node* deleteMe = travel;
        travel = travel->next;
        delete deleteMe;
    }
}

void LList::enqueue(BaseFighter val)
{
    tail = new Node(val, nullptr, tail);

    if (tail->prev == nullptr)
    {
        front = tail;
    }
    else
    {
        tail->prev->next = tail;
    }
}


bool LList::dequeue()
{
    if (tail != nullptr)
    {
        Node* deleteMe = tail;
        tail = tail->prev;

        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {

            front = nullptr;
        }

        delete deleteMe;
        return true;
    }
}

void LList::print()
{
    Node* travel = front;

    while (travel != nullptr)
    {
        // Print each item
        cout << travel->data << ' ';
        // Move forward each iteration
        travel = travel->next;
    }
    cout << endl;
}

//Node* LList::getPrev(int key)
//{
//    Node* travel = front;
//    Node* trail = nullptr;

//    while (travel != nullptr)
//    {
//        if (travel->data == key)
//        {
//            return trail;
//        }
//        trail = travel;
//        travel = travel->next;
//    }
//
//    return nullptr;
//}