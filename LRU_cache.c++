#include <iostream>
#include <map>
#include <list>
#include <utility>
using namespace std;
class LRUCache{
public:
    //首先强调一点---map的第一个int与list->pair的第一个int含义一致
    list<pair<int,int>> dataList;
    map<int,list<pair<int,int>>::iterator> dataMap;
    int cpty;

    LRUCache(int capacity){
        cpty = capacity;
    }
    
    int get(int key){
        //iter 是遍历器，find()返回值也是遍历器
        auto iter = dataMap.find(key);
        
        //如果找不到就返回 -1
        if (iter == dataMap.end()){
            return -1;
        }
        
        //如果找到了，就更新最近使用链表
        int val = iter->second->second;
        //把该值放在list（双向链表）首部，表示最近最常访问，余下的自动连接
        //首先清除该节点，然后再加入该节点到链表头部
        dataList.erase(iter->second);
        dataList.push_front({key,val});
        
        //下面这一步，主要是更新一下dataMap[key]的值，因为上面抹去了dataMap[key]的指针指向，如果不更新，现在的dataMap[key]是空指针
        dataMap[key] = dataList.begin();

        return val;
    }
    
    void put(int key,int value){
        //如果原map中有新增的值，则需要先删去该值并重新赋值
        auto iter = dataMap.find(key);
        if (iter != dataMap.end()){
            dataList.erase(iter->second);
            dataMap.erase(iter);
        }

        //如果cache满了，即map.size >= capacity 那么删除dataList最后一个，即map最不常访问的一个
        if (dataList.size() == cpty){
            auto iter = dataList.back();
            dataMap.erase(dataMap.find(iter.first));
            //删除链表最后一个，即最不常访问的一个   是否可以用erase删去最后一个？
            dataList.pop_back();
        }

        //将新数据添加至头部
        dataList.push_front({key,value});
        dataMap.insert({key,dataList.begin()});
    }

};
int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    int param_1 = obj->get(1);
    cout<<param_1<<endl;
    obj->put(3,3);
    int param_2 = obj->get(2);
    cout<<param_2<<endl;
    return 0;
}
