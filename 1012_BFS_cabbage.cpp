#include <iostream>
#include <queue>



int main(){

    int case_num;
    cin>> case_num;
    for(int p = 0; p<case_num;p++){
        int m,n,k; // m 가로 n 세로, k 개수
        cin>>m>>n>>k;
        int** array = new int*[n];
        int** visited = new int*[n];
        for(int i = 0; i<n;i++){
            array[i] = new int[m];
            visited[i] = new int[m];
            for(int j = 0;j<m;j++){
                array[i][j] = 0; // initialize zero;
                visited[i][j] = 0;
            }
        }
        
        for( int i = 0; i<k;i++){
            int a,b;
            cin >> a>>b;
            array[b][a] = 1;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(array[i][j])
            }
        }

        for(int i = 0; i< n;i++){
            delete[]array[i];
        }
        delete[] array;
    }
    

    return 0;
}