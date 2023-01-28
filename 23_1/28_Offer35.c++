//emmmm这道题的输入比较复杂，不打算写完整代码了
//主要记录思路：
//这道题我觉得本质应该是考深拷贝，难点在于random的指针如何构建
//一开始我直接return head;发现报错not a copy but a reference
//看了题解  用哈希
class Solution{
public:
    unordered_map<Node*,Node*> hashMap;
    Node* copyRandomList(Node* head){
        Node* cur = head;
        //这里根据旧类的val构建新的Node类，并将旧的类映射到新类。这里的next和random指针并未指向正确的
        while(cur){
            hashMap[cur] = new Node(cur->val);
            cur = cur->next;
        }
        //构建next和random关系
        cur = head;
        while(cur){
            hashMap[cur]->next = hashMap[cur->next];
            hashMap[cur]->random = hashMap[cur->random];
            cur = cur->next;
        }
        //映射的新类建立好指向关系，所以返回的是映射到的新类的地址
        return hashMap[head];
    }
};
