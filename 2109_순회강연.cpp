#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main(){


    int n;
    cin >> n;
    int p , d;
    using T = pair<int,int>;
    priority_queue<T, vector<T>> pq;
    for(int i = 0 ; i<n; i++){
        cin >> p >> d;
        pq.push({p,d});
    }
    int sum = 0;
    int day = 1;
    
    int arr[10001] = {0,};

    while(pq.size()!= 0){
        int curP = pq.top().first;
        int curD = pq.top().second;
        pq.pop();
        while(arr[curD]!=0){
            curD--;
        }
        if(curD == 0) continue;
        arr[curD] = curP;
        sum += curP;
    }
    cout<<sum<<endl;
    
    

    return 0;
}