#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(){

    int a,b;
    cin >> a >> b;
    vector<int>v1,v2;
    for(int i = 0; i<a; i++){
        int inp;
        cin >> inp;
        v1.push_back(inp);
    }
    for(int i = 0; i<b; i++){
        int inp;
        cin >> inp;
        v2.push_back(inp);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int cnt = 0;
    int imsi = 0;
    for(int i = 0; i<v1.size(); i++){
        for(int j = imsi; j<v2.size();j++){
            if(v1[i] == v2[j]){
                cnt++;
                imsi = j;
                break;
            }else if(v1[i] < v2[j]){
                imsi = j;
                break;
            }
        }
    }
    cout<<v1.size() + v2.size() - 2*cnt<<endl;



    return 0;
    
    
}