#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int main(){
    
    
    int n;
    cin >>n;
    for(int i = 0; i<n; i++){
        vector<int> v;
        queue<pair<int,int> > q;
        int num, when,cnt = 0;
        cin >> num >> when;
        for(int j = 0; j<num;j++){

            int jungyo;
            cin>> jungyo;
            q.push(make_pair(j,jungyo));
            v.push_back(jungyo);
        }
        sort(v.rbegin(),v.rend());
        int ptr=0;
        while(q.empty() == false){
            // cout<<cnt;
            // cout<<endl;
            if(q.front().second == v[ptr]){
                cnt++;
                ptr++;
                if(q.front().first == when)break;
                q.pop();
            }else{
                q.push(q.front());
                q.pop();
            }
        }
        while(q.empty() == false){
            q.pop();
        }
        cout<<cnt<<endl;
        // v.clear();
    }

    return 0;
}
