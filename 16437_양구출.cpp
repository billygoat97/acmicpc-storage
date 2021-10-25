#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class island{
    public:
        long long num = 0;
        int dest = 0;
};


island seom[130000];
int arr[130000] = {0,};


void dfs(int cur){
    if(cur == 1)return;
    int next = seom[cur].dest;

    if(seom[cur].num < 0){
        arr[next]--;
        arr[cur] = -1;
        if(arr[next] == 0)dfs(next);
        return;
    }
    seom[next].num += seom[cur].num;
    seom[cur].num = 0;
    arr[next]--;
    arr[cur] = -1;
    if(arr[next] == 0)dfs(next);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    
    for(int i = 0; i<=n; i++){
        arr[i] = 0;
    }
    char status;
    long long num;
    int dest;
    seom[1].num = 0;
    seom[1].dest = 0;
    for(int i = 2; i<=n; i++){
        cin >> status;
        cin >> num;
        cin >> dest;
        if(status == 'W')num *= -1;
        seom[i].num = num;
        seom[i].dest = dest;
        arr[dest]++;
    }

    for(int i = 2; i<= n; i++){
        if(arr[i] == 0 ){
            dfs(i);
        }
    }

    cout << seom[1].num <<"\n";

    return 0;
}