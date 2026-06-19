#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int p=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[p]) p++;
    }
    cout<<n-p+1<<endl;
    return 0;
}