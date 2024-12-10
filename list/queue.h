#include <iostream>
/*
@author: Steven Yu 2024/12/10
 */
#ifndef Elemtype
#define Elemtype int
#endif
const int N = 100010;
const int maxSize = 100;
using std::cin;
using std::cout;
using std::endl;

// 非循环顺序队列，用数组模拟
//hh指向队头（初始为0），队头弹出
//tt指向队尾前一个元素（初始为-1），队尾插入
typedef struct SquentialQueue
{
    Elemtype q[N], hh=0, tt = -1;

    void enqueue(int x)
    {
        q[++tt] = x;
    }

    bool isEmpty()
    {
        return hh > tt;
    }

    void dequeue()
    {
        hh++;
    }

    Elemtype back ()
    {
        return q[tt+1];
    }

    Elemtype front ()
    {
        return q[hh];
    }
} SeqQueue;

//循环队列，长度为100
//判断方法为空一个队列元素,队尾指针指向队尾下一块空余位置
//约定队头指针在队尾指针的下一个位置上时对满（尽管此时还空一位置）
typedef struct CircularQueue{

    Elemtype q[maxSize], hh=0,tt=0;
//循环队列为空的条件 hh == tt
    bool isEmpty(){
        return hh == tt;
    }
//循环队列满的条件 ()
    bool isFull(){
        return (( tt + 1 ) % maxSize )== hh;
    }

    int size(){
        return ( tt - hh + maxSize) % maxSize;
    }
    void enqueue(Elemtype e){
        q[(tt++)%maxSize] = e;
    }

    void dequeue(){
        hh =(hh+1) % maxSize;
    }

    Elemtype front(){
        return q[hh];
    }

    Elemtype back(){
        return q[(tt-1)%maxSize];
    }
}CirQueue;