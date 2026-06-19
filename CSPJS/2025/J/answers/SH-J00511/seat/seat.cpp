#include <bits/stdc++.h>
using namespace std;

int a[10005];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    for (int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int c=a[0];
    sort(a,a+n*m);
    for(int j=m*n-1;j>=0;j--)
    {
        if(a[j]==c)
        {
            int s=j/m,y=j%m;
            if(s%2==1)
            {
                cout<<m-s<<" "<<n-y;
                return 0;
            }
            else
            {
                //cout<<m<<" "<<n<<" "<<s<<" "<<y<<endl;
                cout<<m-s<<" "<<y+1;
                return 0;
            }
        }
    }

    return 0;
}
