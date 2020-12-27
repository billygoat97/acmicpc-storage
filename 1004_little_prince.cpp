#include<iostream>
#include<cmath>
using namespace std;

int main(){

    int case_num;
    
    int *case_count = new int[case_num];
    cin >> case_num;
    for(int i = 0; i< case_num; i++){
        int x1, y1, x2, y2;
        case_count[i] = 0;
        cin >> x1>>y1>>x2>>y2;
        int circle_num;
        cin >> circle_num;
        int *CX = new int[circle_num];
        int *CY = new int[circle_num];
        int *length = new int[circle_num];
        for(int j = 0; j< circle_num;j++){
            cin >> CX[j] >> CY[j] >> length[j];
        }
        for(int k = 0; k<circle_num;k++){
            // if(pow(x1-CX[k],2)+pow(y1-CY[k],2) < pow(length[k],2)){
            //     case_count[i]++;
            // }
            // if(pow(x2-CX[k],2)+pow(y2-CY[k],2) < pow(length[k],2)){
            //     case_count[i]++;
            // }
            // if(pow(x2-CX[k],2)+pow(y2-CY[k],2) < pow(length[k],2)&&pow(x1-CX[k],2)+pow(y1-CY[k],2) < pow(length[k],2)){
            //     case_count[i]--;
            // }
            if((pow(x2-CX[k],2)+pow(y2-CY[k],2) < pow(length[k],2) && pow(x1-CX[k],2)+pow(y1-CY[k],2) > pow(length[k],2)) || (pow(x2-CX[k],2)+pow(y2-CY[k],2) > pow(length[k],2) && pow(x1-CX[k],2)+pow(y1-CY[k],2) < pow(length[k],2))){
                case_count[i]++;
            }
        }
        delete [] CX;
        delete [] CY;
        delete [] length;

    }

    for(int i = 0; i<case_num;i++){
        cout<<case_count[i]<<endl;
    }
    return 0;
}
