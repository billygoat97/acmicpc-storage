#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

char corr1[8][8];
char corr2[8][8];

int main(){

    for(int i = 0; i<8; i++){
        for(int j = 0; j< 8;j++){
            if((i+j) %2 ==0){
                corr1[i][j] = 'B';
                corr2[i][j] = 'W';
            }else{
                corr1[i][j] = 'W';
                corr2[i][j] = 'B';
            }
        }
    }


    int n, m;
    cin >> n >> m;
    char arr[50][50];
    for(int i = 0; i< n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    int ans = 9999999;
    for(int i = 0; i<=n-8 ; i++){
        for(int j = 0; j<= m-8; j++){
            int cnt1 = 0, cnt2 = 0;
            for(int a = 0; a<8;a++){
                for(int b = 0 ; b<8; b++){
                    if(arr[i+a][j+b] != corr1[a][b])cnt1++;
                    if(arr[i+a][j+b] != corr2[a][b])cnt2++;
                }
            }
            //cout<< cnt1<<" "<< cnt2<<endl;
            ans = min(ans,min(cnt1,cnt2));

        }
    }

    cout<<ans<<endl;

    return 0;
}
