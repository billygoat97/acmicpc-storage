#include <iostream>
#include <cmath>
#include <vector>
#include <stack>


using namespace std;

stack <pair<int,int> > s;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >>n;
    for(int i = 0; i<n; i++){
        int h;
        cin >> h;
        while(s.empty()==false){
            if(h<s.top().second){
                cout<< s.top().first<<" ";
                break;
            }
            s.pop();
        }
        if(s.empty()==true){
            cout<<0<<" ";
        }
        s.push(make_pair(i+1,h));
    }
    cout<<endl;

    return 0;
}