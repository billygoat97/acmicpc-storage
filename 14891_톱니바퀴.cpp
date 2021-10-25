#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;
int w[4]={0,}; // wheel 4
int check = 0b11111111;
int l[4] = {0,};
int r[4] = {0,};

void turn(int cnt, int dir){
    if(dir == 1){
        int c = w[cnt] &  1 << 7;
        w[cnt] = w[cnt] << 1;
        if(c != 0)w[cnt]+= 1;
    }else{
        int c = w[cnt] &  1;
        w[cnt] = w[cnt] >> 1;
        if(c != 0)w[cnt]+= 1 << 7;
    }
    w[cnt] = w[cnt] & check;
}


int main(){
    
    
    int instNum;
    int which, dir;
    string str;
    for(int i = 0; i<4; i++){
        cin >> str;
        for(int j = 0; j<8; j++){
            if(str[j] == '1')w[i] += 1<<(7-j);
        }
    }
    cin>> instNum;
    for(int inst = 0; inst<instNum; inst++){
        cin >> which >> dir;
        which--;
        dir = dir * -1;
        for(int i = 0; i<4; i++){
            l[i] = w[i] & 1 << 1;
            r[i] = w[i] & 1 << 5;
            if(l[i] != 0)l[i] = 1;
            if(r[i] != 0)r[i] = 1;
        }
        turn(which,dir);
        int cur = which;
        int curdir = dir;
        while(true){
            int next = cur + 1;
            int ndir = curdir * -1;
            if(next >=4)break;
            if(r[cur] == l[next])break;
            turn(next, ndir);
            cur = next;
            curdir = ndir;
        }
        cur = which;
        curdir = dir;
        while(true){
            int next = cur - 1;
            int ndir = curdir * -1;
            if(next < 0)break;
            if(l[cur] == r[next])break;
            turn(next, ndir);
            cur = next;
            curdir = ndir;
        }
        // for(int i = 0; i<4; i++){
        //     cout<<"w"<<i<<":"<<bitset<8>(w[i])<<endl;
        // }
    }
    int ans = 0;
    
    for(int i = 0; i<4; i++){
        // cout<<"w"<<i<<":"<<bitset<8>(w[i])<<endl;;
        int num = 0;
        if(w[i] & 1<<7)num = 1;
        ans += num * 1<<i;
    }
    cout<< ans <<"\n";

    return 0;
}