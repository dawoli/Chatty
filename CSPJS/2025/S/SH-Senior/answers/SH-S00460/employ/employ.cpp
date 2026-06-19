#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int m,n,s[509],b[509],cnt;
long long ans;
char c[509];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(c+1);
	for(int i=1;i<=n;i++){
		int a=c[i]-'0';
		if(a==0)s[i]=s[i-1]+1;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(b[i]==0)cnt++;
	}
	sort(b+1,b+1+n);
	if(m==1){
		if(b[n]>s[1]){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}else cout<<0;
	}else if(s[n]==0){
		if(n-cnt>=m){
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}else cout<<0;
	}else cout<<0;
	return 0;
}
