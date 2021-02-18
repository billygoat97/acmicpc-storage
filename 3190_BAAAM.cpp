#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector< pair<int,int> >baam;
int direc[10000]={0,}; // 0은 아무것도 안하고,1은 좌회전, -1는 우회전
int map[100][100]={0,};
int n,k,l; // n: 맵 크기, k : 사과 갯수, l 방향 direction
int livetime = 0;
int curdir = 3;// right,up,left,down;
int main(){
    
    cin >> n;
    cin >> k;
    for(int i = 0; i<k; i++){
        int ax, ay;
        cin >> ax >> ay;
        map[ax-1][ay-1] = 2; // apple
    }
    baam.push_back(make_pair(0,0));
    map[0][0] = 1;
    cin >> l;
    for(int i = 1; i<= l; i++){
        int T;
        char dir;
        cin >> T >> dir;
        if(dir == 'L')direc[T] = 1;
        if(dir == 'D')direc[T] = -1;
    }
    while(1){
        // curdir += direc[livetime];
        // 1 left, -1 down //0123 right up left down
        if(curdir == 0){ //right
            if(direc[livetime]==-1){ 
                curdir = 1;
            }else if(direc[livetime]==1){
                curdir = 3;
            }
        }else if(curdir == 1){//up
            if(direc[livetime]==-1){
                curdir = 2;
            }else if(direc[livetime]==1){
                curdir = 0;
            }
        }else if(curdir == 2){//left
            if(direc[livetime]==-1){//l
                curdir = 3;
            }else if(direc[livetime]==1){//r
                curdir = 1;
            }
        }else if(curdir == 3){//down
            if(direc[livetime]==-1){//l
                curdir = 0;
            }else if(direc[livetime]==1){
                curdir = 2;
            }
        }
        // if(curdir==0){
        //     cout<<"right"<<endl;
        // }else if(curdir==1){
        //     cout<<"up"<<endl;
        // }else if(curdir==2){
        //     cout<<"left"<<endl;
        // }else if(curdir==3){
        //     cout<<"down"<<endl;
        // }
        
        
        livetime++;
        int nx,ny,lx,ly;
        int next;
        int bs = baam.size()-1;
        if(curdir == 0){ // right
            nx = baam[0].first+1;
            ny = baam[0].second;
            lx = baam[bs].first;
            ly = baam[bs].second;
            if(nx >=n)break;
            next = map[nx][ny];
        }else if(curdir == 1){ // up
            nx = baam[0].first;
            ny = baam[0].second-1;
            lx = baam[bs].first;
            ly = baam[bs].second;
            if(ny <0)break;
            next = map[nx][ny];
        }else if(curdir == 2){ // left 
            nx = baam[0].first-1;
            ny = baam[0].second;
            lx = baam[bs].first;
            ly = baam[bs].second;
            if(nx <0)break;
            next = map[nx][ny];            
        }else if(curdir == 3){ // down
            nx = baam[0].first;
            ny = baam[0].second+1;
            lx = baam[bs].first;
            ly = baam[bs].second;
            if(ny >=n)break;
            next = map[nx][ny];            
        }
        
        if(next == 2){
                map[nx][ny] = 1;
                baam.insert( baam.begin(), make_pair(nx,ny) );
        }else if(next == 0){
            map[nx][ny] = 1;
            map[lx][ly] = 0;
            baam.insert( baam.begin(), make_pair(nx,ny) );
            baam.pop_back();
        }else if (next == 1){
            // if(nx == lx && ly == ny){ // okay
            //     baam.insert( baam.begin(), make_pair(nx,ny) );
            //     baam.pop_back();
            // }else{
            //     break;
            // }
            break;
            
        }
        
        
    }



    cout<< livetime<<endl;
    return 0;
}