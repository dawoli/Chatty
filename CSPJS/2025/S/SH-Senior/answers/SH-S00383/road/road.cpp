#include<bits/stdc++.h>
using namespace std;
int fa[1010];
struct ss{
	int s,e,mon;
}a[2000010];
bool cmp(ss a1,ss b1){
	return a1.mon<b1.mon;
}
int find(int x){
	if(fa[x]==x)return x;
	else return find(fa[x]);
}
int n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k!=0){
		cout<<0;
		return 0;
	} 
	for(int i=1;i<=m;i++){
		cin>>a[i].s>>a[i].e>>a[i].mon;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int tx=find(a[i].s);
		int ty=find(a[i].e);
		if(tx!=ty){
			ans+=a[i].mon;
			fa[tx]=ty;
		}
	}
	cout<<ans;
	return 0;
}
