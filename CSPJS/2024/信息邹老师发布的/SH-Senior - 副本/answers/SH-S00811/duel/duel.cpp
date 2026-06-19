#include<bits/stdc++.h>
using namespace std;
int r[100005];
bool vis[100005];
//queue<int>q;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int cnt=n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r+1,r+1+n);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<r[i]<<" ";
//	}
	if(n<=31)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(r[i]>r[j]&&vis[j]==false)
				{
					cnt--;
					vis[j]==true;
//					cout<<i<<" "<<j<<endl;
					break;
				}
			}
		}
		cout<<cnt;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(r[i]==2&&n-i+1>=i-1)
			{
				cout<<n-i+1;
				return 0;
			}
			if(r[i]==2)
			{
				cout<<i+1;
				return 0;
			}
		}
	}
	
	return 0;
}
//10

//136 136 136 2417 136 136 2417 136 136 136

