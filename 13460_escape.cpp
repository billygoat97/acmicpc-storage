#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int RposX, RposY;
int BposX, BposY;
int holeX, holeY;
int minimum = 11;


void bfs(int cnt, int rx, int ry, int bx, int by, char**arr);
bool check(int x, int y);
int main(){


    cin>> n>>m;
    char ** arr = new char*[n];
    for(int i = 0; i<n; i++){
        arr[i] = new char [m];
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'O'){
                holeX = i;
                holeY = j;
            }else if (arr[i][j] == 'R'){
                RposX = i;
                RposY = j;
            }else if (arr[i][j] == 'B'){
                BposX = i;
                BposY = j;
            }
        }
    }
    bfs(1,RposX,RposY,BposX,BposY,arr);


    if(minimum > 10 || minimum == -1){
        cout<<-1<<endl;
    }else{
        cout<<minimum<<endl;
    }



    return 0;
}

bool check(int x, int y){
    if(x == holeX&& y == holeY){
        return true;
    }else{
        return false;
    }
}


void bfs(int cnt, int rx, int ry, int bx, int by, char**arr){

    int imsi_rx=rx, imsi_ry=ry, imsi_bx=bx, imsi_by=by;
    
    if(cnt > 10){
        return;
    }

    for(int i = 0; i<4; i++){

        if( i == 0){ // up
            rx = imsi_rx;
            ry = imsi_ry;
            bx = imsi_bx;
            by = imsi_by;
            if(rx < bx){
                while(arr[rx-1][ry]!='#'){
                    rx-=1;
                    if(check(rx,ry)){
                        rx = 0, ry = 0;
                        break;
                    }
                }
                while(arr[bx-1][by]!='#'&&!(bx-1==rx && by ==ry)){
                    bx-=1;
                    if(check(bx,by)){
                        bx = 0;
                        by = 0;
                        break;
                    }
                }
            }else{
                while(arr[bx-1][by]!='#'){
                    bx-=1;
                    if(check(bx,by))if(check(bx,by)){
                        bx = 0;
                        by = 0;
                        break;
                    }
                }
                while(arr[rx-1][ry]!='#'&&!(rx-1==bx && by ==ry)){
                    rx-=1;
                    if(check(rx,ry)){
                        rx = 0, ry = 0;
                        break;
                    }
                }
            }
            if(bx== 0 && by == 0){
                continue;
            }else if(rx== 0 && ry == 0){
                minimum = min(cnt,minimum);
                return;
            }else{
                bfs(cnt+1,rx,ry,bx,by,arr);
            }
        }else if( i == 1){ // down
            rx = imsi_rx;
            ry = imsi_ry;
            bx = imsi_bx;
            by = imsi_by;
            if(rx > bx){
                while(arr[rx+1][ry]!='#'){
                    rx+=1;
                    if(check(rx,ry)){
                        rx = 0;
                        ry = 0;
                        break;
                    }
                }
                while(arr[bx+1][by]!='#'&&!(bx+1==rx && by ==ry)){
                    bx+=1;
                    if(check(bx,by)){
                        bx = 0;
                        by = 0;
                        break;
                    }
                }
            }else{
                while(arr[bx+1][by]!='#'){
                    bx+=1;
                    if(check(bx,by)){
                        bx = 0;
                        by = 0;
                        break;
                    }
                }
                while(arr[rx+1][ry]!='#'&&!(rx+1==bx && by ==ry)){
                    rx+=1;
                    if(check(rx,ry)){
                        rx = 0;
                        ry = 0;
                        break;
                    }
                }
            }
            if(bx== 0 && by == 0){
                continue;
            }
            else if(rx== 0 && ry == 0){
                minimum = min(cnt,minimum);
                return;
            }else{
                bfs(cnt+1,rx,ry,bx,by,arr);
            }
        }else if( i == 2){ // left
            rx = imsi_rx;
            ry = imsi_ry;
            bx = imsi_bx;
            by = imsi_by;
            if(ry < by){
                while(arr[rx][ry-1]!='#'){
                    ry-=1;
                    if(check(rx,ry)){
                        rx = 0, ry = 0;
                        break;
                    }
                }
                while(arr[bx][by-1]!='#'&&!(by-1==ry && bx ==rx)){
                    by-=1;
                    if(check(bx,by)){
                        bx = 0;
                        by = 0;
                        break;
                    }
                }
            }else{
                while(arr[bx][by-1]!='#'){
                    by-=1;
                    if(check(bx,by)){
                        bx = 0;
                        by = 0;
                        break;
                    }
                }
                while(arr[rx][ry-1]!='#'&&!(ry-1==by && bx ==rx)){
                    ry-=1;
                    if(check(rx,ry)){
                        rx = 0, ry = 0;
                        break;
                    }
                }
            }
            if(bx== 0 && by == 0){
                continue;
            }
            else if(rx== 0 && ry == 0){
                minimum = min(cnt,minimum);
                return;
            }else{
                bfs(cnt+1,rx,ry,bx,by,arr);
            }
        }else if( i == 3){ // rigjht
            rx = imsi_rx;
            ry = imsi_ry;
            bx = imsi_bx;
            by = imsi_by;
            if(ry > by){
                while(arr[rx][ry+1]!='#'){
                    ry+=1;
                    if(check(rx,ry)){
                        rx = 0, ry = 0;
                        break;
                    }
                }
                while(arr[bx][by+1]!='#'&&!(by+1==ry && bx ==rx)){
                    by+=1;
                    if(check(bx,by)){
                        bx = 0;
                        by = 0;
                        break;
                    }
                }
            }else{
                while(arr[bx][by+1]!='#'){
                    by+=1;
                    if(check(bx,by)){
                        bx = 0;
                        by = 0;
                        break;
                    }
                }
                while(arr[rx][ry+1]!='#'&&!(ry+1==by && bx ==rx)){
                    ry+=1;
                    if(check(rx,ry)){
                        rx = 0, ry = 0;
                        break;
                    }
                }
            }if(bx== 0 && by == 0){
                continue;
            }else if(rx== 0 && ry == 0){
                minimum = min(cnt,minimum);
                return;
            }else{
                bfs(cnt+1,rx,ry,bx,by,arr);
            }
        }


    }



    
}