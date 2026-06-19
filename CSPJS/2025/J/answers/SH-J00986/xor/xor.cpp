#include<bits/stdc++.h>
using namespace std;

const long long N=5e5+5;
long long n,k;
long long a[N];
long long sum[N];
long long mp[N];
long long lst[N];
long long ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(mp,-1,sizeof mp);
	memset(lst,-1,sizeof lst);
	mp[0]=0;
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
		if(mp[sum[i]^k]==-1){
			mp[sum[i]]=i;
		}
		else{
			lst[i]=mp[sum[i]^k];
			mp[sum[i]]=i;
		}
	}
	long long l=0;
	for(long long i=1;i<=n;i++){
		if(lst[i]!=-1 and lst[i]>=l){
			ans++;
			l=i;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
