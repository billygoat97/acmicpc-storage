#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 987654321
using namespace std;

int main(){

    map<string, int> m;
    int n;
    cin >> n;
    for(int i = 0;i<n; i++){
        string str;
        cin >> str;
        m[str]++;
    }
    int cnt = 0;
    string name;
    for(auto it = m.begin();it!= m.end();it++){
        if(it->second > cnt){
            cnt = it->second;
            name = it->first;
        }else if(it->second == cnt){
            if(name > it->first){
                name = it->first;
            }
        }
    }
    cout<<name<<endl;


    return 0;
}