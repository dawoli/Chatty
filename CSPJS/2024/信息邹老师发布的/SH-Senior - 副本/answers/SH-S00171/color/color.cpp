#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    char ch=getchar();int x=0,y=1;
    while(!isdigit(ch)){
        if(ch=='-')y=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*y;
}
int T;
int n;
int a[500005];
int f[1000005];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=0;i<=1000000;i++)f[i]=-1000000000000000;
        f[0]=(a[1]==a[2])*a[1];
        f[a[1]]=0;
        int mx=0;int dt=0;
        for(int i=3;i<=n;i++){
            int res=0;
            if(mx==a[i])res=f[mx]+dt+a[i];
            else res=max(f[a[i]]+dt+a[i],f[mx]+dt);
            if(a[i]==a[i-1])dt+=a[i];
            f[a[i-1]]=max(f[a[i-1]],res-dt);
            if(f[a[i-1]]>f[mx])mx=a[i-1];
        }
        int ans=0;
        for(int i=0;i<=1000000;i++)ans=max(ans,f[i]);
        cout<<ans+dt<<endl;
    }
    return 0;
}
