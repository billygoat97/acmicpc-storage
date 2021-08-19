#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> arr[n];

    for(int i = 0; i<n; i++){
        int a,b;
        cin >> a >> b;
        arr[i].push_back(b);
        arr[i].push_back(a);
    }
    sort(arr,arr+n);
    int cnt = 1;
    int cur = arr[0][0];
    for(int i = 1; i<n; i++){
        if(arr[i][1] >= cur){
            cnt++;
            cur = arr[i][0];
        }
    }
    cout<<cnt<<endl;
    // for(int i = 0; i<n; i++){
    //     cout<< arr[i][0] <<" "<< arr[i][1]<<endl;
    // }
    return 0;
}