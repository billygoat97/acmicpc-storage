#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
vector<int> v;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        v.push_back(inp);
    }
    sort(v.begin(),v.end());
    int left=0, right = n-1;
    long long int ans = 9876543210;
    int l = 0, r = 0;
    while(left< right){
        long long int sum = v[left] + v[right];
        if (abs(sum) < ans)
		{
			ans = abs(sum);
			l = left, r = right;
			if (ans == 0)
				break;
		}
		if (sum < 0){
            left++;
        }	
		else{
            right--;
        }
			
    }
    cout<<v[l]<<' '<<v[r];

    return 0;
}