#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//这道题只能说如果不动脑子是挺简单的 比如我 就用了一个数组来储存然后再反转存进去
//只能说空间复杂度有点高  要遍历两边 时间复杂度也高点
//下面直接写迭代的方法 我只能说leetcode官方题解真不是中国人能读懂的
//也不给个注释和图解  
//迭代的方法就是两个指针分别指向前一个和后一个指针  让后一个指向前一个然后再把两个指针同时后移
ListNode* reverseList(ListNode* head) {
    //从NULL开始  这样就可以保证链表结尾是NULL
    ListNode* bef = NULL;
    ListNode* aft = head;
    while(aft!=NULL){
        //需要临时存储aft的下一个 因为一点aft->next指向了前一个bef 就断了
        ListNode* tmp =aft->next;
        //后一个指向前一个
        aft->next = bef;
        //两个都往后移一位
        bef = aft;
        aft = tmp;
    }
    //这里返回bef的原因是  aft成了NULL  bef指向了最后一个结点
    return bef;
}
int main(){
    int n;
    cin>>n;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* newhead =head;
    for(int i = 0; i < n; i++){
        ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
        cin>>head->val;
        //这里有判断的原因是  如果不判断最后一个 最后一个末尾会有一个新的结点其初始值是设好了的 反过来的时候也会多一个
        if(i != n-1){
            head->next=tmp;
            head = tmp;
        }else{
            head->next = NULL;
        }
    }
    ListNode* res = reverseList(newhead);
    while(res!=NULL){
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;
    return 0;
}
