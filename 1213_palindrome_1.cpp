#include <iostream>
#include <cstring>
using namespace std;

int main(void){

    char name[50] ="";
    char answer[50] = "";
    int alphabet[26];
    for(int i = 0; i<26; i++){
        alphabet[i] = 0;
    }
    cin >> name;
    //cout<<strlen(name)<<endl;
    for(int i = 0; i< strlen(name);i++){
        int ascii_number = name[i] - 65;
        if(ascii_number>=0 || ascii_number <= 25){
            alphabet[ascii_number]++;
        }
    }

    int count_odd = 0;
    int odd;
    for(int i = 0; i< 26; i++){
        if(alphabet[i]%2==1){
            count_odd++;
            odd = i;
            alphabet[i]--;
        }
    }
    if(count_odd > 1){
        cout<<"I'm Sorry Hansoo"<<endl;
    }else{
        int count=0;
        for(int i = 0; i<26;i++){
            while(alphabet[i]>0){
                answer[count] = char(i+65);
                alphabet[i] -=2;
                count++;
            }
        }
        int length = count;
        if(count_odd == 1){
            answer[count] = char(odd + 65);
            count ++;
        }

        //cout<<strlen(answer)<<endl;
        for(int i = 0; i< strlen(answer);i++){
            if(count_odd == 1){
                answer[count+i] = answer[count-i-2];
            }else{
                answer[count+i] = answer[count-i-1];
            }
        }
        cout<<answer<<endl;

    }
    



    return 0;
}