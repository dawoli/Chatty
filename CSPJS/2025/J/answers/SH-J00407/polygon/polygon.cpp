#include<bits/stdc++.h>
using namespace std;
int n,a[50],cnt; 
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int q=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		q*=2;
	}
	for(int i=7;i<q;i++)
	{
		int b[50];
		int k=1,p=1;int j=i;
//		for(int h=1;h<=n;h++)
//		{
//			if(j%2==1)
//			{
//				b[k]=a[h];
//				k++;
//			}
//			j=j/2;
//		}
		while(j>0)
		{
			if(j%2==1)
			{
				b[k]=a[p];
				k++;
			}
			p++;
			j=j/2;
		}
		if(k<4)
		{
			continue;
		}
		sort(b+1,b+k+1,cmp);
		int ans=0;
		for(int j=1;j<=k-1;j++)
		{
			ans+=b[j];
		}
		if(b[k]<ans)
		{
			cnt++;
			for(int j=1;j<=k;j++)
			{
				cout<<b[j]<<" ";
			}
			cout<<endl;	
		}
	}
	cout<<cnt;
	return 0;	
}
