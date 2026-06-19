#include<bits/stdc++.h>
using namespace std;
const int N=2e6+9;
int n,m,k;
int c[15][N];
int f[N];
int sum;
struct node{
	int u,v,w,n=0;
}a[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int get(int id){
	if(f[id]==id) return id;
	else{
		return get(f[id]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int id;
	for(id=1;id<=m;id++){
		cin>>a[id].u>>a[id].v>>a[id].w;
	}
	if(k==0){
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		int cnt=0;
		for(int i=1;i<=m;i++){
			if(get(a[i].u)==get(a[i].v)) continue;
			f[a[i].v]=get(f[a[i].u]);
			cnt++;
			sum+=a[i].w;
			if(cnt==n-1) break;
		}
		cout<<sum;
	}else{
		for(int i=1;i<=k;i++){
			for(int j=0;j<=n;j++){
				cin>>c[i][j];
				if(j!=0){
					a[id++].u=i;
					a[id].v=j;
					a[id].w=c[i][j]+c[i][0];
					a[id].n=i;
				}
			}
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		int cnt=0;
		for(int i=1;i<=m;i++){
			if(get(a[i].u)==get(a[i].v)) continue;
			if(c[a[i].n][0]>0){
				sum+=c[a[i].n][0];
				c[a[i].n][0]=-c[a[i].n][0];
			}
			f[a[i].v]=get(f[a[i].u]);
			cnt++;
			sum+=a[i].w+c[a[i].n][0];
			if(cnt==n-1) break;
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
