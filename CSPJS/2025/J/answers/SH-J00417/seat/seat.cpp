#include<bits/stdc++.h>
using namespace std;
int a[200];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,sum;
    cin>>n>>m;
    sum=n*m;
    for (int i=1;i<=sum;i++)
    {
        cin>>a[i];
    }
    int R_num=a[1],R_pos;
    sort(a+1,a+sum+1,cmp);
    for (int i=1;i<=sum;i++)
    {
        if (a[i]==R_num)
        {
            R_pos=i;
            break;
        }
    }
    int lie=(R_pos-1)/n+1,hang=(R_pos-1)%n+1;
    if (lie%2==0)
    {
        hang=n-hang+1;
    }
    cout<<lie<<' '<<hang<<endl;
    return 0;
}