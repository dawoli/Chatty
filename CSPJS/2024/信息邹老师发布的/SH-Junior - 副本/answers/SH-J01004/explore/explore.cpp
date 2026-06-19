#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	int d1[4]={0,1,0,-1};
	int d2[4]={1,0,-1,0};
	cin>>t;
	while(t--)
	{
		int n,m,k;
		string mp[1005]={};
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=0;i<n;i++)
		{
			cin>>mp[i];
		}
		x--,y--;
		int cnt=0;
		if(x+d1[d]<0||x+d1[d]>n||y+d2[d]<0||y+d2[d]>m||mp[x+d1[d]][y+d2[d]]!='.') cnt++;
		while(k--)
		{
			if(x+d1[d]>=0&&x+d1[d]<n&&y+d2[d]>=0&&y+d2[d]<m)
			{
				if(mp[x+d1[d]][y+d2[d]]!='x')
				{
					x+=d1[d];
					y+=d2[d];
					//cout<<x<<" "<<y<<endl;
					cnt++;
				}
				else
				{
					d=(d+1)%4;
				}
			}
			else
			{
				d=(d+1)%4;
			}
		}
		//cout<<mp[4][0]<<endl;
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
