#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int r[1000005];
struct road{
	int st,nd;
	int c;
} a[1000005];
struct rebuild{
	int bc;
	int newc[10005];
} b[11];
//bool cmp(road p,road q){
//	return 	(p.st<q.st)||(p.st==q.st&&p.nd<q.nd);
//}
//void dfs(int x,int price){
//	if(x==m+1){
//		for(int i=1;i<=n;i++){
//			if(r[i]==0) return ;
//		}
//		if(price<ans){
//			ans=price;
//			return ;
//		}
//	}
//	r[a[x].st]++;
//	r[a[x].nd]++;
//	dfs(x+1,price+a[x].c);
//	r[a[x].st]--;
//	r[a[x].nd]--;
//	dfs(x+1,price); 
//}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; 
	for(int i=1;i<=m;i++){
		cin>>a[i].st>>a[i].nd>>a[i].c;
		ans+=a[i].c; 
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].bc;
		for(int j=1;j<=n;j++) cin>>b[i].newc[j];
	}
	//sort(a+1,a+m+1,cmp);
//	dfs(1,0);
	cout<<ans;
	return 0;
} 
//  ¦Å£½¦Å£½¦Å£½(#>§¥<)/
//  ¦Å=(¡ä¦Ï£à*))) 
