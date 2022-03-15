#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    //构造函数，即构造出来后默认赋值 val是x，next是NULL
    ListNode(int x) : val(x),next(NULL){}
};

//这里采用的是反转数组的方式输出
vector<int> reversePrint(ListNode* head){
    vector<int> tmp;
    vector<int> res;
    while(head != NULL){
        tmp.push_back(head->val);
        head = head->next;
    }
    for (int i = tmp.size()-1; i >=0; i--){
            res.push_back(tmp[i]);
        }
        return res;
}

//对于做题来说，到上面已经结束了
//对于我来说，主要的难点是利用C++构造链表,下面
int main(){
    int num;
    cin>>num;
    ListNode* head;
    ListNode* head1;
    //必须要为链表节点分配空间，否则直接赋值，没有结果
    head1 = (ListNode *)malloc(sizeof(ListNode));
    head = head1;
    for (int i = 0 ; i < num; ++i){
        ListNode* p = (ListNode *) malloc(sizeof(ListNode));
        cin>>p->val;
        head1->next = p;
        head1 = head1->next;
    }
    head1->next = NULL;
    //由于头部多创建了一个节点，所以要从第二个节点开始算起
    head = head->next;

    vector<int> num_r = reversePrint(head);
    for (int i = 0; i < num_r.size(); ++i){
        cout<<num_r[i]<<endl;
    }
    return 0;
}
