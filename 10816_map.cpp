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
    
    int n;
    cin >>n;
    map<int,int> m;
    vector<int>v;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    sort(v.begin(),v.end());
    for(int i = 0; i<v.size();i++){
        m[v[i]]++;
    }
    cin >> n;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        int a;
        cin >>a;
        cout<<m[a]<<' ';
    }
    cout<<'\n';

    return 0;
}
