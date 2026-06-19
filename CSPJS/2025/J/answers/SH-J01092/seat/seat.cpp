#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a,cnt = 1;
    cin >> a;
    int t = a;
    for(int i = 2; i <= n*m; i++){
        cin >> a;
        if(a > t){
            cnt++;
        }
    }
    int c,r;
    if(cnt % n == 0){
        c = cnt/n;
    }else{
        c = cnt/n+1;
    }
    if(c % 2 == 0){
        if(cnt%n==0){
            r = 1;
        }else{
            r = n-cnt%n+1;
        }
    }else if(c % 2 != 0){
        if(cnt % n == 0){
            r = n;
        }else{
            r = cnt%n;
        }
    }
    cout << c << " " << r;
    return 0;
}
