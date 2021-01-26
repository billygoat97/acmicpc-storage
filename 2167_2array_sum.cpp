#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int arr[301][301]={0,};
    int n, m;
    cin >> n >> m;

    for(int i =1; i<=n;i++){
        for(int j = 1; j<=m; j++){
            cin >> arr[i][j];
        }
    }

    long long sum[301][301]={0,};

    for(int i =1;i<=n;i++){
        for(int j = 1; j<=m;j++){
            sum[i][j] += sum[i][j-1]+arr[i][j];
        }
    }

    int inpNum;
    cin >>inpNum;

    for(int i = 0; i<inpNum;i++){
        int f1,f2,t1,t2;
        int imsi_sum=0;
        cin >> f1>>f2>>t1>>t2;
        for(int a = f1;a<=t1;a++){
            imsi_sum += (sum[a][t2]-sum[a][f2-1]);
        }
        cout<<imsi_sum<<endl;
    }

    return 0;
}