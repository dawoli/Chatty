#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,cnt=52,flag=1;
    string a[100];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=i-1;j++)
        {
            if(a[j]==a[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cnt--;
        }
        flag=1;
    }
    cout<<cnt;
    return 0;
}
