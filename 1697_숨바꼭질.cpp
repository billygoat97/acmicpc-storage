#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



int main(){

    int n,k;
    cin >> n >>k;
    using T = pair<int,int>;
    queue<T> q;
    


    q.push({n,0});
    int visited[100001] = {0,};
    fill(visited, visited + 100001, -1);
    while(q.size()!= 0){
        int pos = q.front().first;
        int time = q.front().second;
        if(visited[pos]!= 0){
            visited[pos] = time;
        }
        if(pos == k){
            cout<<time<<endl;
            break;
        }
        q.pop();
        int npos;
        
        npos = pos + 1;
        if(npos < 0 || npos > 100000 || visited[npos] != -1){
            
        }else{
            q.push({npos,time+1});
        }
        npos = pos - 1;
        if(npos < 0 || npos > 100000 || visited[npos] != -1){
            
        }else{
            q.push({npos,time+1});
        }
        npos = pos * 2;
        if(npos < 0 || npos > 100000 || visited[npos] != -1){
            
        }else{
            q.push({npos,time+1});
        }
    }

    return 0;
}