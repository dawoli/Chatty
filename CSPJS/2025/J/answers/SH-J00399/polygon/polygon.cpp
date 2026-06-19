#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn];
bool dbx(int m,int h,int zc)
{
	if(m>=3 && h>=zc*2)
	{
		return true;
	}
	else return false;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long cnt=0;
	int n;
	int z=-91,h=0,b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			h+=a[j];
			b=i;
			if(z<=a[j])
			{
				z=a[j];
			}
		}
		if(dbx(b,h,z)==true)
		{
			cnt=3;
		} 
	}
	cout<<cnt<<endl;
	return 0;
}
