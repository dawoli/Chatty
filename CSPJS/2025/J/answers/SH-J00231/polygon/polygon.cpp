#include<bits/stdc++.h>

using namespace std;

long long cnt,n,gsum=0;
long length[5000]={};
bool counted=0;

void dfs(long long l,long long sum,long long lmax,long scnt)
{
    bool pcnted=0;
    if(scnt>=3&&sum>(lmax*2)&&!counted)
    {
        cnt=(cnt+1)%(long long)998244353;
        counted=1;
        pcnted=1;
    }
    if(l==n)
    {
        if(pcnted)
            counted=0;
        return;
    }
    dfs(l+1,sum,lmax,scnt);
    if(gsum>2*length[l])
    {
        counted=0;
        if(length[l]>lmax)
            dfs(l+1,sum+length[l],length[l],scnt+1);
        else
            dfs(l+1,sum+length[l],lmax,scnt+1);
    }
    if(pcnted)
        counted=0;
    return;
}

int main()
{
    FILE *fp=freopen("polygon.in","r",stdin);
    cin>>n;
    for(long i=0;i<n;i++)
    {
        cin>>length[i];
        gsum+=length[i];
    }
    fclose(fp);
    dfs(0,0,0,0);
    fp=freopen("polygon.out","w",stdout);
    cout<<cnt;
    fclose(fp);
    return(0);
}
