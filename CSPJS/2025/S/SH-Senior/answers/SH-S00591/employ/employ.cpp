#include<iostream>
#include<cstring>
using namespace std;
const int mod=998224353;
int n,m,s[505],a[505],cnt=0;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=(c=='1'?1:0);
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==0) cnt++;
	}
	if(n-cnt<m){
		cout<<"0\n";
		return 0;
	}
	for(int i=1;i<=n-cnt;i++){
		ans=(ans*i)%mod;
	}
	for(int i=1;i<=cnt;i++){
		ans=(ans*i)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
