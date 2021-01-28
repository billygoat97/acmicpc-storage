#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    int n,m;
    cin >> n >> m; // n은 총 갯수 , m은 확보해야 하는 바이트 수
    int arr[101][2];
    int cost_sum=0;
    for(int i = 1; i<= n; i++){
        cin >> arr[i][0]; // 0 은 용량(바이트)
    }
    for(int i = 1; i<= n; i++){
        cin >> arr[i][1]; // 1은 용량이 아니라 cost!
        cost_sum += arr[i][1];
    }

    int dp[n+1][cost_sum+1];
    int minimum_cost = 99999999; // 최대 cost (min으로 줄일 것)
    for(int i = 0; i<=n;i++){ // 전체 다 넣어보기
        for(int j = 0; j<=cost_sum; j++){ // 나올수 있는 최대 cost까지 돌려보기
            if(i == 0 || j == 0){ // 아무것도 없으면 0
                dp[i][j]= 0;
            }else if(arr[i][1]<=j){ // 만약에 이거 넣을 수 있는 cost다
                if(arr[i][0]+dp[i-1][j - arr[i][1]]>=m){ // 만약에 이거 넣으면 m을 충족
                    if(dp[i-1][j]>=m){ // 이전에 것도 충족하면
                        dp[i][j] = min(dp[i-1][j], arr[i][0]+dp[i-1][j - arr[i][1]]); // 적게 드는걸로 하는것
                    }else{
                        dp[i][j] = arr[i][0]+dp[i-1][j - arr[i][1]]; // 아니면 새거로 바꾸기
                    }
                    
                    if(dp[i][j]>=m){ // 만약에 이번에 거 충족하니
                        //cout<<"j: "<<j<<endl;
                        if(j < minimum_cost){
                            minimum_cost = j; // minimum cost로 슥삭 삭제
                        }
                    }
                }else{
                    dp[i][j] = max(arr[i][0]+dp[i-1][j - arr[i][1]], dp[i-1][j]); // 둘다 충족 못하면 그중에 큰걸로 대체하기
                }
                
            }else{
                dp[i][j] = dp[i-1][j]; // 이도저도 아니면 그전꺼 가져오기
            }
        }
    }
    // cout<<endl<<endl;
    // for(int i = 0; i<=n;i++){
    //     for(int j = 0; j<=cost_sum; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<minimum_cost<<endl;




    return 0;
}