#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ok[505]={0},pa[505];
long long pai[505];
int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		char a;
		cin>>a;
		ok[i]=(long long)(a-'0');
		pai[i]=i;
	}
	for(long long i=1;i<=n;i++){
		cin>>pa[i];
	}
	long long ans=0;
	do{
		long long cnt=0;
		for(long long i=1;i<=n;i++){
//			cout<<pai[i]<<" ";
			if(pa[pai[i]]<=cnt||!ok[i])cnt++;
//			cout<<pa[pai[i]]<<" "<<ok[i]<<" "<<cnt<<"\n";
		}
		if(n-cnt>=m)ans++;
		ans%=998244353;
//		cout<<"\n";
	}while(next_permutation(pai+1,pai+n+1));
	cout<<ans;
}
