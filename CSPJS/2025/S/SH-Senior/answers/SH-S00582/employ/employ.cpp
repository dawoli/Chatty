#include<bits/stdc++.h>
using namespace std;
#define N 510
bool a[N];
int sum[N],c[N],x=0;
long long d[N]={1};
long long mod=998244353,ans=1;
bool vis[N];
int n,m;
int ne=0;
void go(int all,int sum){
	if(sum>=m){
		ans=(ans+d[n-all])%mod;
		return;
	} if(n-all+sum<m) return;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(c[i]>ne&&a[all+1]){
			vis[i]=1;
			go(all+1,sum+1);
			vis[i]=0;
		}
		else{
			ne++;
			vis[i]=1;
			go(all+1,sum);
			vis[i]=0;
			ne--;
		}
	}	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//ios::sync_with_stdio(0);
	 cin>>n>>m;
	for(int i=1;i<=n;i++){
		char abc; cin>>abc;
		a[i]=abc-'0';
		if(!a[i]) x++;
	}for(int i=1;i<=n;i++){
		cin>>c[i];
		sum[c[i]]++;
	} for(int i=1;i<=n;i++){
			d[i]=d[i-1]*i%mod;
	}
	 if(n-sum[0]-x<m){
		cout<<0;
		exit(0);
	} if(n<=18){
		ans=0;
		go(0,0);
		cout<<ans;
		return 0;
	}
	if(x==0){
		if(sum[0]==0){
			for(int i=1;i<=n;i++){
				ans=ans*i%mod;
			} cout<<ans; 
			return 0;
		}
	} if(m==1){
		long long x=n,y=1; ans=0;
		int z=0;
		for(int i=1;i<=n;i++){
			x-=sum[i-1];
			if(a[i]){
				ans=(ans+y*x%mod*d[n-i+z]%mod)%mod;
				y=y*(n-x-i+z+1)%mod;
			} else z++;
		} cout<<ans; 
			return 0;
	} cout<<d[n];
}

