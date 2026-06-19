#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("coffee.in","r",stdin);
    freopen("coffee.out","w",stdout);
    cin >> t;
    while(t--)
    {
        int cnt[7];
        memset(cnt,0,sizeof(cnt));
        int sum=0;
        int n=0,m=0;
        int ans=0;
        for(int i=1;i<=5;i++)
        {
            for(int j=1;j<=8;j++)
            {
                string s;
                cin >> s;
                if(s=="math")
                {
                    cnt[i]++;
                }
            }
            sum+=cnt[i];
        }
        cin >> n >> m;
        ans+=(n/7)*sum;
        for(int i=0;i<(n%7);i++)
        {
            int t=(m+i)%7;
            if(t==0||t==6)
            {
                continue;
            }
            else
            {
                ans+=cnt[t];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
