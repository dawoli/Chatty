#include<bits/stdc++.h>
using namespace std;
struct road{
	int u;
	int v;
	int w;
}r[1000010];
bool cmp(road x,road y){
	if(x.u==y.u){
		if(x.v==y.v){
			return x.w<y.w;
		}else{
			return x.v<y.v;
		}
	}else{
		return x.u<y.u;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ans=0;
	int n,m,k;
	cin>>n>>m>>k;
	r[0].u=-1;
	r[0].v=-1;
	r[0].w=0;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b>>r[i].w;
		if(a<b){
			r[i].u=b;
			r[i].v=a;
		}else{
			r[i].u=a;
			r[i].v=b;
		}
	}
	for(int i=0;i<k;i++){
		int a,b,c;
		cin>>a>>b>>c;
	}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(r[i].u==r[i-1].u&&r[i].v==r[i-1].v){
			ans+=0;
		}else{
			ans+=r[i].w;
		}
	}
	cout<<ans;
	return 0;
}
