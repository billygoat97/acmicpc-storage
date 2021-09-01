#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

unsigned long long arr[1001];
unsigned long long check[10001];
int n,m;
int main(){
    
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