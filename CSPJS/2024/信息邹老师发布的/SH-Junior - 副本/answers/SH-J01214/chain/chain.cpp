#include<bits/stdc++.h>
using namespace std;

long long t,n,k,q,l[1005];
long long r,c;
long long s[1005][2005];
long long bucket[6][200005];

int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++)
        {
            long long cnt=0;
            cin>>l[i];
            for(int j=1;j<=l[i];j++)
            {
                cin>>s[i][j];
                if(cnt)
                {
                    bucket[1][s[i][j]]=1;
                    cnt--;
                }
                if(s[i][j]==1)
                    cnt=k-1;
            }
            s[i][0]=-1;
            s[i][l[i]+1]=-1;
        }
        for(int i=2;i<=5;i++)
        {
            long long cnt=0;
            for(int j=1;j<=n;j++)
                for(int k=1;k<=l[j];k++)
                {
                    if(cnt)
                    {
                        bucket[i][s[j][k]]=1;
                        cnt--;
                    }
                    if(bucket[i-1][s[j][k]])
                        cnt=k-1;
                }
        }
        for(int i=1;i<=q;i++)
        {
            cin>>r>>c;
            if(bucket[r][c])
                cout<<1<<endl;
            else
                cout<<0<<endl;
            continue;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
