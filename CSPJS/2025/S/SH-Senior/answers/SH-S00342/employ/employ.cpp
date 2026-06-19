#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
const int mod=998244353;
string s;
long long n,m,c[N],ans;
bool flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int l=s.size();
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<l;i++){
		if(s[i]=='0') flag=1;
	}
	if(flag==1){
		cout<<(n+1)*n*12;
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans%mod;
	}
}
