#include <bits/stdc++.h>
using namespace std;
const int maxn=5001;
int a[maxn],f[maxn],c[maxn],n,ans=0;
bool sbx(int p,int q,int i)
{
	int maxnn=0,tt=0;
	if(i<3)
		return false;
	for(int j=1;j<=i;j++)
	{
		if(f[j]>maxnn)
			maxnn=f[j];
		tt+=f[j];
	}
	if(tt>2*maxnn)
		return true;
	return false;
}
void dp(int q,int i)
{
	for(int p=q+1;p<=i-q;p++)
	{
		dp(p,i+1);
		f[i-1]=a[p];
		if(sbx(p,q,i)==true)
			ans++;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	for(int i=3;i<=n;i++)
		dp(1,i);
	cout<<ans*3<<endl;
	return 0;
}
