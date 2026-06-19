#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+9;
struct node{
	ll m;
}a[N],b[N],c[N];
int t;
int n;
ll ans;
bool vis[N][5];
bool cmp(node a,node b){
	return a.m>b.m;
}
void dfs(int id,ll sum,int A,int B,int C,ll lm){
	if(id==n+1){
		ans=max(ans,sum);
		return ;
	}
	if(sum+lm<ans) return ;
	int maxn=max({a[id].m,b[id].m,c[id].m});
	if(A<n/2){
		dfs(id+1,sum+a[id].m,A+1,B,C,lm-maxn);
	}
	if(B<n/2){
		dfs(id+1,sum+b[id].m,A,B+1,C,lm-maxn);
	}
	if(C<n/2){
		dfs(id+1,sum+c[id].m,A,B,C+1,lm-maxn);
	}
}
void solve(){
	ans=0;
	cin>>n;
	ll lm=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>b[i].m>>c[i].m;
		lm+=max({a[i].m,b[i].m,c[i].m});
	}
	dfs(1,0,0,0,0,lm);
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
