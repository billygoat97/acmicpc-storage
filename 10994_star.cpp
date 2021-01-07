#include <iostream>
using namespace std;

void star(int x1,int y1, int x2, int y2,int n, char** map);

int main(){
    int n;
    cin >> n;
    

    int x1 = 0, y1 = 0;
    int x2 = 4*n - 3, y2 = 4*n -3;
    char ** map = new char* [x2];
    for(int i = 0; i< x2; i++){
        map[i] = new char[x2];
    }
    for(int i = 0; i<x2;i++){
        for(int j = 0; j<y2;j++){
            map[i][j] = ' ';
        }
    }
    star(x1,y1,x2-1,y2-1,n,map);

    for(int i = 0; i<x2;i++){
        for(int j = 0; j<y2;j++){
            cout<<map[i][j];
        }
        cout<<endl;
    }

    return 0;
}

void star(int x1,int y1, int x2, int y2, int n, char** map){


    if(n!=1){
        for(int i = x1; i<=x2; i++){
            map[i][y1] = '*';
            map[i][y2] = '*';        
        }
        for(int i = y1; i<=y2; i++){
            map[x1][i] = '*';
            map[x2][i] = '*';        
        }
        star(x1+2,y1+2,x2-2,y2-2,n-1,map);
    }
    if(n==1){
        map[x1][y1]='*';
    }

    
}