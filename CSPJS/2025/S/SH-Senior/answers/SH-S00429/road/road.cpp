#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m,k,c,y,idx,fa[10005];
ll mp[1005][1005],d[10005],x;
struct node{
	int u,v,w;
}a[5000006];
int get(int x){
	if(fa[x]==x)	return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		fa[i]=i;
		if(n<=1004)
		for(int j=1;j<=n;++j){
			mp[i][j]=1e19;
		}
	}
	for(int i=1;i<=m;++i){
		cin>>c>>y>>x;
		if(k==0){
			a[++idx].u=c;
			a[idx].v=y;
			a[idx].w=x;	
		}else{
			mp[c][y]=min(mp[c][y],x);
			mp[y][c]=min(mp[y][c],x);
		}
	}
	for(int i=1;i<=k;++i){
		cin>>c;
		for(int j=1;j<=n;++j) cin>>d[j];
		for(int j=1;j<=n;++j){
			for(int z=1;z<=n;++z){
				mp[j][z]=min(mp[j][z],c+d[j]+d[z]);
				mp[z][j]=min(mp[z][j],c+d[j]+d[z]);
			}
		}	
	}
	if(k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				a[++idx].u=i;
				a[idx].v=j;
				a[idx].w=mp[i][j];
			}
		}
	}
	int b=0;
	ll ans=0;
	sort(a+1,a+1+idx,cmp);
	for(int i=1;i<=idx;++i){
		if(get(a[i].u)==get(a[i].v))	continue;
		merge(a[i].u,a[i].v);
		ans+=a[i].w;
		//cout<<a[i].u<<" "<<a[i].v<<endl;
		b++;
		if(b>=n-1)	break;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
