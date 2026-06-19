#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ct1,p[15];
long long ans;
string s;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ct1+=s[i]-'0';
	}
	if(m>ct1){
		cout<<0<<endl;return 0;
	}
	if(n<=10){
		for(int i=1;i<=n;i++)p[i]=i;
		do{
			int fail=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'||fail>=c[p[i]])fail++;
			}
			if(n-fail>=m)ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans<<endl;
		return 0;
	}
	sort(c+1,c+n+1);
	long long f=1;
	if(m==1){
		int ct=0;
		ans=1;
		for(int i=1;i<=n;i++){
			f=f*i%mod;
			if(s[i]=='1'){
				int num=lower_bound(c+1,c+n+1,i)-c-1-ct;
				ans=ans*num%mod;
				ct++;
			}
			if(i==n-ct1)ans=ans*f%mod;
		}
		cout<<(f-ans+mod)%mod<<endl;
		return 0;
	}
	if(m==n){
		if(c[1]==0)cout<<0<<endl;
		else cout<<f<<endl;
		return 0;
	}
	cout<<0;
	return 0;
}
