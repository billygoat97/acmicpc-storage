#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>


using namespace std;

int sosu[10000000]={0,};
vector<int> v;
vector<int> su;
vector<int> selectiii;
bool sel[7];

void dfs(int cur, int num){
    if(cur == num){
        string str="";
        for(int i = 0; i<num;i++){
            str += to_string(selectiii[i]);
        }
        // cout<<str<<endl;
        int n= stoi(str);
        v.push_back(n);
        return;
    }
    for(int i = 0; i< su.size(); i++){
        if(sel[i]==true)continue;
        sel[i] = true;
        selectiii.push_back(su[i]);
        dfs(cur+1,num);
        selectiii.pop_back();
        sel[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    for(int i= 2; i<10000000;i++){
        sosu[i] = i;
    }
    for(int i=2;i<10000000;i++) {
        if(sosu[i]==0) continue; 
        for(int j=2*i;j<10000000; j+=i) {
            sosu[j] = 0;
        }
    }
    int num;
    cin >> num;
    for(int i = 0; i< num; i++){
        int cnt = 0;
        v.clear();
        su.clear();
        string inp;
        cin >> inp;
        for(int j = 0; j<inp.size();j++){
            su.push_back(inp[j]-'0');
        }
        for(int q = 1; q<=su.size();q++){
            for(int a = 0; a<7;a++){
                sel[a] = false;
            }
            dfs(0,q);
            
        }
        
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int j= 0; j<v.size();j++){

            if(sosu[v[j]] != 0){
                //cout<<v[j]<<endl;
                cnt++;
            }
        }

        cout<<cnt<<endl;
    }





    return 0;
}