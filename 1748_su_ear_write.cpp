#include <iostream>
#include <cmath>

using namespace std;

// 그냥 이렇게 풀지 않고 쉽게 풀수 있는데 옛 감성 살려서 노가다 한번 해봄
int main(){

    int imsi;
    scanf("%d", &imsi);
    long long cnt=0;
    if(imsi <= 9){
        cnt += imsi;
    }else if(imsi<=99){
        cnt += 9;
        cnt += 2* (imsi-9);
    }else if(imsi<=999){
        cnt += 90*2 + 9;
        cnt += 3*(imsi-99);
    }else if(imsi<=9999){
        cnt += 900*3+ 90*2 + 9;
        cnt += 4*(imsi-999);
    }else if(imsi<=99999){
        cnt += 9000*4+900*3+90*2 + 9;
        cnt += 5*(imsi-9999);
    }else if(imsi<=999999){
        cnt += 90000*5+9000*4+900*3+90*2 + 9;
        cnt += 6*(imsi-99999);
    }else if(imsi<=9999999){
        cnt += 900000*6+90000*5+9000*4+900*3+90*2 + 9;
        cnt += 7*(imsi-999999);
    }else if(imsi<=99999999){
        cnt += 9000000*7+900000*6+90000*5+9000*4+900*3+90*2 + 9;
        cnt += 8*(imsi-9999999);
    }else if(imsi==100000000){
        cnt += 90000000*8+9000000*7+900000*6+90000*5+9000*4+900*3+90*2 + 9 + 9;
    }
    printf("%lld\n", cnt);


    return 0;
}