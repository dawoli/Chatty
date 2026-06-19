#include<bits/stdc++.h>
using namespace std;

int arr[1010][1010];
int t;
int n,m,k;
int x,y,d;
string s;
int ans;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main()
{
	
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	cin>>t;
	while(t--)
	{
		
		memset(arr,0,sizeof arr);
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=0;j<m;j++)
			{
				arr[i][j+1]= s[j]=='x' ? 1 : 0; 
			}
		}
		while(k--)
		{
			if(arr[x][y]==0)
			{
				ans++;
				arr[x][y]=2;
			}
			int nx=x+dx[d];
			int ny=y+dy[d];
			if(arr[nx][ny]!=1 && nx>=1 && nx<=n && ny>=1 && ny<=m)
			{
				x=nx;y=ny;
			}
			else
			{
				d+=1;
				d%=4;
			}
		}
		if(arr[x][y]==0)
		{
			ans++;
			arr[x][y]=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
