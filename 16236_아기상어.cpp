#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int arr[20][20];
int n;
int x,y;
int shark_size = 2;
int shark_cnt = 0;
int cnt = 0;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
bool visited[20][20];
int addtime = 0;

using T = pair<pair<int,int>,int>;
vector<T> v;



int main(){
    // 9 -> 아기 상어 위치
    // 0 -> 빈칸
    // 1,2,3,4,5,6 물고기 크기
    cin >>n;
    for(int i = 0; i<n; i++){
        for(int j = 0 ;j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                x = i;
                y = j;
            }
        }
    }
    
    return 0;
}


