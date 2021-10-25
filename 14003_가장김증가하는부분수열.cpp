#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;
    vector<int>v;
    vector<int>from;
    int arr[n+1];
    int path[n+1];
    fill(path, path+n+1, 0);
    fill(arr, arr+n+1, 0);
    int inp;
    int endidx = 0;
    v.push_back(-1000000001);  // 기본 세팅
    from.push_back(0);
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        int idx = (lower_bound(v.begin(),v.end(),arr[i]) - v.begin());
        if(idx+1 > v.size()){ // 뒤에 붙는거
            
            v.push_back(arr[i]);
            path[i] = from[from.size()-1];
            from.push_back(i);
        }else{ // 이건 자리 바꾸는거...!
            // from[i] = v[idx];
            v[idx] = arr[i];
            from[idx] = i;
            idx--;
            path[i] = from[idx];
            //path[from[idx]] = i;
            
            
        }
        // for(int i = 1 ;i<= n;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 1; i<=n; i++){
        //     cout<<path[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"===============\n";
    }

    
    // =====================================================================//
    int vs =v.size();
    cout<<vs-1<<"\n";
    priority_queue<int,vector<int>,greater<>>pq;
    int start = v[vs-1];
    int curidx = n;
    while(true){
        if(arr[curidx] == start)break;
        curidx--;
    }
    while(curidx != 0){
        pq.push(arr[curidx]);
        curidx = path[curidx];
    }
    while(pq.size()!= 0){
        cout<< pq.top()<<" ";
        pq.pop();
    }
    

    return 0;
}