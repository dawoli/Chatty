#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7;
struct node{
	int from,to,len;
}a[N];
int n,m,k;
int fa[10010];
int ans;

bool cmp(node x,node y){
	return x.len<y.len;
}
int take(int x){
	if(fa[x] == x) return fa[x];
	return fa[x] = take(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++) fa[i] = i;
	for(int i = 1;i<=m;i++){
		cin>>a[i].from>>a[i].to>>a[i].len;
	}
	for(int i = 1;i<=k;i++){
		int v;
		cin>>v;
		for(int j = 1;j<=n;j++){
			int x;
			cin>>x;
			a[m+(i-1)*n+j].from = i;
			a[m+(i-1)*n+j].to = j;
			a[m+(i-1)*n+j].len = x+v;
		}
	}
	sort(a+1,a+m+k*n+1,cmp);
	for(int i = 1;i<=m+k*n;i++){
		int from = fa[a[i].from];
		int to = fa[a[i].to];
		if(take(from)!=take(to)){
			fa[from] = to;
			ans += a[i].len;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}

