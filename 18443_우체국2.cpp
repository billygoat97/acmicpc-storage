#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;


int main(){


    vector<int> v;
    int n,k,l;
    cin >> n >> k>>l;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    vector<int> diff,chk;
    for(int i = 0; i<v.size()-1; i++){
        diff.push_back(v[i+1]-v[i]);
        chk.push_back(v[i+1]-v[i]);
        //diff.push_back(min(v[i+1]-v[i],abs(l - v[i+1]-v[i])));
        //chk.push_back(min(v[i+1]-v[i],abs(l - v[i+1]-v[i])));
    }
    sort(chk.begin(), chk.end());
    int cur = 0;
    
    // for(int i = 0; i<diff.size(); i++){
    //     bool flag = false;
    //     for(int j = 0; j<chk.size()-k; j++){
    //         if(diff[i] == chk[j]){
    //             chk[j] = -1;
    //             flag = true;
    //             break;
    //         }
    //     }
    //     if(flag == false){
    //         cur += diff[i];
    //         cout<<cur<<" ";
    //     }
    // }
    long long ans = 0;
    if(chk.size() > k-1){
        for(int i = 0; i<chk.size()-k+1; i++){
            ans += chk[i];
        }
    }
    cout<<ans<<endl;
    cout<<"\n";

    return 0;
}