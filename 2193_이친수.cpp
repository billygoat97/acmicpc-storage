#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;
    long long arr[n+1][2] = {0,};
    arr[1][1] = 1;
    arr[1][0] = 0;
    for(int i = 2; i<=n;i++){
        arr[i][0] = arr[i-1][0] + arr[i-1][1];
        arr[i][1] = arr[i-1][0];
    }
    cout<<arr[n][0] + arr[n][1]<<endl;

    return 0;
}