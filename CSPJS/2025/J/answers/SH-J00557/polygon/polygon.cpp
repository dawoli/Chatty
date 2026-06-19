#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0;
const long long mod=998244353;
void dfs(long long num,long long maxx,long long sum,long long l){
	if(l==n+1){
		if(sum>2*maxx&&num>=3){
			ans++;
			return;
		}else return;
	}
	if(n-l+1+num<3) return;
	else if(n-l+1+num==3) dfs(num+1,max(maxx,a[l]),sum+a[l],l+1);
	else{
		dfs(num+1,max(maxx,a[l]),sum+a[l],l+1);
		dfs(num,maxx,sum,l+1);		
	}
	return;
}
long long ppow(long long x,long long k){
	long long sum=1;
	while(k--){
		sum*=x;
		sum%=mod;
	}
	return sum%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	int sss=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sss+=a[i];
	}
	if(sss==n){
		long long h=ppow(2,n);
		h-=n+n*(n-1)/2+1;
		while(h<0) h+=mod;
		cout<<h<<endl;
		return 0;
	}
	dfs(0,0,0,1);
	cout<<ans<<endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}

