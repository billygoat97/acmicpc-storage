#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int arr[100][100];
int n;
int visited[100];

void graph(){
    for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0;j<n; j++){
                if(arr[i][k]==1 && arr[k][j] == 1){
                    arr[i][j] = 1;
                }
            }
        }
    }
}

int main(){

    
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    graph();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[i][j] <<" ";
        }
        cout<<endl;
    }


    return 0;
}