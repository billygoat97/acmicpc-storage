#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n;
int ans;
int cnt = 0;
int arr[20];
int comp[20];

void func(int tot, int k, int idx){
    if(tot == k){
        int imsi = 0;
        for(int i = 0; i<n; i++){
            imsi += comp[i];
        }
        if(imsi == ans)cnt++;
        return;
    }
    for(int i = idx; i<n;i++){
        comp[k] = arr[i];
        func(tot, k+1,i+1);
    }
}

int main(){

    cin >> n >> ans;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<=n;i++){
        func(i,0,0);
    }
    cout<<cnt<<'\n';

    return 0;
}