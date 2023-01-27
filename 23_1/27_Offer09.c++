#include <iostream>
#include <stack>
using namespace std;

class CQueue{
    
public:
    stack<int> stackIn;
    stack<int> stackOut;
    CQueue(){}
    //两个栈实现队列
    //思路：队列是头出尾进，栈是先进后出，进队列的时候可以采取一个栈来模拟，用stackIn来模拟入队列
    //出队列呢？根据入栈stackIn的top与pop我们可以得到一个和它完全相反的栈，出栈stackOut，这个栈的top和pop就是出队列
    //最重要一点：stackOut什么时候才能输出呢？
    //1. 两个栈都为空的时候，队列为空，输出是-1
    //2. 当入栈非空而出栈为空的时候，队列非空，我们可以出队列，但是要将入栈的数据先top和pop到出栈中
    //3. 当出栈非空，直接出队列即可
    //2 3点综合一下其实有好几种情况
    //比如，我入队3个数出队1个数然后入队3个数最后再出队2个数
    //在出队一个数时，stackIn时空的而stackOut非空，所以在最后出队2个数时就不需要从stackIn中取数了
    //所以才有这句话：每次deleteHead时，若输出栈为空则将输入栈的全部数据依次弹出并压入输出栈
    void appendTail(int value){
        stackIn.push(value);
    }

    int deleteHead(){
        if(stackIn.empty()&&stackOut.empty())
            return -1;
        else if (stackOut.empty()){
            while(!stackIn.empty()){
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
            int tmp = stackOut.top();
            stackOut.pop();
            return tmp;
        }
        else{
            int tmp = stackOut.top();
            stackOut.pop();
            return tmp;
        }
    }
};

int main(){
    CQueue* obj = new CQueue();
    obj->appendTail(10);
    obj->appendTail(2);
    obj->appendTail(5);
    int head = obj->deleteHead();
    cout<<head<<endl;
    return 0;
}







