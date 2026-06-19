//Ei Pueblo Unido Samas Sera Vencido
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int n;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    int pre=0;
    for(int i=1;i<=n;i++){
        int ptr=i;
        while(ptr<=n and a[i]==a[ptr])ptr++;
        ptr--;
        int len=ptr-i+1;
        int d=min(pre,len);
        ans+=d;
        pre+=len-d;
        i=ptr;
    }
    cout<<n-ans<<endl;
    return 0;
}
