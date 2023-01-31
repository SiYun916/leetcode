#include <iostream>
#include <vector>
using namespace std;
//题解思路：
//把矩阵逆时针旋转90°，就形成了一个类似二叉搜索树的东西
//左边的值全部小于父节点，右边的值全部大于父节点
//如果target小于父节点，往左找列变小；target大于父节点，往右找行变大
//基于这个思想，以右上角的点为根节点寻找
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)  return false;
        int i = 0, j =matrix[0].size() - 1;
        while(i <= matrix.size() - 1 && j >= 0){
            if(target > matrix[i][j])   i++;
            else if(target < matrix[i][j])  j--;
            else   return true;
        }
        return false;
    }
};
int main(){
    vector<vector<int>> matrix = {{-5}};
    int target = -5;
    Solution* obj = new Solution();
    bool judge = obj->findNumberIn2DArray(matrix,target);
    cout<<"result is "<<judge<<endl;
    return 0;
}
