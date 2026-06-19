#include<bits/stdc++.h>
using namespace std;
int n,m,k,du[10020],step;
struct road{
	int a,b,w;
}r[1000025];
bool cmp(road x,road y){
	return x.w>y.w;
}
long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].a>>r[i].b>>r[i].w;
		du[r[i].a]++;
		du[r[i].b]++;
		//v[r[i].a][r[i].b]=1;
		sum+=r[i].w;
	}
	sort(r+1,r+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(du[r[i].a]>1&&du[r[i].b]>1){
			du[r[i].a]--;
			du[r[i].b]--;
			sum-=r[i].w;
		}
	}
	cout<<sum;
	return 0;
}

