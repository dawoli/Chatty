#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll INF=1e15;
void file(){
	 freopen("color.in","r",stdin);
	 freopen("color.out","w",stdout);
}
const ll N=200009;
const ll R=2000009;
ll T,n,a[N];
ll ok[N];
ll ans=-INF;
//多测不请空，爆零两行泪
void init(){
	rep(i,1,n)a[i]=ok[i]=0;
	n=0;
	ans=-INF; 
}
void input(){
	cin>>n;
	rep(i,1,n)cin>>a[i];
} 
ll pre[R];
void dfs(ll now){
	if(now==n+1){
		ll res=0;
		rep(i,1,n){
			ll mx=-1;
			down(j,i-1,1){
				if(ok[j]==ok[i]){
					mx=j;
					break;
				}
			}
			if(a[i]==a[mx])res+=a[i];
		}
		ans=max(ans,res);
		return;
	}
	ok[now]=1;
	dfs(now+1);
	ok[now]=0;
	dfs(now+1);
}
void solveBF(){
	ans=-INF;
	dfs(1);
	cout<<ans<<endl;
}
int main(){
	file();
	cin>>T;
	rep(i,1,T){
		init();
		input();
		solveBF();
	}
	return 0;
}

