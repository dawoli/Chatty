#include<bits/stdc++.h>
#define int long long
using namespace std;
long long t,dp[100009][9],n,a[100009],b[100009],c[100009],ans=0,dp1[209][109][109];
void dfs(int q,int w,int e,int r,int k)
{
    if(q==n+1){ans=max(ans,k);return;}
    if(w<n/2)dfs(q+1,w+1,e,r,k+a[q]);
    if(e<n/2)dfs(q+1,w,e+1,r,k+b[q]);
    if(r<n/2)dfs(q+1,w,e,r+1,k+c[q]);
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int qwq=1;qwq<=t;qwq++)
    {
        long long a1[9],b1[9],c1[9],pdb=0,pdc=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            pdb=max(b[i],(long long)0);
            pdc=max(c[i],(long long)0);
        }
        if(pdb==0&&pdc==0)
        {
            sort(a,a+n+1);
            for(int i=n;i>=n/2;i--)
            {
                ans+=a[i];
            }
            cout<<ans<<endl;
            continue;
        }
        if(n<=10)
        {
            dfs(1,0,0,0,0);
            cout<<ans<<endl;
            continue;
        }
        if(n<=200)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<=min(i,n/2);j++)
                {
                    for(int k=0;k<=min(i-j,n/2);k++)
                    {
                        if(i-j-k>n/2||i<j+k)break;
                        dp1[i][j][k]=max(dp1[i-1][j][k]+c[i],max(dp1[i-1][j-1][k]+a[i],dp1[i-1][j][k-1]+b[i]));
                        ans=max(dp1[i][j][k],ans);
                    }
                }
            }
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=6;i++)
        {
            a1[i]=0,b1[i]=0,c1[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            int id=i;
            dp[id][1]=a1[4]+a[id];
            long long a2=a1[1]+1,a3=a1[2],a4=a1[3];
            dp[id][2]=b1[4]+b[id];
            long long b2=b1[1],b3=b1[2]+1,b4=b1[3];
            dp[id][3]=c1[4]+c[id];
            long long c2=c1[1],c3=c1[2],c4=c1[3]+1;
            if(a2<n/2&&dp[id][1]>a1[4])
            {
                a1[1]=a2;
                a1[2]=a3;
                a1[3]=a4;
                a1[4]=dp[id][1];
            }
            if(a3<n/2&&dp[id][1]>b1[4])
            {
                b1[1]=a2;
                b1[2]=a3;
                b1[3]=a4;
                b1[4]=dp[id][1];
            }
            if(a4<n/2&&dp[id][1]>c1[4])
            {
                c1[1]=a2;
                c1[2]=a3;
                c1[3]=a4;
                c1[4]=dp[id][1];
            }
            if(b2<n/2&&dp[id][2]>a1[4])
            {
                a1[1]=b2;
                a1[2]=b3;
                a1[3]=b4;
                a1[4]=dp[id][2];
            }
            if(b3<n/2&&dp[id][2]>b1[4])
            {
                b1[1]=b2;
                b1[2]=b3;
                b1[3]=b4;
                b1[4]=dp[id][2];
            }
            if(b4<n/2&&dp[id][2]>c1[4])
            {
                c1[1]=b2;
                c1[2]=b3;
                c1[3]=b4;
                c1[4]=dp[id][2];
            }
            if(c2<n/2&&dp[id][3]>a1[4])
            {
                a1[1]=c2;
                a1[2]=c3;
                a1[3]=c4;
                a1[4]=dp[id][3];
            }
            if(c3<n/2&&dp[id][3]>b1[4])
            {
                b1[1]=c2;
                b1[2]=c3;
                b1[3]=c4;
                b1[4]=dp[id][3];
            }
            if(c4<n/2&&dp[id][3]>c1[4])
            {
                c1[1]=c2;
                c1[2]=c3;
                c1[3]=c4;
                c1[4]=dp[id][3];
            }
            ans=max(max(ans,dp[id][1]),max(dp[id][2],dp[id][3]));
        }
        cout<<ans<<endl;
    }
}

