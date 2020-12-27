#include <iostream>
using namespace std;

int main(){
    unsigned long long N;
    int F;
    cin >> N >> F;
    int N_prime;
    N_prime = (N/100)*100;
    int k = N_prime % F;
    int Answer;
    if(k == 0){
        Answer = 0;
    }else{
        Answer = F - k;
    } 
    if(Answer <10){
        cout <<"0"<<Answer<<endl;
    }else{
        cout<<Answer<<endl;
    }


    return 0;
}