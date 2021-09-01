#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int arr[8] = {0,};
int ans[8] = {0,};
int visited[8] = {0,};
int sum = 0;
void comb(int k){
    if(k == n){
        int imsi = 0;
        for(int i = 0; i<n-1; i++){
            imsi += abs(ans[i] - ans[i+1]);
        }
        sum = max(imsi,sum);
        return;
    }
    for(int i = 0; i<n; i++){
        if(visited[i] == 0){
            visited[i] = 1;
            ans[k] = arr[i];
            comb(k+1);
            visited[i] = 0;
        }
    }
}

int main(){

    cin >> n;
    for(int i = 0; i<n;i++){
        cin >> arr[i];
    }
    comb(0);
    cout<<sum;

    return 0;
}