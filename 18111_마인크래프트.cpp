#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    
	cin.tie(0);
	ios::sync_with_stdio(false);
    int n,m,b;
    cin >> n>>m>>b;
    int arr[n][m];
    int total_box = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> arr[i][j];
            total_box += arr[i][j];
        }
    }
    total_box += b;
    int max_height = total_box / (n*m); 
    int height = 0;
    int time = 987654321;
    for(int h = 0; h <= max_height; h++){
        int imsi_time = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int diff = arr[i][j] - h;
                if(diff > 0) imsi_time += diff*2;
                else if(diff < 0 )imsi_time += diff*(-1);
            }
        }
        if(imsi_time <= time){
            //cout<<"h:" << h<<"imsi"<<imsi_time<<endl;
            time = imsi_time;
            height = h;
        }
    }
    cout<< time << " " << height <<"\n";


    

    return 0;
}