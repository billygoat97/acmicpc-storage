#include <iostream>
using namespace std;

int main(){

    int x_length,y_length;
    cin >> x_length>>y_length;
    int X_pos, Y_pos, dir;
    cin >> X_pos >> Y_pos >> dir;
    int count = 0;

    int** block = new int*[x_length];
    for( int i = 0; i< x_length; i++){
        block[i] = new int[y_length];
    }
    for(int i = 0; i< x_length;i++){
        for(int j = 0; j< y_length;j++){
            cin >> block[i][j];
        }
    }
    // for(int i = 0; i< x_length;i++){
    //     for(int j = 0; j< y_length;j++){
    //         cout<< block[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }
    

    int total = 0;
    int dir4 = 0;
    while(1){
        if(block[X_pos][Y_pos]==0){
            count++;
            block[X_pos][Y_pos] = -1; // means this is cleaned
        }
        if(dir==0){ // north
            if(block[X_pos][Y_pos-1]==0){
                dir= 3;
                Y_pos--;
                dir4 = 0;
            }else if(block[X_pos][Y_pos-1]!=0){
                dir = 3;
                dir4++;
            }
        }else if(dir==1){ // east
            if(block[X_pos-1][Y_pos]==0){
                dir= 0;
                X_pos--;
                dir4 = 0;
            }else if(block[X_pos-1][Y_pos]!=0){
                dir = 0;
                dir4++;
            }
        }else if(dir==2){ // south
            if(block[X_pos][Y_pos+1]==0){
                dir= 1;
                Y_pos++;
                dir4 = 0;
            }else if(block[X_pos][Y_pos+1]!=0){
                dir = 1;
                dir4++;
            }            
        }else if(dir==3){ // west
            if(block[X_pos+1][Y_pos]==0){
                dir= 2;
                X_pos++;
                dir4 = 0;
            }else if(block[X_pos+1][Y_pos]!=0){
                dir = 2;
                dir4++;
            }            
        }
        if(dir4 > 3){
            if(dir == 0){
                if(block[X_pos+1][Y_pos]==1){
                    cout << count<<endl;
                    return 0;
                }else{
                    X_pos++;
                    dir4 = 0;
                }
            }else if(dir == 1){
                if(block[X_pos][Y_pos-1]==1){
                    cout << count<<endl;
                    return 0;
                }else{
                    Y_pos--;
                    dir4 = 0;
                }
                
            }else if(dir == 2){
                if(block[X_pos-1][Y_pos]==1){
                    cout << count <<endl;
                    return 0;
                }else{
                    X_pos--;
                    dir4 = 0;
                }

            }else if(dir == 3){
                if(block[X_pos][Y_pos+1]==1){
                    cout << count<<endl;
                    return 0;
                }else{
                    Y_pos++;
                    dir4 = 0;
                }

            }
        }
        // total++;
        // cout<<"total: "<<total<< ", current position: "<<X_pos<<"," <<Y_pos<<"  count: "<<count<<endl;
        // if(total==100){
        //     return 0;
        // }
    }
    
return 0;
}