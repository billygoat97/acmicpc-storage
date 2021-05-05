#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int main(){
    long long sum=0;
    int n;
    cin >>n;
    stack<int> s;
    for(int i = 0; i<n; i++){
        int temp;
        cin >> temp;
        if(temp == 0){
            s.pop();
        }else{
            s.push(temp);
        }

    }
    while(s.empty() == false){
        sum+=s.top();
        s.pop();
    }
    cout<<sum<<endl;




}
