#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cmath>
#include <deque>
using namespace std;

float func(float i){
    if(i == 0)return 1;

    return i*func(i-1);
}

int main(){


    ios::sync_with_stdio(0);cin.tie(0), cout.tie(0);
    
    int n,k;
    cin >>n>>k;
    queue<int> q;
    for(int i = 0; i<n; i++){
        q.push(i+1);
    }
    cout<<"<";
    int cnt = 0;
    while(q.empty()==false){
        cnt++;
        if(cnt == k){
            cnt = 0;
            cout<<q.front();
            q.pop();
            if(q.size() !=0){
                cout<<", ";
            }
        }else{
            q.push(q.front());
            q.pop();
        }
    }
    cout<<">"<<'\n';
    return 0;
}
