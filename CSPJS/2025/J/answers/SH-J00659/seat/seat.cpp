#include<bits/stdc++.h>
using namespace std;
#define maxnm 123
int n, m, aR, a[maxnm], ansr, ansc, cnt; // n row, m col
bool cmp(int a, int b){
    return a > b;
}
void solve(int i, int j){
    if(a[cnt] == aR){
        ansr = i; ansc = j;
    }
}
int main(){
    // 9 : 20
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n * m; i++){
        cin >> a[i];
    }
    aR = a[0];
    sort(a, a + n * m, cmp);
    for(int j = 1; j <= m; j++){
        if(j % 2 == 1){
            for(int i = 1; i <= n; i++){ solve(i, j); cnt++; }
        }else{
            for(int i = n; i >= 1; i--){ solve(i, j); cnt++; }
        }
    }
    cout << ansc << ' ' << ansr << endl;
    return 0;
}