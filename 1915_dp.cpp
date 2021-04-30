#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;

int arr[1002][1002] = {0,};
int dp[1002][1002] = {0,};
int main(){

    cin >> n >>m;

    

    for(int i = 1 ; i<=n; i++){
        string str;
        cin >> str;
        for(int j = 1; j<=m; j++){
            arr[i][j] = str[j-1] - 48;
            if(arr[i][j] == 1)dp[i][j] = 1;
        }
    }

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=m; j++){
            if(arr[i][j]== 1){
                if(dp[i-1][j] == 0 || dp[i][j-1] == 0 || dp[i-1][j-1]==0){ // 두번쨰로 작은 정사각형 조건 x아ㅏㅏㅏㅏㅏ  dp[i][i-1]이라고 써놨었네 뇌 없네 진짜

                }else{ // 두번째로 작은 정사각형 이상 되는거니 일단 
                    double a = sqrt(dp[i-1][j]);
                    double b = sqrt(dp[i][j-1]);
                    double c = sqrt(dp[i-1][j-1]);
                    double imsi = min(min(a,b),c);
                    dp[i][j] = pow((1 + imsi),2);
                }
            }
        }
    }
    double max = 0;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=m; j++){
            if(dp[i][j] > max)max = dp[i][j];
        }
    }
    cout<< max<<endl;

    return 0;
}
