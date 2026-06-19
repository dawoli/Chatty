#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int a[5050];
int v[50];
ll ans=0;
int dfs(int sum,int maxx,int qidian){
	if(qidian<=n&&count(v+1,v+50,1)>=3&&sum>maxx*2) ans++;
	if(qidian==n) return ans;
	for(int i=1;i<=n;i++){
		if(!v[a[i]]){
			v[a[i]]=1;
			ans+=dfs(sum+a[i],max(maxx,a[i]),i+1);
			v[a[i]]=0;
		}
	}
	return ans;
}
void solve1(){
	cout<<dfs(0,0,1);
}

int xz(int a,int b){
	if(a==b) return 1;
	ll ans=1;
	for(int i=b+1;i<=a;i++){
		ans*=i;
	}
	for(int i=2;i<=a-b;i++){
		ans/=i;
	}
	return ans%998244353;
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	int maxa=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	
	if(n==3){
		if(a[1]+a[2]+a[3]>2*maxa) cout<<1;
		else cout<<0;
	}
	
	
	else if(maxa==1){
		ll ans=0;
		for(int i=3;i<=n;i++){
			ans+=xz(n,i);
			ans%=998244353;
		}
		cout<<ans;
	}
	else if(n<=20){
		solve1();
	}
	
}
