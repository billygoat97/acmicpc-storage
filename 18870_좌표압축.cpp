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
vector<int >v;
vector<int >ans;
map<int,int> m;


int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >>n;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
        ans.push_back(inp);
        m[inp] = 0;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 0; i<v.size();i++){
        m[v[i]] = i;
    }

    for(int i = 0; i<ans.size();i++){
        cout<<m[ans[i]]<<" ";
    }
    cout<<endl;

    
    return 0;
}
