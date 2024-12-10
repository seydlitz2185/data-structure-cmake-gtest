#include <gtest/gtest.h>
#include "../list/queue.h"
#include <random>
#include <vector>
#include <functional>

using std::cin;
using std::cout;
using std::vector;

TEST(queue_test, Simple_Queue)
{
    const int size = 10;
    SeqQueue q;
    EXPECT_TRUE(q.isEmpty());
    for (int i = 0; i < size; i++)
    {
        q.enqueue(i + 1);
    }
    for (int i = i; i < size; i++)
    {
        EXPECT_EQ(q.front(), i+1);
        q.dequeue();
    }
    EXPECT_TRUE(q.isEmpty());
}

TEST(queue_test, CircularQueue)
{
    int size = 99;
    size = size%maxSize;
    CirQueue q;
    EXPECT_TRUE(q.isEmpty());
    for (int i = 0; i < size; i++)
    {
        q.enqueue(i + 1);
    }
    EXPECT_TRUE((q.isFull()) == (size==maxSize-1));
    for (int i = i; i < size; i++)
    {
        EXPECT_EQ(q.front(), i+1);
        q.dequeue();
    }
    EXPECT_TRUE(q.isEmpty());
}