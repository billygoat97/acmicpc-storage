#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
queue <char> q;

int main(){

    string input;
    cin >> input;
    int imsi = 0;
    
    for(int i = 0; i<input.length();i++){
        if(input[i]== 'P'){
            imsi++;
            continue;
        }
        if(input[i+1] == 'P' && imsi >=2){ // 현재 A, 앞에 P 2개, 다음에 P
            imsi --;
            i++;
        }else{
            printf("NP\n");return 0;
        }
    }
    
    if(imsi ==1){ // PPAP 구조여야 1 남음
        printf("PPAP\n");
    }else{
        printf("NP\n");
    }
    





    return 0;
}