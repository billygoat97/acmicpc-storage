#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    int n,k;
    cin >>n>>k;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    sort(v.begin(),v.end());
    cout<<v[k-1];
}