#include <iostream>
#include <cmath>
#include <stack>
#include <vector>

using namespace std;

stack<int> s;
vector<int> v;

long long int sum=0;

int n;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i<n; i++){
        int p;
        cin >> p;
        v.push_back(p);
    }
    for(int i = 0;i<n;i++){
        while(s.empty()== false && s.top() <= v[i]){ // 나보다 작은가? 그럼 빼기
            s.pop();
        }
        sum += s.size(); // 새로 들어온놈을 볼수 있는 갯수만큼 그때그때 더하기
        s.push(v[i]);
    }
    
    cout<<sum<<endl;
}