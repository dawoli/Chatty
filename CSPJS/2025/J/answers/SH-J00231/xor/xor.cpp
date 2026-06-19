#include<bits/stdc++.h>

using namespace std;

long long cnt=0,n,k,res=0;
long a[500000]={};
long x[5000],y[5000];

void dfs()
{
    long i,j,m,temp;
    bool can;
    for(i=0;i<n;i++)
    {
        temp=0;
        for(j=i;j<n;j++)
        {
            temp=temp^a[j];
            if(temp==k)
            {
                can=1;
                for(m=0;m<cnt;m++)
                    if((i<=x[m]&&j>=y[m])||(i<=y[m]&&j>=y[m]))
                        can=0;
                if(can)
                {
                    x[cnt]=i;
                    y[cnt]=j;
                    cnt++;
                    if(cnt>res)
                        res=cnt;
                    dfs();
                }
            }
        }
    }
    return;
}

int main()
{
    FILE *fp=freopen("xor.in","r",stdin);
    cin>>n>>k;
    for(long i=0;i<n;i++)
        cin>>a[i];
    fclose(fp);
    dfs();
    fp=freopen("xor.out","w",stdout);
    cout<<res;
    fclose(fp);
    return(0);
}
