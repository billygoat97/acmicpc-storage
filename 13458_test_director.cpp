#include <iostream>
using namespace std;


int main(void){
    int total = 0;
    int a[1000000];
    int test_num;
    int num_main;
    int num_sub;
    int temp_num = 0;

    cin >> test_num;
    for (int i = 0; i< test_num; i++){
        cin >> a[i];
    }

    cin>> num_main >> num_sub;

    for(int i = 0; i< test_num; i++){
        int imsi = a[i] - num_main;
        if(imsi <= 0){
            temp_num = 1;
        }else{
            if( imsi % num_sub == 0){
                temp_num = 1 + (a[i] - num_main)/num_sub;
            }else{
                temp_num = 2 + (a[i] - num_main)/num_sub;
            }
        }
        total += temp_num;
    }

    cout<< total <<endl;
    return 0;
}
