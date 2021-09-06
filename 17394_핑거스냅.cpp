#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    int tc;
    
    int arr[1000001]={0,};
    for(int i = 2; i<=100000; i++){
        arr[i] = i;
    }
    for(int i = 2; i*i<=100000;i++){
        if(arr[i] == 0)continue;
        for(int j = i*i; j<=100000; j+=i){
            arr[j] = 0;
        }
    }


    cin >> tc;
    while(tc--){
        bool dp[1000001]={false,};
        int start, a,b;
        cin >> start >> a >> b;
        int flag = 0;
        for(int i = a; i<=b; i++){
            if(arr[i] !=0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout<<-1<<"\n";
            continue;
        }else{
            using T = pair<int,int>;
            queue<T> q;
            q.push({start,0});
            dp[start] = true;
            while(q.size()!= 0){
                
                int cur = q.front().first;
                int t = q.front().second;
                q.pop();
                
                if(cur>= a && cur <= b && arr[cur] != 0){
                    cout<<t<<"\n";
                    queue<T> empty;
                    swap(empty,q);
                    break;
                }else{
                    
                    int next = cur / 3;
                    if(dp[next]== false){
                        q.push({next,t+1});
                        dp[next] = true;
                    }
                    next = cur / 2;
                    if(dp[next]== false){
                        q.push({next,t+1});
                        dp[next] = true;
                    }
                    next = cur - 1;
                    if(dp[next]== false){
                        q.push({next,t+1});
                        dp[next] = true;
                    }
                    next = cur + 1;
                    if(next <= 1000000){
                        if(dp[next]== false){
                            q.push({next,t+1});
                            dp[next] = true;
                        }
                    }
                    
                }
            }
        }
    }
    return 0;
}