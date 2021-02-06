#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <cstring>


using namespace std;

int main(){

    int n;
    stack<pair<int, int> > s;
    cin >> n;
    int arr[n];

    for(int i = 0; i<n; i++){
        arr[i] = -1;
    }
    for(int i = 0; i<n; i++){
        int inp;
        cin >> inp;
        if(s.size() == 0){
            s.push(make_pair(i, inp));
        }else{
            while(s.size() > 0){
                if(s.top().second < inp){
                    arr[s.top().first] = inp;
                    s.pop();
                }else{
                    break;
                }
            }

            s.push(make_pair(i, inp));
        }

    }
    for(int i = 0; i<n; i++){
        
        cout<< arr[i] <<" ";
    }
    cout<<"\n";



    return 0;
}