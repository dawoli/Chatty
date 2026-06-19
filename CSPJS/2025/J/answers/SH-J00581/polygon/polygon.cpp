#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[6003];
ll ss[6000];
int maxn=0;
const int mod=998244353;
int endd;
ll ans;
ll C(int n,int m){
	ll tmp;
	tmp=ss[n]*ss[m-n];
	tmp%=mod;
	tmp=ss[m]/tmp;
	tmp%=mod;
	return tmp;
}
bool dfs(int sum,int last){
	if (last==endd) return 0;
	for (int i=last+1;i<=endd;i++){
		dfs(sum+a[i],i);
		if (sum>a[i]) ans++;
		ans%=mod;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	ss[1]=1;
	ss[0]=1;
	for (int i=2;i<=n;i++){
		ss[i]=ss[i-1]*i;
		ss[i]%=mod;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxn=max(a[i],maxn);
	}
	if (n<=2){
		cout<<0;
		return 0;
	}
	if (n==3){
		int sum=a[1]+a[2]+a[3];
		if (sum>2*maxn){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if (maxn==1){
		for (int i=3;i<=n;i++){
			
			ans+=C(i,n);
			ans%=mod;
		}
	}
	
	else {
		endd=n;
		sort(a+1,a+n+1);
		for (int i=1;i<=n-2;i++){
			for (int j=i+1;j<=n-1;j++){
				dfs(a[i]+a[j],j);
			}
		}
	}
	cout<<ans;
}
