#include <iostream>
#include <vector>
using namespace std;
//这道题模拟的方法做 应该不存在什么复杂度的陷阱
//但是我找了半天没有找到什么规律 想的方法太复杂了不知道从何下手
//还是按层模拟比较好理解
//用四个变量来限定最外层 对于最外层的元素依次按顺时针加入结果里面
//当left > right（或者top > bottom）时，说明最里面的一层也遍历完了就可以结束
//其实遍历最里面的一层时 有一个问题：如果top=bottom(或者left=right)，说明只有一层或一列 只需要从左到右（或从上到下）循环一次即可
//否则再执行一次从右到左 会重复记录
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); //行
        int n = matrix[0].size();//列
        int left = 0,right = n - 1;
        int top = 0,bottom = m -1;
        vector<int> res;
        while(left<=right&&top<=bottom){
            for(int col = left; col <= right; col++){
                res.push_back(matrix[top][col]);
            }
            for(int row = top + 1; row <= bottom; row++){
                res.push_back(matrix[row][right]);
            }
            if(left<right&&top<bottom){
                for(int col = right - 1; col>=left+1; col--){
                    res.push_back(matrix[bottom][col]);
                }
                for(int row = bottom; row>=top+1;row--){
                    res.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i =0 ; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>matrix[i][j];           
        }
    }
    vector<int> res;
    res = spiralOrder(matrix);
    for(int i =0 ; i < res.size();i++){
        cout<<res[i]<<" ";
    } 
    return 0;
}