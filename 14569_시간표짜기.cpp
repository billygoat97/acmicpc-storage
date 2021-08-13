#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n,m;
int aaaaa;
int main(){
    cout<<aaaaa<<endl;
    unsigned long long arr[1001]={0,};
    unsigned long long check[10001]={0,};
    cin >> n;
    for(int i = 0; i<n ;i++){
        int len;
        cin >> len;
        for(int j = 0; j<len;j++){
            int inp;
            cin >> inp;
            arr[i] += (long long)1<<(inp-1);
        }
    }
    cin >> m; 
    for(int i = 0; i<m ;i++){
        int len;
        cin >> len;
        for(int j = 0; j<len;j++){
            int inp;
            cin >> inp;
            check[i] += (long long)1<<(inp-1);
        }
    }
    for(int i = 0; i<m; i++){
        int cnt = 0;
        for(int j = 0; j<n; j++){
            if((check[i] == (arr[j] | check[i])) && (check[i]!= 0 && arr[j]!= 0))cnt++;
        }
        cout<<cnt<<endl;
    }

}