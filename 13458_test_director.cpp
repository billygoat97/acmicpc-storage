#include <iostream>
using namespace std;


int main(void){
    long long total = 0; // int는 안됨
    int a[1000000]; // 시험실별 인원
    int test_num; // 시험실 개수
    int num_main; //메인 감독관 감독 인원
    int num_sub; // 서브 감독관 감독 인원
    int temp_num = 0;

    cin >> test_num;
    for (int i = 0; i< test_num; i++){
        cin >> a[i]; // 세기
    }

    cin>> num_main >> num_sub;

    for(int i = 0; i< test_num; i++){
        int imsi = a[i] - num_main; // 일단 1명은 들어가야 함
        if(imsi <= 0){
            temp_num = 1;
        }else{
            if( imsi % num_sub == 0){
                temp_num = 1 + (a[i] - num_main)/num_sub; // 만약에 딱떨어질 경우
            }else{
                temp_num = 2 + (a[i] - num_main)/num_sub; // 딱 안떨어질 경우
            }
        }
        total += temp_num;
    }

    cout<< total <<endl;
    return 0;
}
