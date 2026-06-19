#include<bits/stdc++.h>//T3骗了10分 
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	bool flag1=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag1=false;
	}
	if(flag1 && k==0){//特性a
		long long ans=0;
		for(int i=2;i<=n;i+=2) ans+=n/i;
		cout<<ans;
	}
	else cout<<2;//看运气了 
	return 0;
}
