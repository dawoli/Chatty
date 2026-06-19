#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    string pai[53] ;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>pai[i];
        int pan=0;
        for(int j=1;j<=i-1;j++)
        {
            if(pai[i]==pai[j])
            {
                pan=1;
                break;
            }
        }
        if (pan==0)
        {
            ans++;
        }
    }
    cout<<52-ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
