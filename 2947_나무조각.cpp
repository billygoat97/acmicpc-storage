#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){

    int arr[5]={0,};
    for(int i = 0; i<5; i++){
        cin >> arr[i];
    }
    while(!(arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5)){
        for(int i = 0; i<4; i++){
            if(arr[i] > arr[i+1]){
                int imsi = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = imsi;
                for(int i = 0; i<5; i++){
                    cout<<arr[i] <<" ";
                }
                cout<<"\n";
            }
        }
        
    }


    return 0;
}