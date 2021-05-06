#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;


int n,k;
int cnt =0;
int arr[128][128];
int bcnt=0, wcnt = 0;
bool check(int x1,int y1, int x2, int y2){
    int imsi = arr[x1][y1];
    for(int i = x1; i<x2;i++){
        for(int j = y1;j<y2;j++){
            if(imsi != arr[i][j])return false;
        }
    }
    if(imsi == 0){
        bcnt += 1;
    }else{
        wcnt += 1;
    }
    return true;

}

int func( int x1,int y1, int x2, int y2){
    int cnt=0;
    if(check(x1,y1,x2,y2)){
        return (x2-x1)*(y2-y1);
    }else{
        int mid1 = (x1+x2)/2;
        int mid2 = (y1+y2)/2;
        int ans = func(x1,y1,mid1,mid2) + func(mid1,y1,x2,mid2) + func(x1,mid2, mid1, y2) + func(mid1,mid2, x2,y2);
        return ans;
    }
}


int main(){

    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >>n;
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    
    int cnt = func(0,0,n,n);
    cout<< bcnt<<'\n' <<wcnt<<'\n';
    //cout<< cnt<<'\n';
    return 0;
}
