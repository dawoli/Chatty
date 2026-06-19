#include<bits/stdc++.h>
using namespace std;
int a[1024][1024];
int tr(int t){
	return t==3?0:t+1;
}
bool cg(int x,int y,int d)
{
	if(d==0)if(a[x][y+1]==0)return false;
	if(d==1)if(a[x+1][y]==0)return false;
	if(d==2)if(a[x][y-1]==0)return false;
	if(d==3)if(a[x-1][y]==0)return false;
	return true;
}
void t()
{
	int n,m,k;
	int x,y,d;
	int s=0;
	char c;
	cin>>n>>m>>k>>x>>y>>d;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>c,a[i][j]=c=='.'?1:0;
	a[x][y]=2;
	for(int b=0;b<k;b++){
//		for(int i=0;i<=n;i++,cout<<endl)for(int j=0;j<=m;j++)
//		if(a[i][j]==0)cout<<'x';
//		else if(a[i][j]==1)cout<<'-';
//		else cout<<'@';
//		cout<<endl;
		int fl=0;
		for(int e=0;e<4;e++)if(cg(x,y,d)==false)d=tr(d),fl++,b++;
		if(b>=k) break;
		if(fl==4)break;
		if(d==0)a[x][y+1]=2,y++;
		if(d==1)a[x+1][y]=2,x++;
		if(d==2)a[x][y-1]=2,y--;
		if(d==3)a[x-1][y]=2,x--;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]==2)s++;
	cout<<s<<endl;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	t();
	return 0;
}
