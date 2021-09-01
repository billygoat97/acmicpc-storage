#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
char arr[101][2]; // input
long long dp[101][2][20]; // must go // n, A, k 라고 하면 n 번째 블록왔을때 k 만큼을 맞춘 갯수,  A는 0,1번째 다리

int main(){

    string str, bridge1, bridge2;
    cin >> str >> bridge1 >> bridge2;
    int sz = bridge1.size();
    for(int i = 1; i<=sz; i++){
        arr[i][0] = bridge1[i];
        arr[i][1] = bridge2[i];
    }
    if(arr[0][0] == str[0]){
        dp[0][0][1] = 1;
    }
    if(arr[0][1] == str[0]){
        dp[0][1][1] = 1;
    }
    for(int i = 1; i < sz; i++){
        for(int j = 1; j<sz; j++){
            
        }
    }

    return 0;
}