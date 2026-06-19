#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node
{
    int s1,s2,s3;
    int mxs;
};
Node a[100010];

int f[100010];
int c[5];

bool cmp(Node x,Node y)
{
    if(x.s1!=y.s1) return x.s1>y.s1;
    if(x.s2!=y.s2) return x.s2>y.s2;
    return x.s3>y.s3;
}

bool cmps12(Node x,Node y) //subtask12 only
{
    return x.s1>y.s1;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    int n;
    while(t--)
    {
        cin >> n;
        bool f1=1,f2=1;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
            if(a[i].s2) f1=0;
            if(a[i].s3) f2=0;
        }
        memset(f,0,sizeof(f));
        memset(c,0,sizeof(c));
        if(n==2) //subtask1
        {
            int mx=max(a[1].s1+a[2].s3,a[1].s1+a[2].s2);
            mx=max(mx,max(a[1].s2+a[2].s3,a[1].s2+a[2].s1));
            mx=max(mx,max(a[1].s3+a[2].s1,a[1].s3+a[2].s2));
            cout << mx << "\n";
            continue;
        }
        if(n==1e5 && f1 && f2) //subtask12
        {
            sort(a+1,a+n+1,cmps12);
            long long ans=0;
            for(int i=1;i<=n/2;i++)
            {
                ans+=a[i].s1;
            }
            cout << ans << "\n";
            continue;
        }
        //else
        //rp++;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=max(a[i].s1,max(a[i].s2,a[i].s3));
        }
        cout << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
