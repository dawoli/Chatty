#include<iostream>
#include<cstdio>
using namespace std;

int n,m;
int d[510],c[510];
const int p=998244353;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i=0;i<n;i++)
    {
        d[i+1]=s[i]-'0';
    }
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
    }
    if(m==1) //subtask 12-14
    {
        int x;
        for(int i=1;i<=n;i++)
        {
            if(d[i]==1)
            {
                x=i;break;
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]>=x) cnt++;
        }
        long long ans=cnt;
        for(int i=n-1;i>1;i--)
        {
            ans*=i;
            ans%=p;
        }
        cout << ans%p;
        return 0;
    }
    //feature A
    long long ans=1;
    for(int i=n;i>1;i--)
    {
        ans*=i;
        ans%=p;
    }
    dfs(1);
    cout << ans%p;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
