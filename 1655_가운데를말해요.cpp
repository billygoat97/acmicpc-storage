#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<int> minpq;
    priority_queue<int, vector<int>, greater<int>> maxpq;
    int n;
    cin >> n;
    int inp;
    for(int i = 0; i<n; i++){
        cin >> inp;
        if(maxpq.size()== minpq.size()){
            maxpq.push(inp);
        }else{
            minpq.push(inp);
        }
        if(maxpq.size()!=0 && minpq.size()!=0){
            if(maxpq.top() < minpq.top()){
                int a = maxpq.top();
                int b = minpq.top();
                maxpq.pop();
                minpq.pop();
                maxpq.push(b);
                minpq.push(a);
            }
        }
        if(maxpq.size() == minpq.size()){
            cout<<minpq.top()<<"\n";
        }else{
            cout<<maxpq.top()<<"\n";
        }
    }
    return 0;
}