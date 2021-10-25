#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int bf[401][4];
int arr[22][22];
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
int main(){

    int n;
    cin >> n;
    

    for(int i = 0; i<= n+1; i++){
        arr[i][0] = -1;
        arr[0][i] = -1;
        arr[i][n+1] = -1;
        arr[n+1][i] = -1;
    }
    for(int a = 0; a< n*n; a++){
        int student;
        cin >> student;
        for(int i = 0; i<4; i++){
            int inp;
            cin >> inp;
            bf[student][i]=inp;
        }
        int happy = -1;
        int empty = -1;
        int x=-1,y=-1;
        for(int i = 1; i<= n; i++){
            for(int j = 1; j<= n; j++){
                int ihappy = 0;
                int iempty = 0;
                if(arr[i][j]!= 0)continue;
                for(int c = 0; c<4; c++){
                    int nx = i + dx[c];
                    int ny = j + dy[c];
                    int nn = arr[nx][ny];
                    if(nn == 0)iempty++;
                    if(nn == bf[student][0] || nn == bf[student][1] || nn == bf[student][2] || nn == bf[student][3] )ihappy++;
                }
                if(happy < ihappy){
                    x = i;
                    y = j;
                    happy = ihappy;
                    empty = iempty;
                }else if(happy == ihappy){
                    if(empty < iempty){
                        x = i;
                        y = j;
                        happy = ihappy;
                        empty = iempty;
                    }
                }
            }
        }
        arr[x][y] = student;
    }


    int tot = 0;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            int s = arr[i][j];
            int imsi = 0;
            for(int a = 0; a<4; a++){
                int nx = i + dx[a];
                int ny = j + dy[a];
                int f = arr[nx][ny];
                if(bf[s][0] == f || bf[s][1] == f ||bf[s][2] == f ||bf[s][3] == f)imsi++;
            }
            if(imsi == 1)tot += 1;
            if(imsi == 2)tot += 10;
            if(imsi == 3)tot += 100;
            if(imsi == 4)tot += 1000;
        }
    }
    cout<<tot<<"\n";



    return 0;
}