#include <iostream>
#include <cmath>
using namespace std;
// tromino tiling
int cnt = 0;
int arr[128][128];
bool chk(int x, int y, int size);
void recursion(int x, int y, int size);

int main(void){

    int flag = 0;
    int k;
    int a,b;
    cin >> k;

    
    cin >> a >> b;
    arr[b-1][a-1] = -1;

    recursion(0,0,pow(2,k));

    if (flag == 0){
        for(int i = pow(2,k)-1; i>=0;i--){
            for(int j = 0;j<pow(2,k);j++){
                cout<<arr[i][j] <<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<-1<<endl;
    }

    return 0;
}


bool chk(int x, int y, int size){
    for(int i = x;i< x+size; i++){
        for(int j = y; j<y+size;j++){
            if(arr[i][j]!=0){
                return false;
            }
        }
    }
    return true;
}

void recursion(int x, int y, int size){
    cnt++;
    size /=2;
    if(chk(x,y,size))arr[x+size-1][y+size-1] = cnt;
    if(chk(x,y+size,size))arr[x+size-1][y+size] = cnt;
    if(chk(x+size,y,size))arr[x+size][y+size-1] = cnt;
    if(chk(x+size,y+size,size))arr[x+size][y+size] = cnt;
    if(size == 1)return;
    recursion(x,y,size);
    recursion(x+size,y,size);
    recursion(x,y+size,size);
    recursion(x+size,y+size,size);

}