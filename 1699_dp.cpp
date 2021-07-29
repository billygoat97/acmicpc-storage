#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;

int n;

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  int dp[100001];
  
  for(int i = 1; i<=n; i++){
    dp[i] = i;
    for(int j = 1; j*j<=i; j++){
      dp[i] = min(dp[i], dp[i-j*j] + 1);
    }
  }
  cout<<dp[n]<<endl;

  return 0;
  
}