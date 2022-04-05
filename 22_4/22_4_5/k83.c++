#include <iostream>
using namespace std;
//这道题 单链表删除重复元素 难点在于空指针的判断 防越界
//首先是一个循环 遍历一遍
//循环的条件真的好无语  head!=NULL&&head->next!=NULL能过  但head->next!=NULL&&head!=NULL过不了
//其实后来仔细想想也对 &&是逐个判断 先判断第一个如果不成立就推出了  假如head是NULL 明显如果先判断head->next是越界的
//还有一个易错点是 如果有3个及以上的重复值的时候  需要判断该值与下一个值是否还相等  这里还是要判断是否head->next是否越界
//如果没越界才可以判断是否相等如果相等就不要head=head->next   越界就直接退出了
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* deleteDuplicates(ListNode* head) {
        ListNode* new_head = head;
        while(head!=NULL&&head->next!=NULL){
            if(head->val==head->next->val){
                head->next = head->next->next;
                if(head->next==NULL)
                    break;
                if(head->val!=head->next->val)
                    head = head->next;
            }else{
                head = head->next;
            }
        }
        return new_head;
}
int main(){
    int n;
    cin>>n;
    ListNode* head;
    ListNode* head1;
    head = (ListNode*)malloc(sizeof(ListNode));
    head1 = head;
    for(int i = 0; i < n; ++i){
        cin>>head->val;
        ListNode* p =(ListNode*)malloc(sizeof(ListNode));
        head->next = p;
        head = head->next;
    }
    ListNode* head2 = deleteDuplicates(head1);
    while(head2!=NULL&&head2->next!=NULL){
        cout<<head2->val;
        head2 = head2->next;
    }
    cout<<endl;
    return 0;
}




