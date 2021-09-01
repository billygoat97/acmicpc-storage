#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#define INF 987654321
using namespace std;
int n;
int arr[11];
int oper[4];

int ansBig = -INF;
int ansSmall = INF;

void back(int cur, int num){

    if(num == n){
        ansSmall = min(cur , ansSmall);
        ansBig = max(cur,ansBig);
        return;
    }
    
    for(int i = 0; i<4; i++){
        if(oper[i] > 0){
            oper[i]-=1;
            if(i == 0)back(cur + arr[num], num+1);
            if(i == 1)back(cur - arr[num], num+1);
            if(i == 2)back(cur * arr[num], num+1);
            if(i == 3)back(cur / arr[num], num+1);
            oper[i]+=1;
        }
    }
    

}

int main(){

    cin >> n;
    for(int i = 0; i<n; i++)cin >> arr[i];
    for(int i = 0; i<4; i++)cin >> oper[i];

    back(arr[0],1);
    cout<<ansBig <<"\n" <<ansSmall;
    return 0;
}