#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int arr[6] ={0,};
void recursion(int num,int idx){

    if(num == 6){
        for(int i = 0; i<6; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i =idx; i<v.size();i++){
        arr[num] = v[i];
        recursion(num+1,i+1);
    }

}

int main(){

    while(1){
        int n;
        cin >>n;
        if(n == 0)break;
        v.clear();
        for(int i = 0; i<n; i++){
            int inp;
            cin >> inp;
            v.push_back(inp);
        }
        recursion(0,0);
        cout<<"\n";
    }


}