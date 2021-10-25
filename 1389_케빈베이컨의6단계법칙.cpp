#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n,m;
    cin >> n>>m;
    int arr[n+1][n+1];
    for(int i = 0; i<= n; i++){
        fill(arr[i], arr[i]+n+1,0);
    }
    for(int i = 0; i<m; i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            if(arr[i][j] == 0)arr[i][j] = 987654321;
        }
    }

    for(int k = 1; k<= n; k++){
        for(int i = 1; i<=n; i++){
            if(i == k) continue;
            for(int j = 1; j<= n; j++){
                if(i == j)continue;
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }

    int ans = 0;
    int baconNum = 987654321;
    for(int i = 1; i<= n; i++){
        int imsiBacon = 0;
        for(int j = 1; j<= n; j++){
            if(i == j)continue;
            imsiBacon += arr[i][j];
        }
        if(imsiBacon < baconNum){
            baconNum = imsiBacon;
            ans = i;
        }
    }
    cout<< ans <<"\n";

    return 0;
}