#include<bits/stdc++.h>
using namespace std;
struct rd
{
	int s,e,v;	
}a[2000005];
int town[15],trd[15][10005];
int minn=1e9;
inline int read()
{
	int f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		f=f*10+ch-'0';
		ch=getchar();
	}
	return f;
}
int n,m,k;
bool cmpp(rd x,rd y)
{
	return x.v<y.v;
}
int fa[100005];
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
int kus()
{
	
	int cnt=1,as=0,i=1;
	bool ifbut[15]={false};
	while(1)
	{
		int x=a[i].s,y=a[i].e;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy,as+=a[i].v;
			if(x<=n&&y<=n)	cnt++;
			if(x>n&&ifbut[x]) cnt++;
			if(y>n&&ifbut[y]) cnt++;
			if(x>n)	ifbut[x]=true;
			if(y>n) ifbut[y]=true;
		}
		if(cnt==n-1)
			break;
		i++;
	}
	return as;
}

void krustral()
{
	int cnt=1,ans=0,i=1;
	while(1)
	{
		int x=a[i].s,y=a[i].e;
		int fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			fa[fx]=fy,ans+=a[i].v,cnt++;
		}
		if(cnt==n)
			break;
		i++;
	}
	cout<<ans<<endl;
}
bool tmp[11];
int init()
{
	
	int ans=0,newm=m;
	for(int i=1;i<=k;i++)
	{
		
		if(tmp[i])
		{
			fa[n+i]=n+i;
			ans+=town[i];
			for(int j=1;j<=n;j++)
			{
				a[++newm].s=n+i,a[newm].e=j,a[newm].v=trd[i][j];
			}
		}
	}
	sort(a+1,a+newm+1,cmpp);
	ans+=kus();
	return ans;
}
void dfs(int x)
{
	if(x==k)
	{
		minn=min(minn,init());
		return ;
	}
	tmp[x]=false;
	dfs(x+1);
	tmp[x]=true;
	dfs(x+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
//	cout<<n<<m<<k<<endl;
	for(int i=1;i<=m;i++)
	{
		a[i].s=read(),a[i].e=read(),a[i].v=read();
	}
	
	if(k==0)
	{
		sort(a+1,a+m+1,cmpp);
		for(int i=1;i<=n;i++)
			fa[i]=i; 
	//	for(int i=1;i<=m;i++)
	//		cout<<a[i].s<<' '<<a[i].e<<' '<<a[i].v<<endl;
		krustral();
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		town[i]=read();
		for(int j=1;j<=n;j++)
		{
			trd[i][j]=read();
		}
	}
	dfs(1);
	cout<<minn<<endl;
	return 0;
}

