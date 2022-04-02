#include <iostream>
#include <vector>
using namespace std;
//双指针有两种
//第一种 记录0和1的终止位置
//第二种 记录0的终止位置 和 2的起始位置
//第一种
void sortColors_01(vector<int>& nums) {
        //0 1的终止位置初始值都为0
        int p0 = 0;
        int p1 = 0;
        for(int i = 0; i < nums.size(); ++i){
            //遇到0
            if(nums[i]==0){
                //交换当前与0终止位置的值
                swap(nums[i],nums[p0]);
                //如果p0终止位置小于p1终止位置 说明0之后是排好顺序的1 这时要把换出去的1填到p1终止位置
                if(p0<p1)
                    swap(nums[i],nums[p1]);
                //换0时 两个位置都要加1
                p0++;
                p1++;
                //遇到1时 直接交换p1终止节点与当前值1
            }else if(nums[i]==1){
                swap(nums[i],nums[p1]);
                p1++;
            }

        }
}
//第二种
void sortColors_02(vector<int>& nums) {
        //记录0的终止位置 与2的开始位置
        int p0 = 0;
        int p2 = nums.size()-1;
        //这里注意 一定要有等号i<=p2 因为p2 开始位置 不一定是2 只是代表它的下一个一定是2
        for(int i = 0; i <= p2; ++i){
            //用while的原因是 如果结尾都是二那么必须等p2位置移到2开始前
            while(nums[i]==2&&i<p2){
                swap(nums[i],nums[p2]);
                p2--;
            }
            //如果是0 交换即可
            if(nums[i]==0){
                swap(nums[i],nums[p0]);
                p0++;
            }

        }
    }

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        nums.push_back(tmp);
    }
    sortColors_02(nums);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}









