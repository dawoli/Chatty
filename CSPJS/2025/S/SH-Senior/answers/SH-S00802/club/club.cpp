#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9;
const int N=1e5+9;
int t;
int n;
int a[N][4];
int ans=0;
int size[4];
void check(int cnt){
	for(int i=1;i<=3;i++){
		if(size[i]>n/2){
			return ;
		}
	}
	ans=max(ans,cnt);
	return ;
}
void dfs(int depth,int x,int cnt){
	if(depth>n){
		check(cnt);
		return ;
	}
	cnt+=a[depth][x];
	for(int i=1;i<=3;i++){
		size[i]+=1;
		dfs(depth+1,i,cnt);
		size[i]-=1;
	}
}
void solveA(){
	int q[N];
	for(int i=1;i<=n;i++){
		q[i]=a[i][1];
	}
	sort(q+1,q+1+n);
	int ans=0;
	for(int i=n;i>n/2;i--){
		ans+=q[i];
	}
	cout<<ans<<endl;
}
void solve(){
	cin>>n;
	bool is_A=true; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][2]!=0||a[i][3]!=0){
			is_A=false;
		}
	}
	if(is_A){
		solveA();
		return ;
	}
	for(int i=1;i<=3;i++){
		size[i]+=1;
		dfs(1,i,0);
		size[i]-=1;
	}
	cout<<ans<<endl;
	ans=0;
	fill(size+1,size+5,0);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		solve();
	}
	return 0;
}
