#include<iostream>
#include<cstdio>
using namespace std;

const int MOD = 998244353;

long long n,m,c[505],ans=1,cnt,cnt2,sum=1;
bool flag = false;
string s;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
    }
    if(m == n)
    {
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0' || c[i]==0) cout << 0;
            else cout << 1;
            return 0;
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(c[i] == 0)
            {
                cnt ++;
            }
            if(s[i-1] == '0')
            {
                cnt2 ++;
            }
        }
        if(cnt>n-m || cnt2>n-m)
        {
            cout << 0;
            return 0;
        }
        if(cnt) flag = true;
        for(int i=n-cnt;i>=1;i--)
        {
            ans = (1ll*ans*i)%MOD;
        }
        if(flag)
        {
            for(int i=n-m+1;i>=n-m-cnt+2;i--)
            {
                sum = (1ll*sum*i)%MOD;
            }
            ans = (ans+sum)%MOD;
        }
    }
    cout << ans;
    return 0;
}
