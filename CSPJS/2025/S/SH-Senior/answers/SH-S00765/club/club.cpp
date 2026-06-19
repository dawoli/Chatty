#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int t,n,a[N],b[N],c[N],limit;
long long mx;
bool A,B,C; 
inline void dfs(int u,int at,int bt,int ct,long long val) {
	if(u==n) {
		mx=max(mx,val);
		return;
	}
	if(at+1<=limit) dfs(u+1,at+1,bt,ct,val+a[u]);
	if(bt+1<=limit) dfs(u+1,at,bt+1,ct,val+b[u]);
	if(ct+1<=limit) dfs(u+1,at,bt,ct+1,val+c[u]);
}inline void dfsnc(int u,int at,int bt,long long val) {
	if(u==n) {
		mx=max(mx,val);
		return;
	}
	if(at+1<=limit) dfsnc(u+1,at+1,bt,val+a[u]);
	if(bt+1<=limit) dfsnc(u+1,at,bt+1,val+b[u]);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		mx=0,limit=n/2;
		for(int i = 0; i<n; i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]!=0) A=1;
			if(b[i]!=0) B=1;
			if(c[i]!=0) C=1;
		}if(!C&&!B){
			sort(a,a+n);
			for(int j=0;j<limit;j++) mx+=a[n-j-1];
		}else if(!C){
			dfsnc(0,0,0,0);
		}else dfs(0,0,0,0,0);
		cout<<mx<<"\n";
	}
	return 0;
}
