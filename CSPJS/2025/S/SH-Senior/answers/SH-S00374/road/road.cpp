#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
struct s{
	int u,v,w;
}a[1000009];
int b[19][1009];
int n,m,k,cnt;
int f[10009],c[19];
long long ans;
bool cmp(s x,s y){
	return x.w<y.w;
}
int get(int x){
	if(f[x]==x)return x;
	return f[x]=get(f[x]);
}
void merge(int x,int y){
	int fx=get(x),fy=get(y);
	f[fx]=fy;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>b[i][j];
	}
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			m++;
			a[m].u=m,a[m].v=j,a[m].w=b[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(get(u)==get(v))continue;
		ans+=w;
		merge(u,v);
		cout<<u<<' '<<v<<' '<<w<<'\n';
//		cnt++;
	}
	cout<<ans;
//	if(cnt==n-1)cout<<ans;
//	else cout<<114514;
//	cout<<'\n';
//	for(int i=1;i<=m;i++){
//		cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].w<<'\n';
//	}
//	for(int i=1;i<=n;i++)cout<<f[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
