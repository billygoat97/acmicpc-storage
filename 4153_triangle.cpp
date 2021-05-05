#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>

using namespace std;


int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    vector<int>v;
    while(1){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0){
            break;
        }else{
            if(pow(a,2) + pow(b,2) == pow(c,2) ||pow(a,2) + pow(c,2) == pow(b,2) || pow(c,2) + pow(b,2) == pow(a,2)){
                cout<<"right"<<"\n";
            }else{
                cout<<"wrong"<<"\n";
            }
        }
    }


    return 0;
}
