#include <iostream>
#include <stack>
using namespace std;

//包含min函数的最小栈
//一开始我觉得是要自己用数组实现一个栈，不能使用stack stl
//写着写着才发现min函数是重点，在解决min的时候我的思路是空间换时间，用一个vector来记录之前的最小值
//但是我的思路很混乱，理不清楚，看了题解
//两个栈，一个最小栈保存截至当前每个数据项的最小值
//如下两个栈
//栈：            1 2 3 0 6 
//最小栈：INT_MAX 1 1 1 0 0
//思路很清晰：最小栈push的时候选当前最小的值，两个栈同时pop
class MinStack{
public:
    stack<int> number;
    stack<int> numberMin;
    MinStack(){
        numberMin.push(INT8_MAX);
    }
    
    void push(int value){
        number.push(value);
        if(value < numberMin.top())
            numberMin.push(value);
        else
            numberMin.push(numberMin.top());
    }
    void pop(){
        numberMin.pop();
        number.pop();

    }
    int top(){
        return number.top();
    }
    int min(){
        return numberMin.top();
    }
}; 


int main(){
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(0);
    cout<<"MIN NUMBER: "<<obj->min()<<endl;
    obj->pop();
    cout<<"STACK TOP: "<<obj->top()<<endl;
    cout<<"MIN NUMBER: "<<obj->min()<<endl;
    return 0;
}

