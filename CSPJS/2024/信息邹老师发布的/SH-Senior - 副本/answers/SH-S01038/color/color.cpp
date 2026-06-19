#include<bits/stdc++.h>
using namespace std;
int a[200005][15];
int ans[15];
bool b[200005][15]={0};
void dfs(int x,int y,int tt)
{
	if(x==1)
	{
		int s=0;
		for(int ii=1;ii<=y;ii++)
		{
			for(int jj=ii+1;jj<=y;jj++)
			{
				if(b[jj][tt]==b[ii][tt])
				{
					if(a[jj][tt]!=a[ii][tt]) break;
					else
					{
						s+=a[jj][tt];
						break;
					}
				}
			}
		}
		ans[tt]=max(ans[tt],s);
		return;
	}
	dfs(x-1,y,tt);
	for(int ii=x;ii<=y;ii++)
	{
		if(a[ii][tt]==a[x-1][tt])
		{
			for(int jj=x;jj<=ii-1;jj++) b[jj][tt]=(b[ii][tt]+1)%2;
			b[x-1][tt]=b[ii][tt];
			dfs(x-1,y,tt);
			break;
		}
	}

}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		ans[t]=0;
		int n,s=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][t];
			b[i][t]==0;
		}
		dfs(n,n,t);
		cout<<ans[t]<<endl;
	}
	return 0;
}
