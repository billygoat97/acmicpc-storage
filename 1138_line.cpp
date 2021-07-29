#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#define BIG 1000000000

using namespace std;
int n;
int arr[11];
int out[11];

int main(){

  cin >> n;
  for(int i= 1; i<=n; i++){
    cin >> arr[i];
  }

  for(int i = 1; i<=n; i++){
    int imsi = arr[i];
    int cnt = 0;
    for(int j = 0; j<=imsi; j++){
      if(out[j]!= 0){
      cnt++;
      imsi++;
      }
    }
    while(out[imsi] != 0){
      imsi++;
    }
    out[imsi] = i;
  }

  for(int i = 0; i<n; i++){
    cout<<out[i]<<" ";
  }
  cout<<endl;
  return 0;
}