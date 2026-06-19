#include<bits/stdc++.h>
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define el <<"\n"
#define fi first
#define sc second
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,m;
string s;
int A[505];
int C[505];
int B[20];
bool P[20];
ll ans=0;
void dfs1(int i){
	if(i==n+1){
		int x=0,cnt=0;
		rep(i,1,n){
			if(s[i-1]=='1'&&x<A[B[i]]){
				cnt++;
			}else{
				x++;
			}
		}
		if(cnt>=m){
			ans++;
		}
		return;
	}
	rep(j,1,n){
		if(P[j]){
			continue;
		}
		P[j]=true;
		B[i]=j;
		dfs1(i+1);
		P[j]=false;
	}
}
void solve1(){
	dfs1(1);
	cout<<ans%mod;
}
ll f[505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	bool f=true;
	rep(i,1,n){
		cin>>A[i];
		if(A[i]==0){
			f=false;
		}
	}
	if(n==m){
		for(char c:s){
			if(c=='0'){
				f=false;
			}
		}
		if(f){
			ll ans=1;
			rep(i,1,n){
				ans*=i;
				ans%=mod;
			}
			cout<<ans;
		}else{
			cout<<0;
		}
		return 0;
	}else if(m==1){
	}
//	int cnt=0;
//	rep(i,0,s.size()-1){
//		if(s[i]=='1'){
//			cnt++;
//		}
//	}
	if(n<=18)solve1();
}
