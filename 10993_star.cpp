#include <iostream>
#include <cmath>
using namespace std;


void star(int x1, int y1,int x2, int y2,int x3, int y3, int n, char** map);
int main(void){
    int n;
    cin >> n;
    int x_length = pow(2,n)-1;
    int y_length = pow(2,n+1)-3;

    char ** map = new char*[x_length];
    for(int i = 0; i< x_length;i++){
        map[i] = new char[y_length];
    }
    for(int i = 0; i< x_length;i++){
        for(int j = 0; j< y_length;j++){
            map[i][j] = ' ';
        }
    }
    
    if(n%2 == 0){
        star(0,0,0,y_length-1,x_length-1,(y_length-1)/2+1,n,map);
    }else{
        star(0,(y_length-1)/2,x_length-1,0,x_length-1,y_length-1,n,map);
    }

    if(n%2==0){
        for(int i = 0; i< x_length;i++){
            for(int j = 0; j< y_length-i;j++){
                cout<<map[i][j];
            }
            cout<<endl;
        }
    }else{
        for(int i = 0; i< x_length;i++){
            for(int j = 0; j< y_length/2+i+1;j++){
                cout<<map[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}


void star(int x1, int y1,int x2, int y2,int x3, int y3, int n, char** map){

    if(n!=1){
        if(n%2 == 0){  // even
            // for(int i = x1; i<=x3; i++){
            //     for(int j =y1;j<=y2;j++){
            //         if(i==x1){
            //             map[i][j]= '*';
            //         }
            //     }
            //     map[i][y1 + (i-x1)] = '*';
            //     map[i][y2 - (i-x1)] = '*';
            // }
            for(int i = x1;i<= x3;i++){
                for(int j = y1; j<=y2;j++){
                    map[x1][j] = '*';
                }
                map[i][y1+i-x1] = '*';
                map[i][y2-i+x2] = '*';
            }

            // map[x1][y1] = '*';
            // map[x2][y2] = '*';
            // map[x3][y3] = '*';
            star(x1+1,(y1+y2)/2,(x1+x3)/2,(y1+y3)/2+1,(x2+x3)/2,(y2+y3)/2-1,n-1,map);
        }else if(n%2== 1){ // odd
             map[x1][y1] = '*';
             map[x2][y2] = '*';
             map[x3][y3] = '*';
            for(int i = x1; i <= x2; i++){
                map[i][y1 + (i-x1)] = '*';
                map[i][y1 - (i-x1)] = '*';
            }

            for(int j =y2;j<=y3;j++){
                    map[x3][j]= '*';
            }
            
            
            star((x1+x2)/2,(y1+y2)/2+1,(x1+x3)/2,(y1+y3)/2-1,x2-1,(y2+y3)/2,n-1,map);
        }
    }

    if(n==1){
        map[x1][y1]='*';
    }
    
}