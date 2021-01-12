#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int M = 0;
int func(int ** arr);
int** func_up(int ** arr);
int** func_right(int ** arr);
int** func_left(int ** arr);
int** func_down(int ** arr);
int n = 0;
int main(){

    

    cin >> n;
    int** arr = new int*[n];
    for(int i = 0; i<n; i++){
        arr[i] = new int[n];
    }

    for(int i = 0; i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[j][i];
        }
    }
    int result;
    result = func(arr);
    cout<< result<<endl;

    return 0;
}


int func(int ** arr){

    int** copy_imsi = new int*[n];
    for(int j = 0; j<n; j++){
        copy_imsi[j] = new int[n];
    }
    for(int i = 0; i<1024;i++){
        int imsi = i;
        int count = 0;
        
        for(int j = 0; j<n;j++){
            for(int k = 0; k<n; k++){
                copy_imsi[k][j] = arr[k][j];
            }
        }
        while(count<5){
            if(imsi%4 == 0){
                copy_imsi = func_up(copy_imsi);
            }else if(imsi%4 == 1){
                copy_imsi = func_right(copy_imsi);
            }else if(imsi%4 == 2){
                copy_imsi = func_left(copy_imsi);
            }else if(imsi%4 == 3){
                copy_imsi = func_down(copy_imsi);
            }
            imsi /= 4;
            count++;
        }
        int imsi_max= 0;
        for(int j = 0;j<n;j++){
            for(int k = 0; k<n; k++){
                if(imsi_max < copy_imsi[j][k])
                imsi_max = copy_imsi[j][k];
            }
        }
        if( imsi_max > M){
            M = imsi_max;
        }
        
    }





    return M;
}
int** func_up(int ** arr){
    for(int i = 0; i<n;i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(arr[i][j]!=0){
                arr[i][count]=arr[i][j];
                if(j!=count){
                    arr[i][j] = 0;
                }
                count++;
            }
        }
    }

    /////////////////////////
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n-1;j++){
            if(arr[i][j]!=0){
                if(arr[i][j]==arr[i][j+1]){
                    arr[i][j]+=arr[i][j];
                    arr[i][j+1] = 0;
                }
            }
        }
    }
    /////////////////////////
    for(int i = 0; i<n;i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(arr[i][j]!=0){
                arr[i][count]=arr[i][j];
                if(j!=count){
                    arr[i][j] = 0;
                }
                count++;
            }
        }
    }


    return arr;
}
int** func_right(int ** arr){
    for(int i = 0; i<n;i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(arr[j][i]!=0){
                arr[count][i]=arr[j][i];
                if(j!=count){
                    arr[j][i] = 0;
                }
                count++;
            }
        }
    }

    /////////////////////////
    for(int i = 0; i<n;i++){
        for(int j = 0;j<n-1;j++){
            if(arr[j][i]!=0){
                if(arr[j][i]==arr[j+1][i]){
                    arr[j][i]+=arr[j][i];
                    arr[j+1][i] = 0;
                }
            }
        }
    }
    /////////////////////////
    for(int i = 0; i<n;i++){
        int count = 0;
        for(int j = 0; j<n; j++){
            if(arr[j][i]!=0){
                arr[count][i]=arr[j][i];
                if(j!=count){
                    arr[j][i] = 0;
                }
                count++;
            }
        }
    }
    


    return arr;
}
int** func_left(int ** arr){
    
    for(int i = 0; i<n;i++){
        int count = n-1;
        for(int j = n-1; j>=0; j--){
            if(arr[j][i]!=0){
                arr[count][i]=arr[j][i];
                if(j!=count){
                    arr[j][i] = 0;
                }
                count--;
            }
        }
    }

    /////////////////////////
    for(int i = 0; i<n;i++){
        for(int j = n-1;j>0;j--){
            if(arr[j][i]!=0){
                if(arr[j][i]==arr[j-1][i]){
                    arr[j][i]+=arr[j][i];
                    arr[j-1][i] = 0;
                }
            }
        }
    }
    /////////////////////////
    for(int i = 0; i<n;i++){
        int count = n-1;
        for(int j = n-1; j>=0; j--){
            if(arr[j][i]!=0){
                arr[count][i]=arr[j][i];
                if(j!=count){
                    arr[j][i] = 0;
                }
                count--;
            }
        }
    }
    return arr;
}
int** func_down(int ** arr){
    
    for(int i = 0; i<n;i++){
        int count = n-1;
        for(int j = n-1; j>=0; j--){
            if(arr[i][j]!=0){
                arr[i][count]=arr[i][j];
                if(j!=count){
                    arr[i][j] = 0;
                }
                count--;
            }
        }
    }

    /////////////////////////
    for(int i = 0; i<n;i++){
        for(int j = n-1;j>0;j--){
            if(arr[i][j]!=0){
                if(arr[i][j]==arr[i][j-1]){
                    arr[i][j]+=arr[i][j];
                    arr[i][j-1] = 0;
                }
            }
        }
    }
    /////////////////////////
    for(int i = 0; i<n;i++){
        int count = n-1;
        for(int j = n-1; j>=0; j--){
            if(arr[i][j]!=0){
                arr[i][count]=arr[i][j];
                if(j!=count){
                    arr[i][j] = 0;
                }
                count--;
            }
        }
    }

    return arr;
}