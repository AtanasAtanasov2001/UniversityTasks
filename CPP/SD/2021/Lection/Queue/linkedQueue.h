/******************************************************************
*  Sample code to the course "Data Structures And Algorithms", FMI
*
* An educational class, representing linked queue implementation
*
* (cc) Petar Armyanov, FMI, 2020
*******************************************************************/
#pragma once

#ifndef _LINKED_QUEUE_HEADER_INCLUDED_
#define _LINKED_QUEUE_HEADER_INCLUDED_

#include "queue.h"
#include <stdexcept>
#include <cassert>

namespace fmi {
namespace sdp {

template <class DataType>
class LinkedQueue : public Queue<DataType>
{
public:
    LinkedQueue()
        : begin(nullptr)
        , end(nullptr)
    {}
    LinkedQueue(const LinkedQueue<DataType>& rhs);

    LinkedQueue<DataType>& operator=(const LinkedQueue<DataType>& rhs);
    ~LinkedQueue();

    void enqueue(const DataType& data) override;
    DataType dequeue() override;
    const DataType& first() const override;
    bool isEmpty() const override;
    bool isFull() const override { return false; }

private:
    struct node
    {
        DataType data;
        node* next;
        node(const DataType& data, node* n = nullptr)
            : data(data), next(n) {}
    } *begin, *end;

private:
    void clear();
    void copy(const node* start);
};

#include "linkedQueue.inc"

} // namespace sdp
} // namespace fmi



#endif  //_LINKED_QUEUE_HEADER_INCLUDED_
