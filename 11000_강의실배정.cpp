#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    using T = pair<int,int>;
    priority_queue<T, vector<T>, greater<>>pq;
    priority_queue<int, vector<int>, greater<>>bang;
    for(int i = 0; i<n; i++){
        int start, end;
        cin >> start >> end;
        pq.push({start,end});
    }
    int curEnd = 0;
    bang.push(0);
    while(pq.size()!=0){
        T cur = pq.top();
        pq.pop();
        curEnd = bang.top();
        if(cur.first >= curEnd){
            curEnd = cur.second;
            bang.pop();
            bang.push(curEnd);
        }else{
            bang.push(cur.second);
        }
    }
    cout<<bang.size()<<"\n";

    return 0;
}
