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
vector<int >v;


int main(){

    priority_queue<int> pq;
    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    cin >>n;
    for(int i =0; i<n; i++){
        int inp;
        cin >> inp;
        if(inp == 0){
            if(pq.size() == 0){
                cout<<0<<'\n';
            }else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }else{
            pq.push(inp);
        }
    }
    
    
    return 0;
}
