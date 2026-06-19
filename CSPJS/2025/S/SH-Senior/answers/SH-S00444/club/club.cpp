#include<bits/stdc++.h>
using namespace std;
int t,n,p,maxn; 
int a[100010];
int b[100010]; 
int c[100010];
inline bool cmp(int a,int b){
	return a>b;
}
inline void dfs(int idx,int sum,int c1,int c2,int c3){
	if (idx==n+1) {
		maxn=max(maxn,sum);
		return ;
	}
	if(c1<p) {
		dfs(idx+1,sum+a[idx],c1+1,c2,c3);
	} if(c2<p) {
		dfs(idx+1,sum+b[idx],c1,c2+1,c3);
	} if (c3<p) {
		dfs(idx+1,sum+c[idx],c1,c2,c3+1);
	}
	return ;
}
inline void dfs1(int idx,int sum,int c1,int c2){
	if (idx==n+1) {
		maxn=max(maxn,sum);
		return ;
	}
	if(c1<p) {
		dfs1(idx+1,sum+a[idx],c1+1,c2);
	} if(c2<p) {
		dfs1(idx+1,sum+b[idx],c1,c2+1);
}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		bool f1=true;
		bool f2=true;
		maxn=0;
		cin>>n;
		p=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(c[i]!=0) f1=f2=false;
			else if(b[i]!=0) f1=false;
		}
		if(f1){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i*2<=n;i++){
				maxn+=a[i];
			}
		} else if(f2){
			dfs1(1,0,0,0);
		} else{
			dfs(1,0,0,0,0);
		}
		cout<<maxn<<"\n";
	}
	return 0;
}
