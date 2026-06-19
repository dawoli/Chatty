#include<bits/stdc++.h> 
using namespace std;
int n,m,k;
int fa[10001];
int deep[10001];
int c[11];
int cm[11][10001];
long long ans=0;
int t;
struct x{
	int u;
	int v;
	long long w;
}a[2000001];
bool cmp(x a,x b){
	return a.w<b.w;
}
int findf(int a){
	if(fa[a]!=a){
		fa[a]=findf(fa[a]);
	}
	return fa[a];
}
void hebing(int a,int b){
	int af=findf(a);
	int bf=findf(b);
	if(a==b)return;
	if(deep[af]>deep[bf]){
		fa[bf]=af;
	}
	else if(deep[af]==deep[bf]){
		fa[bf]=af;deep[af]++;
	}
	else fa[af]=bf;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;t=m+1;
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)	cin>>cm[i][j];
		for(int j=1;j<=n;j++){
			if(cm[i][j]==0){
				for(int ii=1;ii<=n;ii++){
					if(ii!=j){
						a[t].u=ii,a[t].v=j,a[t].w=cm[i][ii];
						t++;
					}
				}
			}
		}
	}
	sort(a+1,a+t,cmp);
	for(int i=1;i<t;i++){
		if(findf(a[i].u)!=findf(a[i].v)){
			hebing(a[i].u,a[i].v);
			ans+=a[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}
//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//0 2 0 9 9
//0 9 9 9 9 
