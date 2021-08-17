#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;
    int arr[9] = {0,};
    while(n!=0){
        int num = n%10;
        if(num == 9)num = 6;
        arr[num]++;
        n/=10;
    }
    arr[6] = arr[6]/2 + arr[6]%2;
    sort(arr,arr+9);
    cout<<max(1,arr[8])<<endl;



    return 0;
}