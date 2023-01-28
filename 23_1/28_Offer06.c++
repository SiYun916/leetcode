#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode* next;
}ListNode;

class Solution{
    public:
        stack<int> tmpStack;
        vector<int> result;
    vector<int> reversePrint(ListNode* head){
        while(head!=NULL){
            tmpStack.push(head->val);
            head = head->next;
        }
        while(!tmpStack.empty()){
            result.push_back(tmpStack.top());
            tmpStack.pop();
        }
        return result;
    }
};

int main(){
    ListNode* f =  (ListNode*)malloc(sizeof(ListNode));
    ListNode* s =  (ListNode*)malloc(sizeof(ListNode));
    ListNode* t =  (ListNode*)malloc(sizeof(ListNode));
    f->val = 1;
    f->next = s;
    s->val = 3;
    s->next = t;
    t->val = 2;
    t->next = NULL;
    ListNode* head = f;
    Solution* obj = new Solution();
    vector<int> r;
    r = obj->reversePrint(head);
    for(int i = 0; i < r.size(); i++)
        cout<<r[i]<<endl;
    return 0;
}













































