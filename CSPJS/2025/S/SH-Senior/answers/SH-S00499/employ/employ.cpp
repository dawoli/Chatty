#include<bits/stdc++.h>
using namespace std;
string s;
const int mod=998244353;
long long n,a[505],b[505],c[505],k,ans,ze;
bool pd=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)ze++;
		b[i]=i;
	}
	for(int i=0;i<n;i++){
		if(s[i]!='1')pd=false;
	}
	if(pd){
		ans=1;
		for(int i=n;i>=1;i--){
			ans=ans*i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	long long noo=0,ini=0;
	for(int i=1;i<=n;i++){
		//cout<<b[i]<<' ';
		c[i]=a[b[i]];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'||c[i+1]<=noo){
			//cout<<c[i];
			noo++;
		}
		else ini++;
	}
	if(ini>=k)ans++;
	while(next_permutation(b+1,b+1+n)){
		long long now=0,inn=0;
		for(int i=1;i<=n;i++){
			//cout<<b[i]<<' ';
			c[i]=a[b[i]];
		}
		for(int i=0;i<n;i++){
			if(s[i]=='0'||c[i+1]<=now){
				//cout<<c[i];
				now++;
			}
			else inn++;
		}
		//cout<<inn<<"\n";
		if(inn>=k)ans++,ans%=mod;
	}
	cout<<ans;
	return 0;
}
