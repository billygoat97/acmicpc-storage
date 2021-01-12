#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
#define inf 10000000
vector< pair<int, int> > House, Chicken, chosen;
int n,m;
int input;
int Answer=inf;
int Chicken_Num=0;
bool Select[13];

void get_input();
int calculate();
void Select_Chicken(int Idx, int Cnt);

int main(){
    
    cin>>n>>m;
    get_input();
    Select_Chicken(0,0);
    cout<<Answer<<endl;

    return 0;
}

void get_input(){
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            
            cin >> input;
            if (input == 1){
                House.push_back(make_pair(i,j));
            }else if(input==2){
                Chicken.push_back(make_pair(i,j));
                
            }
        }
    }
    Chicken_Num = Chicken.size();
}

int calculate(){
    int Sum = 0;
    for (int i = 0; i < House.size(); i++)
    {
        int x = House[i].first;
        int y = House[i].second;
        int d = inf;
 
        for (int j = 0; j < chosen.size(); j++)
        {
            int xx = chosen[j].first;
            int yy = chosen[j].second;
            int Dist = abs(xx - x) + abs(yy - y);
 
            d = min(d, Dist);
        }
        Sum = Sum + d;
    }
    return Sum;
}

void Select_Chicken(int Idx, int Cnt){
    if (Cnt == m)
    {
        Answer = min(Answer, calculate());
        return;
    }
 
    for (int i = Idx; i < Chicken_Num; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        chosen.push_back(Chicken[i]);
        Select_Chicken(i, Cnt + 1);
        Select[i] = false;
        chosen.pop_back();
    }
}

