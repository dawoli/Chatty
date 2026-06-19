#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int all1;
struct node{
	int start,end;
};
int a[500009];
int d[500009];
node g[500009];
const int inf=1e9+7;
bool cmp(node a,node b){
	return a.end<b.end;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[i].start=i;
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((d[j]^d[i-1])==k){
				g[i].end=j;
				break;
			}
		}
		if(g[i].end==0){
			g[i].end=inf;
		}
	}
	sort(g+1,g+1+n,cmp);
	int ed=0;
	for(int i=1;i<=n;i++){
		if(g[i].end==inf) break;
		if(g[i].start>ed){
			ed=g[i].end;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
