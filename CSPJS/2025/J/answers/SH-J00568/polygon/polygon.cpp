#include<bits/stdc++.h>
using namespace std;
long long n;
const long long p=998244353;
long long a[5010];
int d[5010];
int lst=0;
int ans=0;
long long ksm(long long x){
	long long an=1;
	long long ppp[30];
	int k=0;
	while(x>0){
		ppp[k]=(x&1);
		x=x>>1;
		k++;
	}
	k--;
	while(k>=0){
		an=an*an;
		an%=p;
		if(ppp[k]){
			an*=2;
			an%=p;
		}
		k--;
	}
	return an;
}
void dfs(long long x,int v,int dh){
	if(dh==x && v>=3){
		long long ck=0;
		for(int i=1;i<=v-1;i++){
			ck+=a[d[i]];
		}
		if(ck>a[d[v]]) ans++;
		return;
	}
	else if(dh<x){
		d[v+1]=dh+1;
		dfs(x,v+1,dh+1);
		d[v+1]=0;
		dfs(x,v,dh+1);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);//
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(a[n]==1){
		ans=ksm(n);
		ans+=p-1-n-(n*(n-1))/2;
		ans%=p;
		cout<<ans;
	}
	else{
		dfs(n,0,0);
		cout<<ans;
	}
//	for(int i=1;i<=n;i++){
//		int x=0;
//		for(int j=i;j>lst;j--){
//			x=x^a[j];
//			if(x==k){
//				lst=i;
//				ans++;
//				break;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j>0;j--){
//			if(dp[j-i])
//		}
//	}
	return 0;
}
