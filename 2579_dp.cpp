#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;
int n;
int dp[300];
int arr[300];

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  dp[0] = arr[0];
  dp[1] = arr[1] + arr[0];
  dp[2] = max(arr[0],arr[1]) + arr[2];

  for(int i = 3; i<n; i++){
    dp[i] = max(arr[i-1]+ arr[i] + dp[i-3] ,dp[i-2] + arr[i]);
  }
  cout<<dp[n-1];


  return 0;
  
}