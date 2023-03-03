#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> culMovePace(string strb){
    vector<int> arrMaxMatch;
    vector<int> movePace;
    int strbNum = strb.size();
    for(int i = 0; i < strbNum; i++)
        arrMaxMatch.push_back(0);
    int curMaxMatch = 0;
    for(int i = 1; i < strbNum; i++){
        while(curMaxMatch > 0 && strb[curMaxMatch] != strb[i])
            curMaxMatch = arrMaxMatch[curMaxMatch];
        if(strb[curMaxMatch] == strb[i])
            curMaxMatch++;
        arrMaxMatch[i] = curMaxMatch;
    }
    for(int i = 0; i < strbNum; i++){
        movePace.push_back(i+1-arrMaxMatch[i]);
    }
    return movePace;
}

int judgeAndReturnLocation(string stra,string strb){
    vector<int> strbMovePace = culMovePace(strb);
    int straNum = stra.size();
    int strbNum = strb.size();
    int l = 0;
    for(l;l <= straNum-strbNum; l++){
        int tmpl = l;
        int i = 0;
        while(i<strbNum){
            if(stra[tmpl] == strb[i]){
                i++;
                tmpl++;
            }
            else
                break;
        }
        if(i == strbNum)    break;
        l = l + strbMovePace[i];
    }
    return l;
} 

string newStr(int place,string stra,string strb,string strc){
    string frontStra = stra.substr(0,place);
    int beginPlace = place + strb.size();
    int length = stra.size() - beginPlace + 1; 
    string backStra = stra.substr(beginPlace,length);
    string result = frontStra + strc + backStra;
    return result;
}


int main(){
    string a,b,c;
    cin>>a>>b>>c;
    if(a.size() >= b.size()){
        int place = judgeAndReturnLocation(a,b);
        if(place >a.size()-b.size())
            cout<<a;
        else{
            cout<<newStr(place,a,b,c);
        }
    }
    else
        cout<<a;    
    return 0;
}