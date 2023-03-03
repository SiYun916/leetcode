#include <iostream>
using namespace std;

bool judgeMove(int n,int x,int y,char move){
    switch(move){
        case 'w':   y++;
        case 's':   y--;
        case 'a':   x--;
        case 'd':   x++;
        default:    ;
    }
    if(x>=0&&x<=n-1&&y>=0&&y<=n-1)
        return true;
    else
        return false;
}


int main(){
    int N;
    cin>>N;
    int x,y;
    cin>>x>>y;
    char move;
    cin>>move;
    if(judgeMove(N,x,y,move))
        cout<<'Y'<<endl;
    else
        cout<<'N'<<endl;
    return 0;
}