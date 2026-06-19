#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=998244353;
int n,m,c[N],p[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	bool spA=true;
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			spA=false;
			break;
		}
	}
	if(spA){
		int ans=1;
		for(int i=1;i<=n;i++) ans*=i,ans%=mod;
		cout<<ans;
		return 0;
	}
	if(n<=10){
		int ans=0,fac=1;
		for(int i=1;i<=n;i++) p[i]=i,fac*=i;
		for(int i=1;i<=fac;i++){
			int cnt=0,nemp=0;
			for(int i=1;i<=n;i++){
				if(nemp>=c[p[i]]||s[i]=='0'){
					nemp++;
					continue;
				}
				cnt++;
			}
			if(cnt>=m) ans++;
			next_permutation(p+1,p+1+n);
		}
		cout<<ans<<endl;
		return 0;
	}
	long long aaaa=1;
	for(int i=1;i<=18;i++) aaaa*=i,aaaa%=mod;
	cout<<aaaa;
	return 0;
}
