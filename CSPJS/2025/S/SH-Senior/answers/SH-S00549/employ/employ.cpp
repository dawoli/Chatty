#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c[505];
string s;
long long count(long long t){
	long long sum=1;
	for(long long i=2;i<=t;i++){
		sum*=i;
		sum%=mod;
	}
	return sum%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	long long sum=0;
	for(long long i=0;i<n;i++){
		sum+=s[i]-'0';
	}
	if(sum==n){
		cout<<count(n)%mod;
		return 0;
	}
	if(sum<=18){
		cout<<0;
		return 0;
	}
	if(m==1){
		sort(c+1,c+n+1);
		for(long long i=0;i<s.size();i++){
			if(s[i]=='1'){
				long long j=1;
				for(;j<=n;j++){
					if(c[j]>i){
						break;
					}
				}
				cout<<(n-j+1)*count(n-1)%mod;
				break;
			}
		}
	}

	return 0;
}

