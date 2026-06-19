#include <bits/stdc++.h>
using namespace std;
int T,n,minn,WeiShu;
int stick[11]={6,2,5,0x3f3f3f3f,4,0x3f3f3f3f,6,3,7,0x3f3f3f3f};
bool vis[11]={1,1,1,0,1,0,1,1,1,0};
int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--)
	{
		minn=10;
		cin>>n;
		if(n<=1) cout<<-1<<"\n";
		else
		{
			WeiShu=ceil(n/7.0);
			for(int i=1;i<=WeiShu;i++)
			{
				minn=10;
				for(int j=0;j<=9;j++)
				{
					vis[j]=1;
				}
				if(i==1) vis[0]=0;
				else vis[0]=1;
				for(int j=0;j<=9;j++)
				{
					if(ceil((n-stick[j])/7.0)!=WeiShu-i&&n!=stick[j])
					vis[j]=0;
				}
				if(i==WeiShu)
				{
					for(int j=0;j<=9;j++)
					{
						if(stick[j]==n && vis[j]) cout<<j;
					}
				}
				else
				{
					for(int j=0;j<=9;j++)
					{
						if(vis[j] && j<minn && n-stick[j]!=1) minn=j;
					}
					cout<<minn;
					n-=stick[minn];
				}
			}
			cout<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
}
