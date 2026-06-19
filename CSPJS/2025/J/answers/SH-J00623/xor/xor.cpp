#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
int a[maxn];
struct Edge
{
	int a,b;
}e[maxn];
bool cmp(Edge x,Edge y)
{
	return x.b<y.b;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int aaa=0;
	int ans1=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int m=i;m<=j;m++)
			{
				aaa^=a[m];
				//cout<<i<<" "<<j<<" "<<aaa<<endl;
			}
			if(aaa==k)
			{
				//cout<<i<<" "<<j<<" "<<aaa<<endl;
				ans1++;
				e[ans1].a=i;
				e[ans1].b=j;
			}
			aaa=0;
		}
	}
	int ans=1;
	int aa=1;
	sort(e+1,e+ans1+1,cmp);
	for(int i=2;i<=ans1;i++)
	{
		//cout<<e[aa].b<<" "<<e[i].a<<endl;
		if(e[aa].b<e[i].a)
		{
			ans++;
			aa=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
