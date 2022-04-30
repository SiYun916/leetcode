#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//我只能说 这道题主要看基础 一开始我觉得我写的是对的 
//但最终发现赋值的位置错了
//还有没考虑空串的情况
ListNode* initNode(int n,vector<int>& nums){
    ListNode* head;
    //一定不要忘记给头节点分配空间 如果不分配就没有next的位置去指向下一个 和list3直接赋值list1不是一个性质
    head = (ListNode*)malloc(sizeof(ListNode));
    ListNode* headNode =head;
    for(int i = 0; i < n; ++i){
        ListNode* tmp;
        tmp = (ListNode*)malloc(sizeof(ListNode));
        tmp->val = nums[i];
        head->next = tmp;
        head = head->next;
    }
    return headNode->next;
}
void outputList(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        //第一遍忘记下面的了
        head = head->next;
    }
    cout<<endl;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode* list3;
       ListNode* res;
       if(list1==NULL){
           return list2;
       }else if(list2==NULL){
           return list1;
       }
       if(list1->val<=list2->val){
           list3 = list1;
           list1 = list1->next;
       } else{
           list3 = list2;
           list2 = list2->next;
       }
       res = list3;
       while(list1!=NULL&&list2!=NULL){
           if(list1->val <= list2->val){
                list3->next = list1;
                list3 = list3->next;
                list1 = list1->next;
           } else{
                list3->next = list2;
                list3 = list3->next;
                list2 = list2->next;
           }
       }
       while(list1!=NULL){
            list3->next = list1;
            list3 = list3->next;
            list1 = list1->next;
       }
       while(list2!=NULL){
            list3->next = list2;
            list3 = list3->next;
            list2 = list2->next;
       }
       return res;
}

int main(){
    int n,m;
    //妈的 蠢死我了  一开始忘记给n输入值了  一直以为函数写错了 虽然刚开始确实写错了点
    cin>>n>>m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i = 0; i < n; ++i){
        cin>>nums1[i];
    }
    for(int j = 0; j < m; ++j){
        cin>>nums2[j];
    }
    ListNode* head1;
    head1 = initNode(n,nums1);
    ListNode* head2;
    head2 = initNode(m,nums2);
    ListNode* res;
    res = mergeTwoLists(head1,head2);
    outputList(res);
    return 0;
}
