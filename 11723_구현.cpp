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
vector<int >ans;
map<int,int> m;
bool visited[1001]={false,};
vector<int >v[1001];


int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >>n;
    
    int arr[21]={0,};
    for(int i = 0; i<n; i++){
        string str;
        cin >> str;
        int num;
        if(str == "add"){
            cin >> num;
            arr[num] = 1;
        }else if(str == "remove"){
            cin >> num;
            arr[num] = 0;
        }else if(str == "check"){
            cin >> num;
            if(arr[num] == 1){
                cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }else if(str == "toggle"){
            cin >> num;
            if(arr[num] == 1){
                arr[num] = 0;
            }else{
                arr[num] = 1;
            }
        }else if(str == "all"){
            for(int i = 1; i<=20; i++){
                arr[i] = 1;
            }
        }else if(str == "empty"){
            for(int i = 1; i<=20; i++){
                arr[i] = 0;
            }
        }
    }
    return 0;
}
