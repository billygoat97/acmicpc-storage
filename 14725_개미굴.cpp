#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct node{
    public:
        string curname;
        vector<node*> nList;
        int len = 0;
    node();
    node(string str){
        curname = str;
    }
};
vector<node*> v;

bool sortByName(node* A, node* B){
    return (A->curname < B->curname);
}

void dfs(node* A){

    for(int i = 0; i<A->len;i++){
        cout<<"--";
    }
    cout<<A->curname<<"\n";
    sort(A->nList.begin(), A->nList.end(), sortByName);
    // cout<<A.nList.size()<<"!!!!!!!!!\n";
    for(int i = 0; i<A->nList.size();i++){
        dfs(A->nList[i]);
    }

}

int main(){

    int n;
    cin >> n;
    int num;
    string str;
    for(int i = 0; i<n;i++){
        cin >> num;
        cin >> str;
        node* imsi = new node(str);
        int flag = 0;
        for(int a = 0; a<v.size(); a++){
            if(v[a] -> curname == str){
                imsi = v[a];
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            v.push_back(imsi);
        }
        
        int cnt = 0;
        node* cur = imsi;
        for(int j = 1; j<num;j++){
            cin >> str;
            cur->len = cnt;
            cnt = cur->len + 1;
            flag = 0;
            for(int k = 0; k<cur->nList.size();k++){
                if(cur->nList[k]->curname == str){
                    cur = cur->nList[k];
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                node* newNode = new node(str);
                // cout<<newNode->curname<<"\n";
                cur->nList.push_back(newNode);
                cur = newNode;
                cur->len = cnt;
            }
        }
    }

    sort(v.begin(),v.end(),sortByName);
    
    for(int i = 0; i<v.size();i++){
        dfs(v[i]);
    }


    return 0;
}