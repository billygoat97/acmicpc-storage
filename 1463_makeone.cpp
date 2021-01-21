#include <iostream>
#include <cmath>

using namespace std;

int dp[1000000];


int func(int n){

    if( n<= 3){
        return dp[n];
    }
    if( dp[n]>0 )return dp[n];
    dp[n] = func(n-1)+1;
    {
        if(n%3 == 0){
            dp[n] = min(dp[n],func(n/3)+ 1);
        }
        if(n%2 == 0){
            dp[n] = min(dp[n],func(n/2) + 1);
        }
        return dp[n];
    }


}
int main(){
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    int num;
    cin >> num;

    cout<<func(num)<<endl;
}