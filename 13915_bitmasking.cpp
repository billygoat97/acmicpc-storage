#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){

    
    int n;
    while(cin >>n){
        int arr[1001];
        for(int i = 0; i<n; i++){
            string str;
            cin >> str;
            arr[i] = 0;
            for(int j = 0; j<str.size();j++){
                int num = str[j] - '0';
                arr[i] = arr[i] | (1<<num);
            }
        }
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] == -1)continue;
            for(int j = i+1; j<n;j++){
                if(arr[i] == arr[j]){
                    arr[j] = -1;
                }
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}