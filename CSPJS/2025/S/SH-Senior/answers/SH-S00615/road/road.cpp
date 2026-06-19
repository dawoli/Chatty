#include<iostream>
using namespace std;
int n,m,k,pd,index,ans,sum,u[1000001],v[1000001],w[1000001],c[11],a[11][10001],father[10001];
int fa(int x){
	if(father[x]==x)return x;
	x=fa(father[x]);
}
void link(int x,int y){
	father[y]=x;
}
void af(){
	for(int i=1;i<=n;i++)fa(i);
}
int un(){
	for(int i=1;i<n;i++)if(father[i]!=father[i+1])return i;
	else return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int l=1;l<=n;l++)cin>>a[j][l];
	}
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	pd=1;
	while(pd){
		index=1;
		for(int i=1;i<=m;i++)if(w[i]<w[index]){
			index=i;
		    link(u[i],v[i]);ans+=w[i];
		}
		af();
		pd=un();
	}
	cout<<sum;
	return 0;
}
