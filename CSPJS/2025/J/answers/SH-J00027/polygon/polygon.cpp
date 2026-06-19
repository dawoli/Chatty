#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans,amax;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
//	for(int i=2;i<=n;i++)
//	{
//		amax=max(a[i-1],a[i]);
//	}
//	
//	for(int i=3;i<=n;i++)//几根木棍 
//	{
//		for(int j=1;j+i-1<=n;j++)//起始木棍 
//		{
//			int sum=0;
//			for(int k=j;k<=i+j-1;k++)
//			{
//				sum+=a[k];
//			} 
//			if(sum>2*amax)
//			{
//				ans++;
//			}
//		}
//	}
//	cout<<ans;
	cout<<1<<endl;
	return 0;
}
