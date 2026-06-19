#include<bits/stdc++.h>
using namespace std;
const int MX=998244353;
int n;
int a[5005];
long long t[5005][5005];
long long cnt[5005];
long long bggr[5005];
long long ans=0;
//long long all=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
//		all+=a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	t[0][0]=1;
	memset(cnt,0,sizeof(cnt));
	memset(bggr,0,sizeof(bggr));
	for(int i=1;i<=n;i++)
	{
		bggr[i]=bggr[i-1]*2;
		for(int j=0;j<=5000;j++)
		{
			t[i][j]=t[i-1][j];
			t[i][j]%=MX;
			if(j>a[i+1])
			{
				cnt[i]+=t[i][j];
				cnt[i]%=MX;
			}
		}
		for(int j=5000;j>=0;j--)
		{
			if(j+a[i]>5000)
			{
				bggr[i]+=t[i][j];
				bggr[i]%=MX;
				continue;
			}
			t[i][j+a[i]]+=t[i][j];
			if(j+a[i]>a[i+1])
			{
				cnt[i]+=t[i][j];
//				if(t[i][j])
//				{
//					cout<<"!"<<j<<" "<<j+a[i]<<" "<<t[i][j]<<endl;
//				}
				cnt[i]%=MX;
			}
			t[i][j+a[i]]%=MX;
		}
//		cout<<a[i]<<" "<<a[i+1]<<" "<<cnt[i]<<" "<<bggr[i]<<endl;
	}
	for(int i=n;i>=3;i--)
	{
		ans+=cnt[i-1]+bggr[i-1];
		ans%=MX;
	}
//	cout<<all<<endl;
	cout<<ans<<endl;
	return 0;
}
/*
10
4999 2999 5000 4998 4997 3999 3000 2709 2000 1
*/
