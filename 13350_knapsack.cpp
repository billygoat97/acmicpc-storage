#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    int state_num;
    cin >> state_num;
    int d[state_num], c[state_num], f[state_num], u[state_num];
    int con = 0, fed = 0, total_sum = 0, undecided = 0;
    vector <int> v[2]; // 0은 candidate 수, 1은 내가 이걸 얻기 위해 필요한 최소 인원
    v[0].push_back(0);
    v[1].push_back(0);
    int imsi_total = 0;
    int nec = 0;
    for(int i = 1; i<=state_num; i++){
        cin >> d[i] >> c[i] >> f[i] >> u[i];
        total_sum += d[i];
        if(c[i] > f[i] + u[i]){
            con += d[i];
        }else if(f[i] > c[i] + u[i]){
            fed += d[i];
        }else if(f[i] == c[i] + u[i]){
            nec += u[i];
            total_sum -= d[i];
        }else if(c[i] == f[i] + u[i]){
            nec += 1;
            con += d[i];
        }else{
            v[0].push_back(d[i]);
            int imsi = (f[i]+c[i]+u[i]) / 2 + 1 - c[i];
            imsi_total += u[i];
            v[1].push_back(imsi);
            undecided += d[i];
        }
    }
    if(fed >= con + undecided){
        cout<<"impossible"<<endl;
        return 0;
    }
    int len = v[0].size();
    int need = total_sum/2 + 1 - con;


    int dp[len+1][imsi_total+1];
    int imsi_min = 9999999;
    int imsi_j = 9999999;
    for(int i = 0; i<=len; i++){
        for(int j = 0; j<= imsi_total; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else if(v[1][i]<=j){
                if(dp[i-1][j-v[1][i]]+v[0][i]>=need){
                    if(j<= imsi_j)imsi_j = j;
                    imsi_min = min(imsi_min, dp[i-1][j-v[1][i]]+v[0][i]);
                    dp[i][j] = imsi_min;
                }else{
                    dp[i][j] = dp[i-1][j-v[1][i]]+v[0][i];
                }
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i = 0; i<=len; i++){
        for(int j = 0; j<= imsi_total; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    // cout<<endl;
    // cout<<endl;
    // cout<<need<<endl;
    // cout<<endl;
    // cout<<endl;

    cout<<imsi_j+nec<<endl;

    return 0;
}