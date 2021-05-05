#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>

using namespace std;


int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    vector<int>v;
    int n;
    cin >>n;
    for(int i = 0; i<n; i++){
        int a;
        cin >>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 0; i<v.size();i++){
        cout<<v[i]<<'\n';
    }
    
    


    return 0;
}
