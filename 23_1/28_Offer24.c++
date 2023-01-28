#include <iostream>
using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
}ListNode;

class Solution{
    
    public:
        ListNode* reverseList(ListNode* head){
            ListNode* prev = NULL;
            ListNode* curr = head;
            while(curr){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        } 
};
int main(){
    ListNode* fs = (ListNode*)malloc(sizeof(ListNode));
    ListNode* se = (ListNode*)malloc(sizeof(ListNode));
    ListNode* th = (ListNode*)malloc(sizeof(ListNode));
    ListNode* fo = (ListNode*)malloc(sizeof(ListNode));
    ListNode* fi = (ListNode*)malloc(sizeof(ListNode));
    ListNode* head;
    fs->val = 1;fs->next = se;
    se->val = 2;se->next = th;
    th->val = 3;th->next = fo;
    fo->val = 4;fo->next = fi;
    fi->val = 5;fi->next = NULL;
    head = fs;
    Solution* obj = new Solution();
    ListNode* rh = obj->reverseList(head);
    while(rh){
        cout<<rh->val<<endl;
        rh = rh->next;
    }
    return 0;
}



