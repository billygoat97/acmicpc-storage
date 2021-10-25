#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


int main(){

    vector<int> v;
    int n,k;
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<int> diff;
    for(int i = 0; i<v.size()-1; i++){
        diff.push_back(v[i+1]-v[i]);
    }
    sort(diff.begin(), diff.end());
    long long ans = 0;
    if(diff.size() > k-1){
        for(int i = 0; i<diff.size()-k+1; i++){
            ans += diff[i];
        }
    }
    
    cout<<ans <<endl;

    return 0;
}