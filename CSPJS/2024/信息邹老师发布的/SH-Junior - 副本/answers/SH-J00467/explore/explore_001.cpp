#include<bits/stdc++.h>
using namespace std;
bool ma[1003][1003],ans[1003][1003];
int t,n,m,k,a,b,d,cnt=0;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>a>>b>>d;
		ans[a][b]=1;
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				if(s[j-1]=='.') ma[i][j]=1;
				else ma[i][j]=0;
			}
		}
		for(int i=1;i<=k;i++)
		{
			if(d==0) 
			{
				if(b+1<=m&&ma[a][b+1]) {
					b++;
					ans[a][b]=1;
				}
				else d=1;
			}
			else if(d==1)
			{
				if(a+1<=n&&ma[a+1][b]) {
					a++;
					ans[a][b]=1;
				}
				else d=2; 
			}
			else if(d==2)
			{
				if(b!=1&&ma[a][b-1]) {
					b--;
					ans[a][b]=1;
				}
				else d=3;
			}
			else
			{
				if(a!=1&&ma[a-1][b]) {
					a--;
					ans[a][b]=1;	
				}
				else d=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ans[i][j])
				{
					cnt++;
					ans[i][j]=0;
				}
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
