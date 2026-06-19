#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2*1e6+9;
int n,t;ll ans;
int a[N],cnnt[N];
bool c[N],ok[N];//0È¾ÎªºìÉ« 1ÎªÀ¶ 
int f[N];
bool cc[N];
void cal(){
	ll res=0;
	int cntr=0,cntb=0,lr=0,lb=0;
	
	for(int i=1;i<=n;i++){
//		cout<<lr<<" "<<lb<<endl;
		if(c[i]==0){
				if(lr!=0&&a[i]==a[lr])res+=a[i];lr=i;
		}
		else {
			if(lb!=0&&a[i]==a[lb])res+=a[i];lb=i;
		}
	}
//	if(res){
//		for(int i=1;i<=n;i++)cout<<c[i]<<" ";
//	cout<<endl;
//	cout<<res<<endl;
//	}
	ans=max(ans,res);
}
void dfs1(int x){
	if(x==n+1){
		cal();
		return ;
	}
	c[x+1]=1;
	dfs1(x+1);
	c[x+1]=0;
	dfs1(x+1);
}
void calnum(){
//	for(int i=1;i<=10;i++)cout<<cc[i]<<" ";
	ll res=0;
	int cntr=0,cntb=0,lr=0,lb=0;
	for(int i=1;i<=n;i++){
		if(cc[a[i]]==0){//hse
			if(lr!=0&&a[i]==a[lr])res+=a[i];lr=i;
		}else {
			if(lb!=0&&a[i]==a[lb])res+=a[i];lb=i;
		}
	}
	ans=max(ans,res);
}
void dfs(int x){
	if(x==11){
		calnum();
		return;
	}
	cc[x+1]==1;
	dfs(x+1);
	cc[x+1]==0;
	dfs(x+1);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=15){
			fill(c+1,c+1+n,0);
			ans=0; 
			dfs1(0);
			cout<<ans<<endl; 
		}
		else {
			fill(cc+1,cc+1+n,0);
			ans=0; 
			dfs(0);
			cout<<ans<<endl;
		}
}
	return 0;
}

