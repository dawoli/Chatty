#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
long long ans[500010];
long long get(long long l,long long r){
	long long num=ans[r]^ans[l-1];
	return num;
}
int main( ){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	cin>>a[1];
	ans[1]=a[1];
	for(long long i=2;i<=n;i++)
		cin>>a[i],ans[i]=(ans[i-1]^a[i]);
	long long x=1;
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=x;j<=i;j++){
			if(get(j,i)==k){
				x=i+1;
				ans++;
				break;
			}
		}
		if((i-x)*(i-x)>=n&&n>40000)
			x++;
	}
	cout<<ans;
	return 0;
}
