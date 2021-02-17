#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<long long int> A,B,C,D;
    int n; 
    cin >> n;
    long long cnt = 0;
    for(int i = 0; i<n; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }
    vector<long long int> AB, CD;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            AB.push_back(A[i]+B[j]);
            CD.push_back(C[i]+D[j]);
        }
    }
    sort(CD.begin(), CD.end());
    for(int i = 0; i<AB.size(); i++){
        long long imsi = upper_bound(CD.begin(),CD.end(),AB[i]*(-1))-lower_bound(CD.begin(),CD.end(),AB[i]*(-1));
        if (imsi >0){
            cnt += imsi;
        }
    }
    
    cout<<cnt<<endl;

    return 0;
}