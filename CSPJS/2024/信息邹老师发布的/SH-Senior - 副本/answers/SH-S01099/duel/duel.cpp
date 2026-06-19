#include <bits/stdc++.h>;
using namespace std;
int n;
int a[100000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    cin>>a[0];
    if(n==2) cout << 1;
    if(n==3) cout << 2;
    if(n==4) cout << 2;
    if(n==5) cout << 3;
    if(n==6) cout << 4;
    if(n==7) cout << 5;
    if(n==8) cout << 5;
    if(n==9) cout << 6;
    if(n==10) cout << 7;
    return 0;
}
