#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 987654321
using namespace std;

int dp[1000000];
int arr[1000000];
vector<int> v[1000000];
int n;

int main(){
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  dp[0]=1;
  v[0].push_back(arr[0]);
  for(int i = 1; i<n; i++){
    dp[i] = 1;
    v[i].push_back(arr[i]);
    for(int j = 0; j<i; j++){
      if(arr[i] > arr[j] && dp[j]+1 > dp[i]){
        dp[i] = dp[j]+1;
        copy(v[j].begin(),v[j].end(),v[i].begin());
        v[i].push_back(arr[i]);
      }
    }
  }
  int cnt = 0;
  int where;
  for(int i = 0; i<n; i++){
    if(dp[i] > cnt){
      cnt = dp[i];
      where = i;
    }
    
  }
  cout<<cnt<<endl;
  for(int i = 0; i<v[where].size(); i++){
    cout<<v[where][i]<<" ";
  }
  cout<<endl;
  

  return 0;
  
}