#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


int main(){

    int num;
    cin >> num;
    int n;
    cin >> n;
    vector<int> inp;
    for(int i = 0; i<n; i++){
        int p;
        cin >> p;
        inp.push_back(p);
    }
    
    int ans=99999999;
    int inum = num;

    int cnt=0;
    if(inum == 0){
        cnt = 1;
    }else{
        while(inum !=0){
            cnt ++;
            inum /=10;
        }
    }
    

    for(int i = 0; i<=1000000; i++){
        int flag = 0;
        int imsi = i;
        do{
            int temp = imsi%10;
            for(int j = 0; j<n;j++){
                if(temp == inp[j]){
                    flag =1; 
                    imsi = 0;
                    break;
                }
            }
            imsi /= 10;
        }while(imsi!=0);

        if(flag == 0){
            int w = i;
            cnt=0;
            if(w == 0){
                cnt = 1;
            }else{
                while(w !=0){
                    cnt ++;
                    w /=10;
                }
            }
            ans = min(abs(i-num)+cnt, ans);
        }
    }


    ans = min(abs(num - 100), ans);
    cout<<ans<<endl;


    return 0;
}