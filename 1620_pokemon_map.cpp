#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

float func(float i){
    if(i == 0)return 1;

    return i*func(i-1);
}

int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    
    int n,k;
    map<string, int>si;
    map<int, string> is;

    cin >>n >>k;
    for(int i = 1; i<=n;i++){
        string str;
        cin >> str;
        si[str] =i;
        is[i] = str;
    }
    for(int i = 0; i<k; i++){
        string ans;
        cin >> ans;
        if(int(ans[0])-65>= 0 &&int(ans[0])-65<= 26){
            cout<<si[ans]<<'\n';
        }else{
            
            cout<<is[stoi(ans)]<<'\n';
        }

    }
    //cout<<"=="<<si["1"]<<endl;
    return 0;
}
