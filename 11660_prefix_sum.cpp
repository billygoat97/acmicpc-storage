#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n,k;
    cin >> n >>k;
    int arr[1025][1025]={0,};
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=n; j++){
            cin >>arr[i][j];
        }
    }

    for(int i =1;i<=n;i++){
        for(int j = 1; j<=n;j++){
            arr[i][j] += arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1];
        }
    }
    for(int i = 0; i<k;i++){
        int f1,f2, t1,t2;
        cin >> f1>>f2>>t1>>t2;
        int imsi_sum = 0;
        
        imsi_sum += (arr[t1][t2]-arr[t1][f2-1] - arr[f1-1][t2]+arr[f1-1][f2-1]);
        
        cout<<imsi_sum<<"\n";
    }




    return 0;
}