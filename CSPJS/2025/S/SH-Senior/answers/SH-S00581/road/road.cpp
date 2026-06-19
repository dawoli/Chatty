#include <bits/stdc++.h>
using namespace std;
int fa[2000010];
struct Edge{
	int a,b,val;
}a[2000010],b[2000010];
int c[100010],ci[20][100010];
int g[20];
int n,m,k,t,ans,ma,mb,t1;
bool cmp(const Edge &a,const Edge &b){
	return a.val<b.val;
}
int find(int x){
	if(fa[x]==x){
		return fa[x];
	}else{
		return fa[x]=find(fa[x]);
	}
}
void f(int x){
	if(x==k+1){
		for(int i=1;i<=n+k;++i){
			fa[i]=i;
		}
		int ans1=0;
		ma=0;
		memset(b,0,sizeof(b));
		for(int i=1;i<=m;++i){
			b[i]=a[i];
		}
		for(int i=1;i<=k;++i){
			if(g[i]){
				ans1+=c[i];
				t1++;
				ma+=n;
				for(int j=ma+m-n+1;j<=ma+m;++j){
					b[j].a=i+n;
					b[j].b=j-ma+n-m;
					b[j].val=ci[i][j-ma-m+n];
				}
			}
		}
		sort(b+1,b+m+ma+1,cmp);
		t=0;
		for(int i=1;i<=m+ma;++i){
			if(t==n+t1-1){
				break;
			}
			int x=find(b[i].a),y=find(b[i].b);
			if(x==y){
				continue;
			}
			fa[x]=fa[y];
			ans1+=b[i].val;
			t++;
		}
		ans=min(ans,ans1); 
	}else{
		g[x]=0;
		f(x+1);
		g[x]=1;
		f(x+1);
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;++i){
		fa[i]=i;
	}
	ma=m;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].val);
	}
	for(int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;++j){
			scanf("%d",&ci[i][j]);
		}
	}
	if(k==0){
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;++i){
			if(t==n-1){
				break;
			}
			int x=find(a[i].a),y=find(a[i].b);
			if(x==y){
				continue;
			}
			fa[x]=fa[y];
			ans+=a[i].val;
			t++;
		}
		cout<<ans;
	}else{
		ans=0x3f3f3f3f;
		f(1);
		cout<<ans;
	}
	return 0;
}
