#include<bits/stdc++.h>
typedef long long LL;
#define int LL
using namespace std;
namespace SH_S00929huletian
{
	inline char get_char()
	{
		char c=getchar();
		while(c<=32&&c!=EOF) c=getchar();
		return c;
	}
	inline int read()
	{
		int x=0,f=1;
		char c=getchar();
		for(;c<'0'||c>'9';c=getchar()){if(c=='-') f=-1;if(c==EOF) return EOF;}
		for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+c-'0';
		return x*f;
	}
	inline void write(int x)
	{
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	inline void fast()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	}
	const int N=1e4+1,M=2e6+1,K=11,INF=1e9;
	int n,m,k,c[K],a[K][N];
	signed edge[N][N];
	/*
	int edges=0,head[N];
	struct Edge{
		int to,next,w;
	}edge[M];
	inline void add(int u,int v,int w)
	{
		edge[++edges]=Edge{v,head[u],w};
		head[u]=edges;
	}
	*/
	inline bool check(int x)
	{
		if(c[x]!=0) return false;
		for(int i=1;i<=n;++i)
			if(a[x][i]!=0) return false;
		return true;
	}
	int s[N];
	struct Edge{
		int u,v,w;
	}e[M];
	inline bool cmp(Edge a,Edge b)
	{
		return a.w<b.w;
	}
	inline int find(int x)
	{
		if(s[x]!=x) s[x]=find(s[x]);
		return s[x];
	}
	inline void input()
	{
		n=read();m=read();k=read();
		//assert(m);
		for(int i=1;i<=n;++i) s[i]=i;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j){
				if(i==j) edge[i][j]=0;
				else edge[i][j]=INF;
			}
		for(int i=1;i<=m;++i){
			e[i].u=read();e[i].v=read();e[i].w=read();
			//if(e[i].u==e[i].v) throw 1;
			//if(e[i].w==0) throw 1;
			edge[e[i].u][e[i].v]=min((LL)edge[e[i].u][e[i].v],e[i].w);
		}
		for(int i=1;i<=k;++i){
			c[i]=read();
			for(int j=1;j<=n;++j) a[i][j]=read();
		}
	}
	inline int solve()
	{
		sort(e+1,e+m+1,cmp);
		int ans=0;
		for(int i=1;i<=m;++i){
			int fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy){
				//++ans;
				//cout<<"continue";
				continue;
			}
			s[fx]=fy;
			ans+=min(e[i].w,(LL)min(edge[e[i].u][e[i].v],edge[fx][fy]));
			//cout<<"running";
		}
		return ans;
	}
	int main()
	{
		/*
		for(int i=1;i<=m;++i){
			int u,v,w;
			u=read();v=read();w=read();
			add(u,v,w);
			add(v,u,w);
		}
		*/
		input();
		for(int i=1;i<=k;++i)
			if(check(i)){
				putchar('0');
				//throw 1;
				return 0;
			}
		for(int v=1;v<=k;++v)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j) edge[i][j]=min((LL)edge[i][j],c[v]+a[v][i]+a[v][j]);
		write(solve());
		return 0;
	}
}
signed main()
{
	//ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
	//1234567890-=[]{};:'"',./?><~`!@#$%^&*()1234567890.+-*/\|
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	SH_S00929huletian::main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

