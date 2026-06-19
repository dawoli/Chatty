#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int z[1005][1005];
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

void write(long long x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0'); 
}

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long t;
	t=read();
	while(t--)
	{
		memset(z,0,sizeof(z));
		long long n,m,k,x,y,d,ans=0;
		n=read();
		m=read();
		k=read();
		x=read();
		y=read();
		d=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		while(k>0)
		{
			z[x][y]=1;
			if(d==0)
			{
				if(a[x][y+1]=='.'&&x<=n&&x>=1&&(y+1)<=m&&(y+1)>=1) y=y+1,d=0;//d=0
				else if(a[x+1][y]=='.'&&(x+1)<=n&&(x+1)>=1&&y<=m&&y>=1) x=x+1,d=1,k--;//d=1
				else if(a[x][y-1]=='.'&&x<=n&&x>=1&&(y-1)<=m&&(y-1)>=1) y=y-1,d=2,k-=2;//d=2
				else if(a[x-1][y]=='.'&&(x-1)<=n&&(x-1)>=1&&y<=m&&y>=1) x=x-1,d=3,k-=3;//d=3
			}
			else if(d==1)
			{
				if(a[x+1][y]=='.'&&(x+1)<=n&&(x+1)>=1&&y<=m&&y>=1) x=x+1,d=1;//d=1
				else if(a[x][y-1]=='.'&&x<=n&&x>=1&&(y-1)<=m&&(y-1)>=1) y=y-1,d=2,k--;//d=2
				else if(a[x-1][y]=='.'&&(x-1)<=n&&(x-1)>=1&&y<=m&&y>=1) x=x-1,d=3,k-=2;//d=3
				else if(a[x][y+1]=='.'&&x<=n&&x>=1&&(y+1)<=m&&(y+1)>=1) y=y+1,d=0,k-=3;//d=0
			}
			else if(d==2)
			{
				if(a[x][y-1]=='.'&&x<=n&&x>=1&&(y-1)<=m&&(y-1)>=1) y=y-1,d=2;//d=2
				else if(a[x-1][y]=='.'&&(x-1)<=n&&(x-1)>=1&&y<=m&&y>=1) x=x-1,d=3,k--;//d=3
				else if(a[x][y+1]=='.'&&x<=n&&x>=1&&(y+1)<=m&&(y+1)>=1) y=y+1,d=0,k-=2;//d=0
				else if(a[x+1][y]=='.'&&(x+1)<=n&&(x+1)>=1&&y<=m&&y>=1) x=x+1,d=1,k-=3;//d=1
			}
			else if(d==3)
			{
				if(a[x-1][y]=='.'&&(x-1)<=n&&(x-1)>=1&&y<=m&&y>=1) x=x-1,d=3;//d=3
				else if(a[x][y+1]=='.'&&x<=n&&x>=1&&(y+1)<=m&&(y+1)>=1) y=y+1,d=0,k--;//d=0
				else if(a[x+1][y]=='.'&&(x+1)<=n&&(x+1)>=1&&y<=m&&y>=1) x=x+1,d=1,k-=2;//d=1
				else if(a[x][y-1]=='.'&&x<=n&&x>=1&&(y-1)<=m&&(y-1)>=1) y=y-1,d=2,k-=3;//d=2
			}
			k--;
		}
		if(k>=0) z[x][y]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(z[i][j]==1) ans++;
			}
		}
		write(ans);
		printf("\n");
	}
	return 0;
}
