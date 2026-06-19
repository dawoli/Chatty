#include<bits/stdc++.h>
using namespace std;
char s[1010][1010];
map<pair<int,int>,int>mp;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int nx,ny,d;
		cin>>nx>>ny>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>s[i][j];
			}
		}
		int ans=1;
		mp.clear();
		mp[make_pair(nx,ny)]=1;
		while(k)
		{
			if(d==0)
			{
				if(ny+1>m||s[nx][ny+1]=='x')
				{
					d++;
				}
				else
				{
					ny++;
				}
				k--;
				if(mp[make_pair(nx,ny)]==0)
				{
					ans++;
					mp[make_pair(nx,ny)]=1;
				}
			}
			else if(d==1)
			{
				if(nx+1>n||s[nx+1][ny]=='x')
				{
					d++;
				}
				else
				{
					nx++;
				}
				k--;
				if(mp[make_pair(nx,ny)]==0)
				{
					ans++;
					mp[make_pair(nx,ny)]=1;
				}
			}
			else if(d==2)
			{
				if(ny-1<1||s[nx][ny-1]=='x')
				{
					d++;
				}
				else
				{
					ny--;
				}
				k--;
				if(mp[make_pair(nx,ny)]==0)
				{
					ans++;
					mp[make_pair(nx,ny)]=1;
				}
			}
			else
			{
				if(nx-1<1||s[nx-1][ny]=='x')
				{
					d=0;
				}
				else
				{
					nx--;
				}
				k--;
				if(mp[make_pair(nx,ny)]==0)
				{
					ans++;
					mp[make_pair(nx,ny)]=1;
				}
			}
			//cout<<nx<<" "<<ny<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
