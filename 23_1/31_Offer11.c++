#include <iostream>
#include <vector>
using namespace std;
//线性方法简单
//二分法： 难点在于分 左排序和右排序
//在比较的时候只能用numbers[right]和numbers[mid]比较，因为左排序可能不存在而右排序一定存在
//1 2 3 4 5 和3 4 5 1 2 无法判断mid在哪个排序，但是numbers[right]一定在右排序
//左边小不一定往右移，右边小一定往左移
class Solution{
    public:
        int minArray(vector<int>& numbers){
            int left = 0, right = numbers.size() - 1;
            //还有这里不加left = right是因为当l=r时l和r同时指向最小值
            //否则right会减1再退出循环，只有返回numbers[left]是正确的
            while(left < right){
                int mid = left + (right - left)/2;
                if(numbers[right] > numbers[mid])   right = mid;
                else if(numbers[right] < numbers[mid]) left = mid + 1;
                else    right = right - 1; 
            }
            return numbers[left];
        }
};

int main(){
    vector<int> numbers{1,3,5};
    Solution* obj = new Solution();
    int result = obj->minArray(numbers);
    cout<<"result is "<<result<<endl;
    return 0;
}

