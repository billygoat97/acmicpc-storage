#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;

int arr[1001];
vector<int> ans[3001];
vector<int> v;

int main(){
    for(int i = 2; i<=1000;i++){
        arr[i] = i;
    }
    for(int i = 2; i<=1000; i++){
        if(arr[i]==0)continue;
        for(int j = 2*i; j<=1000; j+=i){
            arr[j] = 0;
        }
    }
    for(int i = 2; i<=1000; i++){
        if(arr[i] == i)v.push_back(i);
    }
    for(int i = 0; i<v.size();i++){
        for(int j = 0; j<v.size();j++){
            for(int k = 0; k<v.size();k++){
                if(ans[v[i]+v[j]+v[k]].size()!= 0)continue;
                ans[v[i]+v[j]+v[k]].push_back(v[i]);
                ans[v[i]+v[j]+v[k]].push_back(v[j]);
                ans[v[i]+v[j]+v[k]].push_back(v[k]);
            }
        }
    }
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        sort(ans[inp].begin(), ans[inp].end());
        cout<< ans[inp][0] <<" "<< ans[inp][1] <<" "<< ans[inp][2]<<endl;
    }
    return 0;
}