#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long n,k;
// void mergesort(int s, int e);
// void merge(int s, int mid, int e);

int main(){

    cin >> n>>k;
    
    long long small = 1, big = k;
    long long ans;
    while(small <= big){
        long long mid = (small+big)/2;
        long long cnt = 0;
        for(int i = 1 ; i <= n; i++){
            cnt += min(mid/i, n);
        }

        if(cnt <k){
            small = mid+1;
        }else{
            ans = mid;
            big = mid-1;
        }
    }
    cout<<ans<<endl;


    // for(int i = 0 ;i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         v.push_back((i+1)*(j+1));
    //     }
    // }

    // int idx;
    // cin >> idx;
    // mergesort(0,n*n-1);
    // for(int i = 0 ; i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // cout<<v[idx-1]<<endl;


    return 0;
}




// void mergesort(int s, int e){

//     int mid = (s+e)/2;
//     if(s<e){
//         mergesort(s,mid);
//         mergesort(mid+1, e);
//         merge(s,mid,e);
//     }

// }

// void merge(int s, int mid, int e){
//     int i = s,j = mid+1;
//     vector<int> temp;
//     while(i<=mid && j <=e){
//         if(v[i] < v[j]){
//             temp.push_back(v[i]);
//             i++;
//         }else{
//             temp.push_back(v[j]);
//             j++;
//         }
//     }
//     while(i <= mid){
//         temp.push_back(v[i]);
//         i++;
//     }
//     while(j <= e){
//         temp.push_back(v[j]);
//         j++;
//     }

//     for(int i = s ; i<= e;i++){
//         v[i] = temp[i-s];
//     }
    

// }