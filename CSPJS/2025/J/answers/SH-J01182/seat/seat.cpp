#include<bits/stdc++.h>
using namespace std;
int n_n, m_m, grade_of_R, ans_n = 1, ans_m = 1;
priority_queue<int> grades;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n_n >> m_m;
    int k;
    for (int i = 0; i < n_n*m_m; i++){
        cin >> k;
        if(i == 0){
            grade_of_R = k;
        }
        grades.push(k);
    }
    k = 0;
    while(k!=grade_of_R){
        if(k != 0){
            if (ans_m%2 == 1){
                if(ans_n<n_n){
                        ans_n++;
                }else{
                    ans_m++;
                }
            }else{
                if(ans_n>1){
                        ans_n--;
                }else{
                    ans_m++;
                }
            }}
        k = grades.top();
        grades.pop();

    }cout << ans_n << " " << ans_m << endl;
    return 0;
}
