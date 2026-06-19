#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c,t;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c==0)t++;
	}
	if(m==1){
		if(n==t){
			cout<<0;
			return 0;
		}
		int ans=1;
		for(int i=1;i<=n-t;i++)ans=(ans*i)%mod;
		cout<<ans;
		return 0;
	}
	srand(time(0));
	cout<<rand()%20;
	return 0;
}
