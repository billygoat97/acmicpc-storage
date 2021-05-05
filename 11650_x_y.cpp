#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
using namespace std;

float func(float i){
    if(i == 0)return 1;

    return i*func(i-1);
}

int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    
    int n;
    cin >>n;
    vector<pair<int, int> > v;
    for(int i = 0; i<n; i++){
        int a,b;
        cin >>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    for(int i =0;i<v.size();i++){
        cout<< v[i].first <<' '<<v[i].second<<'\n';
    }
}
