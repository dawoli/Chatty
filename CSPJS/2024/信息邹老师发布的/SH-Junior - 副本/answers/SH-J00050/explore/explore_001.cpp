#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char sto[N][N];
bool ved[N][N];
int fangx[5]={0,1,0,-1};
int fangy[5]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin); 
	freopen("explore.out","w",stdout); 
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		memset(ved,0,sizeof(ved));
		int xx,yy,d;
		scanf("%d%d%d",&xx,&yy,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",sto[i]+1);
		}
		ved[xx][yy]=1;
		for(int i=1;i<=k;i++)
		{
			int nx=xx+fangx[d];
			int ny=yy+fangy[d];
			//cout<<"t "<<nx<<" "<<ny<<endl;
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && sto[nx][ny]=='.')
			{
				xx=nx;
				yy=ny;
			}
			else
			{
				d++;
				if(d==4)d=0;
			}
			//cout<<i<<" "<<k<<" "<<xx<<" "<<yy<<endl; 
			ved[xx][yy]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ved[i][j]==1)ans++;
			}
		}
		printf("%d\n",ans);
	}
} 
