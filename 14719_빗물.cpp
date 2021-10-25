#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(){

    int h,w;
    cin >> h>> w;
    int curh = 0;
    int tot = 0;
    stack<int>s;
    for(int i = 0; i<w; i++){
        int height;
        cin >> height;
        if(curh > height){
            s.push(height);
        }else{
            while(s.size()!= 0){
                int ih = s.top();
                s.pop();
                tot += curh-ih;
            }
            curh = height;
        }
    }
    int rh = 0;
    while(s.size()!= 0){
        int ih = s.top();
        s.pop();
        if(ih >= rh){
            rh = ih;
        }else{
            tot += rh - ih;
        }
    }
    cout<<tot<<endl;


    return 0;
}