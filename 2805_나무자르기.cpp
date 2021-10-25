#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long arr[1000001];

int n,m;
long long high = 0;

long long comp(int value){
    long long ans = 0;
    for(int i = 0; i< n; i++){
        if(arr[i]-value > 0){
            ans += arr[i]-value;
        }
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        cin >> arr[i];
        high = max(arr[i],high);
    }
    
    int l = 0, r = high;
    long long ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(comp(mid) >= m){
            if(ans < mid)ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout<<ans<<endl;




    return 0;
}