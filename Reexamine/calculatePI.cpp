#include <iostream>
using namespace std;

typedef struct node{
    int val;
    node* pre;
    node* next;
}listNode,*linkList;

void pushNode(linkList head,int data){
    linkList tmpHead = head;
    listNode* p =(listNode*)malloc(sizeof(listNode));
    if(tmpHead == NULL)
        return ;
    while(tmpHead->next)
        tmpHead = tmpHead->next;
    p->val = data;
    p->next = NULL;
    tmpHead->next = p;
    p->pre = tmpHead;
}

linkList calculate(){
    linkList sumHead = (listNode*)malloc(sizeof(listNode));
    linkList itemHead = (listNode*)malloc(sizeof(listNode));
    sumHead->next = NULL;sumHead->pre=NULL;
    itemHead->next = NULL;itemHead->pre=NULL;
    for(int i = 0; i < 520; i++){
        pushNode(sumHead,0);
        pushNode(itemHead,0);
    }
    linkList sumTmp = sumHead->next;
    linkList itemTmp = itemHead->next;
    sumTmp->val = 2;
    itemTmp->val = 2;
    while(sumTmp->next!=NULL){
        sumTmp = sumTmp->next;
    }
    while(itemTmp->next!=NULL){
        itemTmp = itemTmp->next;
    }
    linkList sumTail = sumTmp;
    linkList itemTail = itemTmp;
    int tmpNum = 0;
    int ret;
    for(int i = 1,t = 3; i < 10000;i++,t = t + 2){
        listNode* p1 = itemTail;
        ret = 0;
        while(p1){
            tmpNum = p1->val*i + ret;
            p1->val = tmpNum % 10;
            ret = tmpNum / 10;
            p1 = p1 -> pre;
        }
        ret = 0;
        p1 = itemHead->next;
        while(p1){
            tmpNum = p1->val + 10*ret;
            p1->val = tmpNum / t;
            ret = tmpNum % t;
            p1 = p1->next;
        }
        p1 = itemTail;
        linkList p2 = sumTail;
        ret = 0;
        while(p1&&p2){
            tmpNum = p1->val + p2->val + ret;
            p2->val = tmpNum % 10;
            ret = tmpNum / 10;
            p2 = p2->pre;
            p1 = p1->pre;
        }
    }
    return sumHead;
}

void output(linkList head,int n){
    head = head->next;
    cout<<head->val<<'.';
    head = head->next;
    for(int i = 0; i < n ; i++){
        cout<<head->val;
        head = head->next;
    }
}

int main(){
    linkList head = calculate();
    int n;
    cin>>n;
    output(head,n);
    return 0;
}



