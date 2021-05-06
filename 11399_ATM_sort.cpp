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
map<int,int> m;
bool visited[1001]={false,};
vector<int >v;


int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >>n;
    for(int i =0; i<n; i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    sort(v.begin(),v.end());
    int sum = 0;
    int s = v.size();
    for(int i = 0; i<s; i++){
        sum += v[i]*(s-i);
    }
    cout<< sum<<'\n';
    
    return 0;
}
