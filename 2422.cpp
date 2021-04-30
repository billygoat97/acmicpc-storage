#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
//2422

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n >> m; // n  max m johab 

    vector<pair<int,int> > no;
    for(int i = 0 ;i<m ;i++){ //3가지는 고르기
        int a, b;
        cin >> a >> b;
        if( a > b){
            int z = a;
            a = b;
            b = z;
        }
        no.push_back(make_pair(a-1,b-1));
    }
    int cnt = n*(n-1)*(n-2);
    int count = 0;
    bool visited[200][200][200] = {false,};
    sort(no.begin(),no.end());
    for(int i = 0; i<no.size(); i++){
        // cout<<no[i].first << no[i].second<<endl;
        for(int j = 0; j<n; j++){
            if(visited[no[i].first][no[i].second][j]==true){

            }else if(no[i].second == j || no[i].first == j){
                
            }else{
                visited[no[i].first][no[i].second][j] = true;
                visited[no[i].first][j][no[i].second] = true; 
                visited[no[i].second][j][no[i].first]= true;
                visited[no[i].second][no[i].first][j]= true;
                visited[j][no[i].second][no[i].first]= true;
                visited[j][no[i].first][no[i].second]= true;
                count++;
            }
        }
        
    }

    cnt = (cnt/6 -count);

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<n; j++){
    //         for(int k = 0; k< n; k++){
    //             if( i == j || j == k || i == k){
                    
    //             }else{
    //                 int q,w;
    //                 int flag = 0;
    //                 for(int a = 0; a<no.size(); a++){
    //                     q = no[a].first;
    //                     w = no[a].second;
    //                     if((q == i && w == j)|| (q == j && w == i)|| (q == i && w == k)|| (q == k && w == i)|| (q == j && w == k)|| (q == k && w == j)){
    //                         flag = 1;
    //                         break;
    //                     }
    //                 }
    //                 if (flag == 0)cnt++;

    //             }
    //         }
    //     }
    // }
    // cnt/=6;
    cout<<cnt;
    return 0;
}
