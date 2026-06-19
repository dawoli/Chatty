#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    x=0;char ch;
    for(ch=getchar();(ch<'0'||ch>'9');ch=getchar());
    for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
}
int n,A[200005],top;
int nx[200005],pre[200005];
int la[1000006];
long long ans,dp[200005],fans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int i,T;
    cin>>T;
    while(T--){
        memset(la,0,sizeof(la));
        cin>>n;
        ans=0;top=0;
        for(i=1;i<=n;i++){
            read(A[++top]);
            if(A[top]==A[top-1]){
                ans+=A[top];
                top--;
            }
        }
        n=top;
        for(i=1;i<=n;i++){
            nx[la[A[i]]]=i;
            pre[i]=la[A[i]];
            la[A[i]]=i;
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            dp[i]=dp[i-1];
            if(pre[i]){
                dp[i]=max(dp[pre[i]+1]+A[i],dp[i]);
            }
        }
        fans=0;
        for(i=1;i<=n;i++)
            fans=max(fans,dp[i]);
        printf("%lld\n",fans+ans);
    }
    return 0;
}
