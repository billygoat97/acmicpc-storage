#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
int arr[10][10];
vector<int> v[10];
int euclid(int a, int b){
    int temp = a%b;

    if(temp == 0){
        return b;
    }else{
        return euclid(b,temp);
    }
}


int main(){
    cin >> n;
    int t_cnt = 0;
    for(int i = 0;i<n-1;i++){
        int a,b,p1,p2;
        cin >> a >> b>> p1 >> p2;
        for(int i = 9; i>1;i--){
            if(p1%i== 0 && p2 %i == 0){
                p1/=i;
                p2/=i;
            }
        }
        arr[a][b] = p1;
        arr[b][a] = p2;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i =0;i<n;i++){
        sort(v[i].begin(),v[i].end());
        t_cnt += v[i].size()-1;
    }

    while(1){
        int cnt = 0;
        for( int i = 0; i<n; i++){
            for(int j = 0; j<v[i].size()-1; j++){
                int gcd = euclid(arr[i][v[i][j]],arr[i][v[i][j+1]]);
                if((arr[i][v[i][j]])==arr[i][v[i][j+1]]) cnt++;
                int alpha = arr[i][v[i][j]]/gcd;
                int beta = arr[i][v[i][j+1]]/gcd;
                arr[i][v[i][j]] *= beta;
                arr[v[i][j]][i] *= beta;
                arr[v[i][j+1]][i] *= alpha;
                arr[i][v[i][j+1]] *= alpha;

                for(int k = 0; k<j;k++){
                    arr[i][v[i][k]]*= beta;
                    arr[v[i][k]][i]*= beta;
                }
            }

        }
        if(cnt == t_cnt)break;
    }
    
    for(int i = 0; i<n; i++){
        // for(int j = 0; j< v[i].size();j++)
        cout<<arr[i][v[i][0]]<<" ";
        // cout<<endl;
    }
    cout<<endl;


    return 0;
}