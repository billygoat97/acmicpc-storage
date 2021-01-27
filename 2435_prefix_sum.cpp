#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n, k;
    cin >> n >>k;
    int arr[n];

    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    int sum[n-k+1];
    int MX=-9999999;
    
    for(int i = 0; i<n-k+1;i++){
        sum[i] = 0;
        for(int j = 0; j<k;j++){
            sum[i] += arr[i+j];
        }
        MX = max(MX, sum[i]);
    }
    // for(int i = 0; i<n-k+1;i++){
    //     cout<<sum[i]<<" ";
    // }
    // cout<<endl;
    cout<<MX<<endl;




    return 0;
}