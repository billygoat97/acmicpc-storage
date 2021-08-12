#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main(){
    int arr[21][2];
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i][0];
    }
    for(int i = 1; i<=n; i++){
        cin >> arr[i][1];
    }
    int knapsack[21][100];
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<= 100;j++){
            if(i==0 || j == 0){
                knapsack[i][j] = 0;
            }else if(arr[i][0] <= j){
                knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-arr[i][0]]+ arr[i][1]);
            }else{
                knapsack[i][j] = knapsack[i-1][j];
            }
        }
    }
    
    cout<<knapsack[n][99]<<endl;
    return 0;
}