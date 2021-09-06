#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    priority_queue<string, vector<string>, greater<>> pq;
    int r, c;
    cin >> r >> c;
    char arr[20][20] = {'\0',};
    bool visited[20][20][2] = {false,};
    string str;
    for(int i = 0; i<r; i++){
        cin >> str;
        for(int j = 0; j<c; j++){
            arr[i][j] = str[j];
        }
    }
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            
            if(arr[i][j] == '#'){
                visited[i][j][0] = true;
                visited[i][j][1] = true;
                continue;
            }
            
            if(visited[i][j][0] == false){
                string imsi = "";
                int a = 0;
                while(i+a < r && arr[i+a][j]!='#'){
                    visited[i+a][j][0] = true;
                    imsi += arr[i+a][j];
                    a++;
                }
                if(imsi.size()>=2)pq.push(imsi);
            }
            if(visited[i][j][1] == false){
                string imsi = "";
                int a = 0;
                while(j+a < c && arr[i][j+a]!='#'){
                    visited[i][j+a][1] = true;
                    imsi += arr[i][j+a];
                    a++;
                }
                if(imsi.size()>=2)pq.push(imsi);
            }
            
        }
    }
    cout<<pq.top()<<"\n";
    
    return 0;
}