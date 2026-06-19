#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
const int N=505;
int n,m,cnt;
char s[N];
int c[N];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
	}
	bool flag=true;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(c[i]==0){
			flag=false;
			cnt++;
		}	
	}
	if(flag==true){
		for(int i=1;i<=n;++i){
			ans=ans*i%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
