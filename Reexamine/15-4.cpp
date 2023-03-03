#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> initMap(int n){
    vector<vector<int>> map;
    for(int i = 0; i < n; i++){
        vector<int> tmpArr;
        for(int j = 0; j < n ; j++){
            int tmpdata;
            cin>>tmpdata;
            tmpArr.push_back(tmpdata);
        }
        map.push_back(tmpArr);
    }
    return map;
}

vector<int> calLocation(int x,int y,int move){
    switch(move){
        case 0: x--;
        case 1: y--;
        case 2: x++;
        case 3: y++;
        default : ;
    }
    vector<int> result;
    result.push_back(x);
    result.push_back(y);
    return result;
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> map = initMap(n); 
    int x,y;
    cin>>x>>y;
    int move;
    cin>>move;
    vector<int> nowLocation = calLocation(x,y,move);
    if(map[nowLocation[0]][nowLocation[1]])
        cout<<'N'<<endl;
    else
        cout<<'Y'<<endl;    
    return 0;
}

