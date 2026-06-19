#include <bits/stdc++.h>
using namespace std;
int t;
int n,m,k,x,y,d;
int ans;
char a[1005][1005];
bool b[1005][1005];
void search(int p,int q,int r,int s)//x,y,d,k
{
	if(s<0)
	{
		return;
	}
	else
	{
		//cout<<'('<<p<<','<<q<<')'<<' '<<s<<endl;
		if(a[p][q]=='.'&&p<=n&&q<=m)
		{
			if(!b[p][q])
			{
				ans++;
				b[p][q]=true;
			}
			
			if(r==0)search(p,q+1,r,s-1);
			else if(r==1)search(p+1,q,r,s-1);
			else if(r==2)search(p,q-1,r,s-1);
			else search(p-1,q,r,s-1);
		}
		else
		{
			if(r==0)search(p,q-1,1,s);
			else if(r==1)search(p-1,q,2,s);
			else if(r==2)search(p,q+1,3,s);
			else search(p+1,q,0,s);
		}
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				b[i][j]=false;
			} 
		}
		ans=0;
		search(x,y,d,k);
		cout<<ans<<'\n';
	}
	return 0;
}

