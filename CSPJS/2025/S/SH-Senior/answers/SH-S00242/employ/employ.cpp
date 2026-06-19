#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,answ=0;
    cin>>n>>m;
    char s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    int k=n-m;
    for(int i=0;i<=k;i++){
        answ+=(i*i);
    }
    cout<<(answ%998244353);
    return 0;
}
