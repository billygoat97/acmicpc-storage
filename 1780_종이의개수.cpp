#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int cnt[3] = {0,};
int arr[2200][2200]={0,};

bool check(int x1, int y1, int x2, int y2){

    int imsi = arr[x1][y1];
    for(int i = x1; i<x2; i++){
        for(int j = y1; j <y2; j++){
            if(arr[i][j] != imsi){
                int sz = (x2 - x1) / 3;
                for(int a = 0; a<3; a++){
                    for(int b = 0; b<3; b++){
                        check(x1+ a*sz, y1 + b*sz, x1+ (a+1)*sz, y1 + (b+1)*sz);
                    }
                }
                return false;
            }
        }
    }
    cnt[imsi]++;
    return true;
}

int main(){

    cin >> n;
    for(int i = 0; i<n;i++){
        for(int j = 0; j< n; j++){
            cin >> arr[i][j];
            arr[i][j]++;
        }
    }
    check(0,0,n,n);
    
    for(int i = 0; i<3; i++){
        cout<<cnt[i]<<"\n";
    }


    return 0;
}