#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int q[555];
void solve(){
	int n,m;
	cin>>n>>m;
	string x;
	cin>>x;
	int p;
	long long ans=1;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>q[i];
	}
	for(int i=0;i<n;i++){
		if(q[i]==0)cnt++;
	}
	if(cnt>n-m){
		cout<<0;
		return ;
	}
	else{
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
			//if(ans==161088479)cout<<"\n\n\n\n\n\n";
		}
		cout<<ans<<'\n';
		
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
	return 0;
}
 
