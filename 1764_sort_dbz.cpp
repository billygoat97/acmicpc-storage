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


int n,k;
int cnt =0;
vector<int >ans;
map<string,int> m;
bool visited[1001]={false,};
vector<string >v;



int main(){

    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >>n>>k;
    string str;
    for(int i = 0; i<n; i++){
        cin >>str;
        v.push_back(str);
        m[str]++;
    }
    for(int i = 0; i<k; i++){
        cin >>str;
        m[str]++;
    }
    vector<string> imsi;
    for(int i = 0; i<v.size();i++){
        if(m[v[i]] == 2){
            imsi.push_back(v[i]);
        }
    }
    sort(imsi.begin(),imsi.end());
    cout<<imsi.size()<<'\n';
    for(int i = 0; i<imsi.size();i++){
        cout<<imsi[i]<<'\n';
    }
    
    
    return 0;
}
