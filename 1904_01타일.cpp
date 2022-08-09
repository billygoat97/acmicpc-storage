#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


int arr[1000000] = {0,};
int main(){

    int n;
    cin >> n;
    n--;
    arr[0] = 1;
    arr[1] = 2;
    for(int i = 2; i<=n; i++){
        arr[i] = (arr[i-1] + arr[i-2])% 15746;
    }
    cout<< arr[n]<<endl;
    return 0;
}