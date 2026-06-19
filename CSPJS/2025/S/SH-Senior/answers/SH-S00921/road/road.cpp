#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
const int maxn1=1e3+5;
const int maxm=1e6+5;
int n,m,k,fa[maxn],cnt_edge;
long long c[15],a[15][maxn],e1[maxn1][maxn1],t[maxn1][maxn1],ans,ans1=1e18;
bool flag,flag1[15];
struct edge{long long u,v,w;}e[maxm];
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){fa[find(x)]=find(y);}
void kru(int num){
	int cnt=0;
	sort(e+1,e+1+num,cmp);
	for(int i=1;i<=num;i++){
		int u=e[i].u,v=e[i].v;long long w=e[i].w;
		if(find(u)!=find(v)){
			merge(u,v);
			cnt++;
			ans+=w;
			if(cnt==n-1)return;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(e1,0x3f,sizeof(e1));
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v;long long w;cin>>u>>v>>w;
		e[i]={u,v,w};
		if(n<=1000)e1[min(u,v)][max(u,v)]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flag=true;
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	if(k==0){
		kru(m);
		cout<<ans<<endl;
	}
	else if(n<=1000){
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				t[i][j]=e1[i][j];
		for(int used=0;used<=(1<<k)-1;used++){
			int tmp=used,cur=0;
			ans=0;
			while(tmp!=0){
				cur++;
				if(tmp%2==1){
					flag1[cur]=true;
					ans+=c[cur];
				}
				else flag1[cur]=false;
				tmp/=2;
			}
			cnt_edge=0;
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++){
					for(int l=1;l<=k;l++)
						if(flag1[l])e1[i][j]=min(e1[i][j],a[l][i]+a[l][j]);
					if(e1[i][j]!=0x3f3f3f3f)e[++cnt_edge]={i,j,e1[i][j]};
				}
			for(int i=1;i<=n;i++)fa[i]=i;
			kru(cnt_edge);
			ans1=min(ans,ans1);
			for(int i=1;i<n;i++)
				for(int j=i+1;j<=n;j++)
					e1[i][j]=t[i][j];
		}
		cout<<ans1<<endl;
	}
	return 0;
}
