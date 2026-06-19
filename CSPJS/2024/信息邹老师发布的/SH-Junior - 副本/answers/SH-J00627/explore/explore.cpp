#include<bits/stdc++.h>
using namespace std;
string a[1005];int b[1005][1005];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;cin>>t;
	int x,y,m,n,d,k,cnt=0;
	while(t)
	{

        cin>>n>>m>>k;cin>>x>>y>>d;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=k;i++)
		{
			b[x][y]=1;
			if(d==0){
			if(y!=m&&a[x-1][y]=='.')
			{
				y=y+1;
			}
			else
			{
			    d=1;continue;
			}
		}
		if(d==1){

			if(x!=n&&a[x][y-1]=='.')
			{
				x=x+1;
			}
			else
			{
			    d=2;continue;
			}}
			if(d==2){

			if(y!=0&&a[x-1][y-2]=='.')
			{
				y=y-1;
			}
			else
			{
			    d=3;continue;
			}}
			if(d==3){
			if(x!=0&&a[x-2][y-1]=='.')
			{
				x=x-1;
			}
			else
			{
			    d=0;continue;
			}}
		}
		b[x][y]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][j])cnt++;
				b[i][j]=0;
			}
		}
		cout<<cnt<<endl;
		cnt=0;
		t--;
	}
	return 0;
}
