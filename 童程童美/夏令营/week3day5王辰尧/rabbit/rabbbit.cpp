#include<bits/stdc++.h>
using namespace std;
inline const int Get_Int() 
{
    int num=0,bj=1;
    char x=getchar();
    while(x<'0'||x>'9') 
	{
        if(x=='-')bj=-1;
        x=getchar();
    }
    while(x>='0'&&x<='9') 
	{
        num=num*10+x-'0';
        x=getchar();
    }
    return num*bj;
}
struct OI_mountain 
{
    int height,x,y;
    bool operator < (const OI_mountain &b) const 
	{
        return height>b.height;
    }
} a[50005];
int Cal(OI_mountain a,OI_mountain b) 
{
    return (abs(a.x-b.x)+abs(a.y-b.y))*(abs(a.x-b.x)+abs(a.y-b.y));
}
int n,cnt=0,f[50005];
int main() 
{
    freopen("rabbit.in","r",stdin);
    freopen("rabbit.out","w",stdout);
	n=Get_Int();
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) 
		{
            a[++cnt].height=Get_Int();
            a[cnt].x=i;
            a[cnt].y=j;
        }
    sort(a+1,a+cnt+1);
    for(int i=2; i<=cnt; i++)
        for(int j=1; j<i; j++)
            f[i]=max(f[i],f[j]+Cal(a[i],a[j])); 
    cout<<f[cnt];
    return 0;
}
