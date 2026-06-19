#include<iostream>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
pii a[100001],b[100001];
int n,m1,m2,ans=0;
int f(pii t[],int m,int q)
{
    if (q==0)return 0;
    int a[q+1]={},s=0;
    /*for (int i=1;i<=m;i++)
    {
        cout<<t[i].x<<' '<<t[i].y<<'\n';
    }
    cout<<endl;*/
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=q;j++)
        {
            if (a[j]<t[i].x)
            {
                a[j]=t[i].y;
                s++;
                break;
            }
        }
    }
    return s;
}

int main()
{
    cin>>n>>m1>>m2;
    for (int i=1;i<=m1;i++)
    {
        cin>>a[i].x>>a[i].y;
    }
    for (int i=1;i<=m2;i++)
    {
        cin>>b[i].x>>b[i].y;
    }
    sort(a+1,a+m1+1);
    sort(b+1,b+m2+1);
    for(int i=0;i<=n;i++)
    {
        ans=max(ans,f(a,m1,i)+f(b,m2,n-i));
    }
    cout<<ans;
    return 0;
}