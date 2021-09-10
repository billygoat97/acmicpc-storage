#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
class tree{

    public:
        int parent = 0;
        int lchild = 0;
        int rchild = 0;
};

int root;
tree node[1000001];
void postorder(int cur){
    
    if(cur == 0)return;
    if(node[cur].lchild== 0 && node[cur].rchild == 0){
        cout<<cur<<"\n";
        return;
    }
    
    postorder(node[cur].lchild);
    postorder(node[cur].rchild);
    cout<<cur<<"\n";
}

int main(){
    int n;
    int cur = -1;
    vector<int> v;
	while(cin >>n) {
        v.push_back(n);
	} 
    for(int i =0; i<v.size();i++){
        n = v[i];
        if(cur == -1){ // root 임
            root = n;
            cur = root;
            node[root].parent = root;
        }else{
            if( n < cur){ // left child
                node[cur].lchild = n;
                node[n].parent = cur;
                cur = n;
            }else{
                int curmax =cur;
                while(node[cur].parent < n){
                    cur = node[cur].parent;
                    curmax = max(curmax, cur);
                    if(cur == node[cur].parent)break;
                }
                cur = curmax;
                node[cur].rchild = n;
                node[n].parent = cur;
                cur = n;
            }
        }
    }

    
    postorder(root);

    return 0;
}