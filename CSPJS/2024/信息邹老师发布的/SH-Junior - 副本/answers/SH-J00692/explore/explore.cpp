#include<bits/stdc++.h>
using namespace std;
char mp[1024][1024];
//x-obstacles
//.-empty
//a-achieved
long long n,m,k,t,x,y,d,x0,y0,ans;
string s;
int main()
{
	if(true)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		freopen("explore.in","r",stdin);
		freopen("explore.out","w",stdout);		
	}
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			for(int j=0;j<m;j++)
				mp[i+1][j+1]=s[j];
		}
		mp[x][y]='a';
		ans=1;
		int i=0;
		while(i<k)
		{
			x0=x,y0=y;
			if(d==0)
				y0+=1;
			else if(d==1)
				x0+=1;
			else if(d==2)
				y0-=1;
			else
				x0-=1;
			if(y0>m||y0<1||x0>n||x0<1||mp[x0][y0]=='x')
			{
				i++;
				d=(d+1)%4;
			}
			else
			{
				x=x0;
				y=y0;
				if(mp[x][y]!='a')
					ans++;
				mp[x][y]='a';
				i++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
