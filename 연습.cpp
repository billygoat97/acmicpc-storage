#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){

    // string str = "aaabbcddcc";
    // string ans = "";
    // char cur = str[0];
    // int cnt = 0;
    // for(int i = 1; i<str.size(); i++){
    //     if(cur == str[i]){
    //         cnt++;
    //         continue;
    //     }
    //     ans += to_string(cnt + 1);
    //     ans += cur;
    //     cur = str[i];
    //     cnt = 0;
    // }
    // ans += to_string(cnt+1);
    // ans += cur;
    // cout<<ans<<endl;

    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    sort(v.begin(), v.end());
    int len = v.size();
    int ans = v[len-1];
    int cur = v[len-1];
    for(int i = len-1; i>= 0; i--){
        if(v[i]*(len-i) >= ans){
            ans = v[i]*(len-i);
        }else{
            continue;
        }
    }
    cout<< ans<<endl;

    return 0;
}