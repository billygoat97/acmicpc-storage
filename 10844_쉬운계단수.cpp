#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define div 1000000000
using namespace std;


long long arr[100][10];
int main(){
    for(int i = 1; i<10; i++){
        arr[0][i] = 1;
    }
    int n;
    cin >> n;

    for(int i = 1; i<n; i++){
        arr[i][0] = arr[i-1][1]%div;
        arr[i][9] = arr[i-1][8]%div;
        for(int j = 1; j<9; j++){
            arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1])%div;
            
        }
    }
    long long ans = 0;
    for(int i = 0; i<10; i++){
        ans += arr[n-1][i];
        ans = ans % div;
    }
    cout<<ans;


    return 0;
}